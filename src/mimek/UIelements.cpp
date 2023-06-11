#include "UIelements.hpp"

#include "Types.hpp"
#include "Color.hpp"
#include "Utils.hpp"
#include "macros.hpp"

#include <stdio.h>

size_t BUTTON_ID = 0;

Button create_button_mim(SDL_Rect rect, SDL_Color color) {
  Button temp_button;

  temp_button.id = BUTTON_ID;
  BUTTON_ID++;

  temp_button.rect = rect;
  temp_button.main_color = color;
  color_mim_change_lightness(temp_button.main_color, temp_button.light_color, 0.6f);

  color_mim_change_lightness(temp_button.main_color, temp_button.focused_main_color, 0.8f);
  color_mim_change_lightness(temp_button.main_color, temp_button.focused_light_color, 0.9f);

  color_mim_change_lightness(temp_button.main_color, temp_button.clicked_main_color, 0.2f);
  color_mim_change_lightness(temp_button.main_color, temp_button.clicked_light_color, 0.4f);

  temp_button.status = STATUS::UN_FOCUSED;

  return temp_button;
}

void button_set_color(Button& button, SDL_Color color) {
  button.main_color = color;
}

void button_click(Button& button) {
  switch (button.status) {
    case STATUS::FOCUSED:
      button.status = STATUS::CLICKED;
      break;
    case STATUS::CLICKED:
      button.status = STATUS::FOCUSED;
      break;
    default:
      break;
  }
}

void init_ui_elements_buttons_mim(Button_Vec& bv) {
  // Some debug initializations

  SDL_Rect temp = {100, 100, 200, 100};
  bv.push_back(create_button_mim(temp, RED));

  temp = {100, 220, 200, 100};
  bv.push_back(create_button_mim(temp, GREEN));
}

Button* select_button(Button_Vec& bv, int x, int y) {
  for (auto& b : bv) {
    if (((x > b.rect.x) && (x < b.rect.x + b.rect.w)) &&
        ((y > b.rect.y) && (y < b.rect.y + b.rect.h))) {
      return &b;
    }
  }
  return NULL;
}

