#ifndef _H_UIELEMENTS
#define _H_UIELEMENTS

#include <SDL.h>
#include "Types.hpp"
#include "Render.hpp"

Button create_button_mim(SDL_Rect rect, SDL_Color color);
void button_set_color(Button& button, SDL_Color color);

void init_ui_elements_buttons_mim(Button_Vec& bv);

Button* select_button(Button_Vec& bv, int x, int y);

#endif /* _H_UIELEMENTS */

