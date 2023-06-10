#include "Render.hpp"
#include "UIelements.hpp"
#include "Utils.hpp"

#include <stdio.h>

void set_rendercolor_mim(SDL_Renderer*& engine_renderer, const SDL_Color& color) {
  SDL_SetRenderDrawColor(engine_renderer, color.r, color.g, color.b, color.a);
}

void mim_render(SDL_Renderer*& engine_renderer) {
  // TEST render
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
}

void mim_render_filled_polygon(SDL_Renderer*& engine_renderer, Point2D_Vec points_vec) {
  int x_min, x_max, y_min, y_max;
  utils_mim_yminmax_xminmax_from_points2d_vec(points_vec, y_min, y_max, x_min, x_max);

#if 0
  printf("Y min: %d\n", y_min);
  printf("Y max: %d\n", y_max);
  printf("X min: %d\n", x_min);
  printf("X max: %d\n", x_max);
#endif

  // @TODO big task: Implement scanline fill algorithm

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

  utils_mim_get_points_from_rect(outer_points, button.rect);
  utils_mim_get_points_to_inner_button(outer_points, inner_points);

  set_rendercolor_mim(engine_renderer, button.main_color);
  SDL_RenderFillRect(engine_renderer, &button.rect);

  // Pushing points to create a vector for lighter area
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(outer_points[0]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(inner_points[0]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(inner_points[3]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(inner_points[2]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(outer_points[2]));
  lighter_area_vec.push_back(utils_mim_sdl_point_to_point_2d(outer_points[3]));

  // Rendering filled polygon with lighter color
  set_rendercolor_mim(engine_renderer, button.light_color);
  mim_render_filled_polygon(engine_renderer, lighter_area_vec);

  // Changing here @TODO - rendering full default_button from assets using code
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
