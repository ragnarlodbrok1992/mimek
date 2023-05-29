#include "Render.hpp"

void set_rendercolor_mim(SDL_Renderer*& engine_renderer, SDL_Color& color) {
  SDL_SetRenderDrawColor(engine_renderer, color.r, color.g, color.b, color.a);
}

void render(SDL_Renderer*& engine_renderer) {
  // Render function
  // General and test purposes
  //
  // @26-05-23 Working on button

  // SDL_Color RED = {255, 0, 0, 255};
  // Button button = create_button_mim({100, 100, 200, 100});
  
  // setrendercolor_mim(engine_renderer, RED);
  // SDL_RenderFillRect(engine_renderer, &button.rect);
  
}

void render_ui_buttons(SDL_Renderer*& engine_renderer, Button_Vec& bv) {
  // Render function for UI elements - buttons
}
