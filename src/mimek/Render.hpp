#ifndef _H_RENDER
#define _H_RENDER

#include <SDL.h>
#include "Types.hpp"
#include "Color.hpp"

void set_rendercolor_mim(SDL_Renderer*& engine_renderer, const SDL_Color& color);

// Render functions
// There is a general purpose render function for testing and debugging purposes
void mim_render(SDL_Renderer*& engine_renderer);

// Function to render primitives
void mim_render_filled_polygon(SDL_Renderer*& engine_renderer, Point2D_Vec& points_vec);

// Also for different UI elements there are dedicated functions - one for aggregates (vectors for now)
// other for separate UI elements - check UIElements.hpp
void render_ui_buttons(SDL_Renderer*& engine_renderer, Button_Vec& bv);
void render_button(SDL_Renderer*& engine_renderer, Button& button);

#endif /* _H_RENDER */

