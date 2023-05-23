#define SDL_MAIN_HANDLED

#include "const.hpp"

#include <SDL.h>

#include <stdio.h>

int init_mim(SDL_Window* engine_window, SDL_Renderer* engine_renderer);
void run_mim(SDL_Renderer* engine_renderer, bool& running);
void clean_mim(SDL_Window* engine_window, SDL_Renderer* engine_renderer);

