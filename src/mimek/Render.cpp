#include "Render.hpp"
#include "UIelements.hpp"
#include "Utils.hpp"

#include <stdio.h>

void set_rendercolor_mim(SDL_Renderer*& engine_renderer, const SDL_Color& color) {
  SDL_SetRenderDrawColor(engine_renderer, color.r, color.g, color.b, color.a);
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

  set_rendercolor_mim(engine_renderer, button.main_color);
  SDL_RenderFillRect(engine_renderer, &button.rect);

  // Changing here @TODO - rendering full default_button from assets using code
  set_rendercolor_mim(engine_renderer, button.outline);

  // Get points out of a rectangle
  utils_mim_get_points_from_rect(outer_points, button.rect);
  SDL_RenderDrawLines(engine_renderer, outer_points, 5);

  // Get points to inner lines
  SDL_Point inner_points[5];

  // Drawing inner lines
  utils_mim_get_points_to_inner_button(outer_points, inner_points);
  set_rendercolor_mim(engine_renderer, button.innerlines);
  SDL_RenderDrawLines(engine_renderer, inner_points, 5);

  // Draw topleft/topright/bottomleft/bottomright lines
  SDL_RenderDrawLine(engine_renderer, outer_points[0].x, outer_points[0].y, inner_points[0].x, inner_points[0].y);
  SDL_RenderDrawLine(engine_renderer, outer_points[1].x, outer_points[1].y, inner_points[1].x, inner_points[1].y);
  SDL_RenderDrawLine(engine_renderer, outer_points[2].x, outer_points[2].y, inner_points[2].x, inner_points[2].y);
  SDL_RenderDrawLine(engine_renderer, outer_points[3].x, outer_points[3].y, inner_points[3].x, inner_points[3].y);

}
