#ifndef _H_UIELEMENTS
#define _H_UIELEMENTS

#include <SDL.h>
#include "Types.hpp"
#include "Render.hpp"

Button create_button_mim(SDL_Rect rect, SDL_Color color);
Button* select_button(Button_Vec& bv, int x, int y);
Button* select_button_from_layout(Layout_Vec& layout_vec, int x, int y);
void button_set_color(Button& button, SDL_Color color);
void button_click(Button& button);
void init_ui_elements_buttons_mim(Button_Vec& bv);
void update_button_position(Button* to_update, int x_diff, int y_diff);

Layout create_default_layout_mim();
Layout* select_layout(Layout_Vec& lv, int& x, int& y);
bool is_top_bar_clicked(Layout& layout, int& x, int& y);
void layout_click(Layout& layout, int& x, int& y);
void make_top_bar_layout(SDL_Rect& layout_rect, SDL_Rect& top_bar_rect);
void update_layout_position(Layout* to_update, int x_diff, int y_diff);

#endif /* _H_UIELEMENTS */

