#ifndef _H_UIELEMENTS
#define _H_UIELEMENTS

#include <SDL.h>
#include "Types.hpp"
#include "Render.hpp"

Button create_button_mim(SDL_Rect rect, SDL_Color color);
void inline render_button_mim(SDL_Renderer*& engine_renderer, Button& bt);

#endif /* _H_UIELEMENTS */

