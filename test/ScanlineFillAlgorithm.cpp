#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <iostream>
#include <vector>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Point structure
struct Point {
    int x;
    int y;
};

// Function to draw a filled polygon using scanline algorithm
void drawFilledPolygon(SDL_Renderer* renderer, const std::vector<Point>& points) {
    // Find the minimum and maximum y-coordinates of the polygon
    int minY = SCREEN_HEIGHT;
    int maxY = 0;
    for (const Point& point : points) {
        if (point.y < minY) {
            minY = point.y;
        }
        if (point.y > maxY) {
            maxY = point.y;
        }
    }

    // Create a vector to store the intersection points
    std::vector<int> intersectionPoints(SCREEN_WIDTH);

    // Iterate over each scanline
    for (int scanlineY = minY; scanlineY <= maxY; scanlineY++) {
        int intersectionCount = 0;

        // Find the intersection points on each scanline
        for (size_t i = 0; i < points.size(); i++) {
            const Point& currentPoint = points[i];
            const Point& nextPoint = points[(i + 1) % points.size()];

            if ((currentPoint.y <= scanlineY && nextPoint.y > scanlineY) ||
                (currentPoint.y > scanlineY && nextPoint.y <= scanlineY)) {
                float t = static_cast<float>(scanlineY - currentPoint.y) / (nextPoint.y - currentPoint.y);
                int intersectX = static_cast<int>(currentPoint.x + t * (nextPoint.x - currentPoint.x));
                intersectionPoints[intersectionCount++] = intersectX;
            }
        }

        // Sort the intersection points in ascending order
        for (int i = 0; i < intersectionCount - 1; i++) {
            for (int j = 0; j < intersectionCount - i - 1; j++) {
                if (intersectionPoints[j] > intersectionPoints[j + 1]) {
                    int temp = intersectionPoints[j];
                    intersectionPoints[j] = intersectionPoints[j + 1];
                    intersectionPoints[j + 1] = temp;
                }
            }
        }

        // Draw the horizontal line segment for the current scanline
        for (int i = 0; i < intersectionCount; i += 2) {
            int startX = intersectionPoints[i];
            int endX = intersectionPoints[i + 1];

            SDL_RenderDrawLine(renderer, startX, scanlineY, endX, scanlineY);
        }
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Scanline Fill Algorithm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
          if (event.type == SDL_QUIT) {
              quit = true;
          }

          if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
              quit = true;
            }
          }

        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Define the vertices of the polygon
        std::vector<Point> points = {{100, 100}, {400, 400}, {300, 100}, {200, 300}};

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        drawFilledPolygon(renderer, points);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
