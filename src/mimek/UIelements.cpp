#include "UIelements.hpp"

#include "Types.hpp"

Button create_button_mim(SDL_Rect rect, SDL_Color color) {
  Button temp_button;
  temp_button.rect = rect;
  temp_button.color = color;
  temp_button.status = STATUS::UnFocused;

  return temp_button;
}

void button_set_color(Button& button, SDL_Color color) {
  printf("Setting button color!\n");
  button.color = color;
}

void inline render_button_mim(SDL_Renderer* engine_renderer, Button& bt) {
  set_rendercolor_mim(engine_renderer, bt.color);
}

void init_ui_elements_buttons_mim(Button_Vec& bv) {
  // Some debug initializations

  SDL_Rect temp = {100, 100, 200, 100};
  SDL_Color temp_color = {255, 0, 0, 255};
  bv.push_back(create_button_mim(temp, temp_color));

  temp = {100, 220, 200, 100};
  temp_color = {255, 127, 0, 255};
  bv.push_back(create_button_mim(temp, temp_color));
}

Button* select_button(Button_Vec& bv, int x, int y) {
  for (auto b : bv) {
    printf("b is: 0x%p\n", &b);

    if (((x > b.rect.x) && (x < b.rect.x + b.rect.w)) &&
        ((y > b.rect.y) && (y < b.rect.y + b.rect.h))) {
      printf("FOUND MADAFAKIN BUTTON!\n");
      return &b;
    }
  }
  return NULL;
}

