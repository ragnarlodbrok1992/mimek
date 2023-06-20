#include "UIelements.hpp"

#include "Types.hpp"
#include "Color.hpp"
#include "Utils.hpp"
#include "ui_sizes_const.hpp"
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
  bv.push_back(create_button_mim(DEFAULT_BUTTON_SIZE_POS, DEFAULT_BUTTON_PURPLE));
}

Button* select_button(Button_Vec& bv, int x, int y) {
  for (auto& b : bv) {
    /*
    if (((x > b.rect.x) && (x < b.rect.x + b.rect.w)) &&
        ((y > b.rect.y) && (y < b.rect.y + b.rect.h))) {
      return &b;
      */
    if (is_x_y_in_rect(b.rect, x, y)) return &b;
    }
  return NULL;
}

Button* select_button_from_layout(Layout_Vec& layout_vec, int x, int y) {
  Button* return_button = NULL;
  for (auto& layout : layout_vec) {
    return_button = select_button(layout.buttons, x, y);
    if (return_button != NULL) {
      return return_button;
    }
  }
  return NULL;
}

Layout create_default_layout_mim() {
  Layout temp_layout;

  // DEFAULT Layout
  temp_layout.layout_type = TOP_BOTTOM_LINE;

  temp_layout.background       = DEFAULT_LAYOUT_SIZE_POS;
  temp_layout.background_color = DEFAULT_LAYOUT_PURPLE;

  make_top_bar_layout(temp_layout.background, temp_layout.top_bar);

  // Creating default buttons for layout
  init_ui_elements_buttons_mim(temp_layout.buttons);

  // DEBUG
  print_rect(temp_layout.background);
  print_rect(temp_layout.top_bar);

  return temp_layout;
}

Layout* select_layout(Layout_Vec& lv, int x, int y) {
  for (auto& layout : lv) {
    /*
    if (((x > layout.background.x) && (x < layout.background.x + layout.background.w)) &&
        ((y > layout.background.y) && (y < layout.background.y + layout.background.h))) {
      return &layout;
      */
    if (is_x_y_in_rect(rect, x, y)) return &layout;
  }
  return NULL;
}

void layout_click(Layout& layout) {
  // Check if top_bar is clicked

}

void make_top_bar_layout(SDL_Rect& layout_rect, SDL_Rect& top_bar_rect) {
  // +---------------------------->
  // |
  // |
  // |
  // |
  // |
  // |
  // v

  top_bar_rect.x = layout_rect.x + 5;
  top_bar_rect.y = layout_rect.y + 5;
  top_bar_rect.w = layout_rect.w - 10;
  top_bar_rect.h = 15;

  // DEBUG
  print_rect(layout_rect);
  print_rect(top_bar_rect);

}

