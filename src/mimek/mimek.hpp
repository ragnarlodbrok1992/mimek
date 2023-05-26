#define SDL_MAIN_HANDLED

#include "const.hpp"
#include "macros.hpp"
#include "UIelements.hpp"
#include "Input.hpp"

#include <SDL.h>

#include <stdio.h>

int init_mim(SDL_Window*& engine_window, SDL_Renderer*& engine_renderer);
void run_mim(SDL_Renderer*& engine_renderer, bool& running);
void clean_mim(SDL_Window*& engine_window, SDL_Renderer*& engine_renderer);

inline void setrendercolor_mim(SDL_Renderer*& engine_renderer, SDL_Color& color);

// Render functions
// There is a general purpose render function for testing and debugging purposes
// Also for different UI elements there are dedicated functions - one for aggregates (vectors for now)
// other for separate UI elements - check UIElements.hpp
inline void render(SDL_Renderer*& engine_renderer);
inline void render_ui_buttons(SDL_Renderer*& engine_renderer, Button_Vec& bv);

void test_mim();

