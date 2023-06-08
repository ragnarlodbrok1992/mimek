#ifndef _H_UTILS
#define _H_UTILS

#include <SDL.h>

// Return fixed array of 5 SDL_Points out of rectangle
void utils_mim_get_points_from_rect(SDL_Point (&points)[5], const SDL_Rect& rect);
void utils_mim_get_points_to_inner_button(SDL_Point (&points_outer)[5], SDL_Point (&points_inner)[5]);
void print_points(SDL_Point (&points)[5]);

#endif /* _H_UTILS */

