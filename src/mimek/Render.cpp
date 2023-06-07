#include "Render.hpp"
#include "UIelements.hpp"

#include <stdio.h>

void set_rendercolor_mim(SDL_Renderer*& engine_renderer, SDL_Color& color) {
  SDL_SetRenderDrawColor(engine_renderer, color.r, color.g, color.b, color.a);
}

void render(SDL_Renderer*& engine_renderer) {
  // Render function
  // General and test purposes
  //
  // @26-05-23 Working on button

  // SDL_Color RED = {255, 0, 0, 255};
  Button button = create_button_mim({100, 100, 200, 100}, {255, 0, 0, 255});
  
  set_rendercolor_mim(engine_renderer, button.main_color);
  SDL_RenderFillRect(engine_renderer, &button.rect);
  
}

void render_ui_buttons(SDL_Renderer*& engine_renderer, Button_Vec& bv) {
  // Render function for UI elements - buttons
  for (auto b : bv) {
    render_button(engine_renderer, b);   
  }
}

// UI Element: Button
void render_button(SDL_Renderer*& engine_renderer, Button& button) {
  set_rendercolor_mim(engine_renderer, button.main_color);
  SDL_RenderFillRect(engine_renderer, &button.rect);

  // Changing here @TODO - rendering full default_button from assets using code
  set_rendercolor_mim(engine_renderer, WHITE);
  // Getting points out of SDL_Rect
}
