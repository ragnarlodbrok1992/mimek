#include "Render.hpp"
#include "UIelements.hpp"
#include "Utils.hpp"
#include "const.hpp"
#include "macros.hpp"

#include <stdio.h>
#include <algorithm>

void set_rendercolor_mim(SDL_Renderer*& engine_renderer, const SDL_Color& color) {
  SDL_SetRenderDrawColor(engine_renderer, color.r, color.g, color.b, color.a);
}

void mim_render(SDL_Renderer*& engine_renderer) {
  // TEST render
#if 0
  SDL_Color test_color = YELLOW;
  SDL_Color darker_color;
  SDL_Color lighter_color;

  SDL_Rect test_rect = {400, 100, 200, 100};
  SDL_Rect darker_rect = {400, 220, 200, 100};
  SDL_Rect lighter_rect = {400, 340, 200, 100};

  color_mim_change_lightness(test_color, darker_color, 0.3f);
  color_mim_change_lightness(test_color, lighter_color, 0.7f);

  set_rendercolor_mim(engine_renderer, test_color);
  SDL_RenderFillRect(engine_renderer, &test_rect);

  set_rendercolor_mim(engine_renderer, darker_color);
  SDL_RenderFillRect(engine_renderer, &darker_rect);

  set_rendercolor_mim(engine_renderer, lighter_color);
  SDL_RenderFillRect(engine_renderer, &lighter_rect);
#endif
}

void mim_render_filled_polygon(SDL_Renderer*& engine_renderer, Point2D_Vec& points_vec) {
  int x_min, x_max, y_min, y_max;
  utils_mim_yminmax_xminmax_from_points2d_vec(points_vec, y_min, y_max, x_min, x_max);

#if 0
  printf("Y min: %d\n", y_min);
  printf("Y max: %d\n", y_max);
  printf("X min: %d\n", x_min);
  printf("X max: %d\n", x_max);
#endif

  std::vector<int> intersection_points(SCREEN_WIDTH);

  for (int scanline_y = y_min; scanline_y <= y_max; scanline_y++) {
    int intersection_count = 0;

    // Finding intersection points on each scanline
    for (size_t i = 0; i < points_vec.size(); i++) {
      const Point2D& current_point = points_vec[i];
      const Point2D& next_point = points_vec[(i + 1) % points_vec.size()];

      if ((current_point.y <= scanline_y && next_point.y > scanline_y) || (current_point.y > scanline_y && next_point.y <= scanline_y)) {
        float t = (float)(scanline_y - current_point.y) / (next_point.y - current_point.y);
        int intersect_x = (int)(current_point.x + t * (next_point.x - current_point.x));
        intersection_points[intersection_count++] = intersect_x;
      }
    }

    // Sorting points in ascending order
    std::sort(intersection_points.begin(), intersection_points.begin() + intersection_count);

    // Drawing lines
    for (size_t i = 0; i < intersection_count; i += 2) {
      int start_x = intersection_points[i];
      int end_x   = intersection_points[i + 1];

      SDL_RenderDrawLine(engine_renderer, start_x, scanline_y, end_x, scanline_y);
    }
  }
}

void render_ui_buttons(SDL_Renderer*& engine_renderer, Button_Vec& bv) {
  // Render function for UI elements - buttons
  for (auto b : bv) {
    render_button(engine_renderer, b);   
  }
}

// UI Element: Button
void render_button(SDL_Renderer*& engine_renderer, Button& button) {
  SDL_Point outer_points[5];
  SDL_Point inner_points[5];
  Point2D_Vec lighter_area_vec;

  // @TODO: change colors based on STATUS

  SDL_Color render_color;
  SDL_Color render_light_color;

  switch (button.status) {
    case STATUS::UN_FOCUSED: 
      render_color       = button.main_color;
      render_light_color = button.light_color;
      break;

    case STATUS::FOCUSED:
      render_color       = button.focused_main_color;
      render_light_color = button.focused_light_color;
      break;

    case STATUS::CLICKED:
      render_color       = button.clicked_main_color;
      render_light_color = button.clicked_light_color;
      break;

    default:
      BAD_RUNTIME_EXECUTION_PATH();
      break;
  }

  utils_mim_get_points_from_rect(outer_points, button.rect);
  utils_mim_get_points_to_inner_button(outer_points, inner_points);

  set_rendercolor_mim(engine_renderer, render_color);
  SDL_RenderFillRect(engine_renderer, &button.rect);

  // Pushing points to create a vector for lighter area
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(outer_points[0]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(inner_points[0]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(inner_points[3]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(inner_points[2]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(outer_points[2]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(outer_points[3]));

  // Rendering filled polygon with lighter color
  set_rendercolor_mim(engine_renderer, render_light_color);
  mim_render_filled_polygon(engine_renderer, lighter_area_vec);

  set_rendercolor_mim(engine_renderer, button.outline);

  // Get points out of a rectangle
  SDL_RenderDrawLines(engine_renderer, outer_points, 5);

  // Drawing inner lines
  set_rendercolor_mim(engine_renderer, button.innerlines);
  SDL_RenderDrawLines(engine_renderer, inner_points, 5);

  // Draw topleft/topright/bottomleft/bottomright lines
  SDL_RenderDrawLine(engine_renderer, outer_points[0].x, outer_points[0].y, inner_points[0].x, inner_points[0].y);
  SDL_RenderDrawLine(engine_renderer, outer_points[1].x, outer_points[1].y, inner_points[1].x, inner_points[1].y);
  SDL_RenderDrawLine(engine_renderer, outer_points[2].x, outer_points[2].y, inner_points[2].x, inner_points[2].y);
  SDL_RenderDrawLine(engine_renderer, outer_points[3].x, outer_points[3].y, inner_points[3].x, inner_points[3].y);

}


void render_layout(SDL_Renderer*& engine_renderer, Layout*& layout) {
  // Render background
  set_rendercolor_mim(engine_renderer, layout->background_color);
  SDL_RenderFillRect(engine_renderer,  &layout->background);

  // Render forground top bar
  SDL_Color foreground_color;
  color_mim_change_lightness(layout->background_color, foreground_color, 0.9f);

  set_rendercolor_mim(engine_renderer, foreground_color);
  SDL_RenderFillRect(engine_renderer,  &layout->top_bar);
}

