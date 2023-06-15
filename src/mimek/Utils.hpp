#ifndef _H_UTILS
#define _H_UTILS

#include <SDL.h>
#include "Types.hpp"

// Float helper functions
void utils_mim_clamp_float(float& value);
float utils_mim_min_3_floats(float a, float b, float c);
float utils_mim_max_3_floats(float a, float b, float c);

int utils_mim_min_3_ints(int a, int b, int c);
int utils_mim_max_3_ints(int a, int b, int c);

// Return fixed array of 5 SDL_Points out of rectangle
void utils_mim_get_points_from_rect(SDL_Point (&points)[5], const SDL_Rect& rect);
void utils_mim_get_points_to_inner_button(SDL_Point (&points_outer)[5], SDL_Point (&points_inner)[5]);
void utils_mim_yminmax_xminmax_from_points2d_vec(Point2D_Vec vec, int& y_min, int& y_max, int& x_min, int& x_max);

// Type-casting functions
Point2D utils_mim_sdl_point_to_point_2d(SDL_Point pt);

// Print functions
void print_points(SDL_Point (&points)[5]);
void print_color(SDL_Color color);
void print_rect(SDL_Rect rect);

#endif /* _H_UTILS */

