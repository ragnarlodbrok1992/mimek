#include "mimek.hpp"

int init_mim(SDL_Window* engine_window, SDL_Renderer* engine_renderer) {
  printf("Initialization.\n");

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL initialization failed: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window
  engine_window = SDL_CreateWindow(
      TITLE_BAR,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, 
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      SDL_WINDOW_SHOWN);
  if (engine_window == nullptr) {
    printf("Failed to create SDL window: %s\n", SDL_GetError());
    return 1;
  }

  // Create a renderer
  engine_renderer = SDL_CreateRenderer(
      engine_window,
      -1,
      SDL_RENDERER_ACCELERATED);
  if (engine_renderer == nullptr) {
    printf("Failed to create SDL renderer: %s\n", SDL_GetError());
    return 1;
  }

  return 0;
}

void run_mim(SDL_Renderer* engine_renderer, bool& running) {
  printf("Running.\n");
  printf("Engine running var: %s\n", running ? "true" : "false");

  SDL_Event event;

  while(running) {
    // Handling events
    while (SDL_PollEvent(&event)) {
      // Quiting event
      if (event.type == SDL_QUIT) {
        running = false;
      }
      
      // Keybaord presses
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          running = false;
        }
      }
    }

    // Clearning the screen
    SDL_SetRenderDrawColor(engine_renderer, 0, 0, 0, 255);
    SDL_RenderClear(engine_renderer);

    // Update the screen
    SDL_RenderPresent(engine_renderer);
  }
}

void clean_mim(SDL_Window* engine_window, SDL_Renderer* engine_renderer) {
  printf("Cleaning.\n");

  SDL_DestroyRenderer(engine_renderer);
  SDL_DestroyWindow(engine_window);
  SDL_Quit();

}

