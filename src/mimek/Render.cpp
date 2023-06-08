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
  SDL_Point points[5];

  set_rendercolor_mim(engine_renderer, button.main_color);
  SDL_RenderFillRect(engine_renderer, &button.rect);

  // Changing here @TODO - rendering full default_button from assets using code
  set_rendercolor_mim(engine_renderer, button.outline);

  // Get points out of a rectangle
  utils_mim_get_points_from_rect(points, button.rect);
  SDL_RenderDrawLines(engine_renderer, points, 5);

  // Get points to inner lines
  SDL_Point inner_points[5];
  utils_mim_

}
