#include "UIelements.hpp"

Button create_button_mim(SDL_Rect rect, SDL_Color color) {
  Button temp_button;
  temp_button.rect = rect;
  temp_button.color = color;
  temp_button.status = STATUS::UnFocused;

  return temp_button;
}