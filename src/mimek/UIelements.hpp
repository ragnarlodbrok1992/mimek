#ifndef _H_UIELEMENTS
#define _H_UIELEMENTS

#include <SDL.h>
#include "Types.hpp"
#include "Render.hpp"

Button create_button_mim(SDL_Rect rect, SDL_Color color);
Button* select_button(Button_Vec& bv, int x, int y);
void button_set_color(Button& button, SDL_Color color);
void button_click(Button& button);
void init_ui_elements_buttons_mim(Button_Vec& bv);

Layout* init_default_layout_mim();
void make_top_bar_of_layout(SDL_Rect& layout_rect, SDL_Rect& top_bar_rect);


#endif /* _H_UIELEMENTS */

