#ifndef _H_MIMEK
#define _H_MIMEK

#define SDL_MAIN_HANDLED

#include "const.hpp"
#include "macros.hpp"
#include "UIelements.hpp"
#include "Input.hpp"
#include "Render.hpp"
#include "Types.hpp"

#include <SDL.h>
#include <stdio.h>

int init_mim(SDL_Window*& engine_window, SDL_Renderer*& engine_renderer);
void run_mim(SDL_Renderer*& engine_renderer, bool& running);
void clean_mim(SDL_Window*& engine_window, SDL_Renderer*& engine_renderer);

void init_ui_elements_buttons_mim(Button_Vec& bv);

void test_mim();

#endif /* _H_MIMEK */

