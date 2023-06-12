#include "Utils.hpp"

#include "Types.hpp"
#include "macros.hpp"
#include "ui_sizes_const.hpp"

#include <stdio.h>

void utils_mim_clamp_float(float& value) {
  if (value > 1.0) value = 1.0;
  if (value < 0.0) value = 0.0;
}

float utils_mim_min_3_floats(float a, float b, float c) {
  float min;
  
  if (a < b) min = a; else min = b;
  if (c < min) min = c;

  return min;
}

float utils_mim_max_3_floats(float a, float b, float c) {
  float max;

  if (a > b) max = a; else max = b;
  if (c > max) max = c;

  return max;
}

int utils_mim_min_3_ints(int a, int b, int c) {
  int min;

  if (a < b) min = a; else min = b;
  if (c < min) min = c;

  return min;
}

int utils_mim_max_3_ints(int a, int b, int c) {
  int max;

  if (a > b) max = a; else max = b;
  if (c > max) max = c;

  return max;
}

void utils_mim_get_points_from_rect(SDL_Point (&points)[5], const SDL_Rect& rect) {
  points[0].x = rect.x;
  points[0].y = rect.y;

  points[1].x = rect.x + rect.w;
  points[1].y = rect.y;

  points[2].x = rect.x + rect.w;
  points[2].y = rect.y + rect.h;

  points[3].x = rect.x;
  points[3].y = rect.y + rect.h;

  // Set last point as the first point
  points[4].x = points[0].x;
  points[4].y = points[0].y;
}

void utils_mim_get_points_to_inner_button(SDL_Point (&points_outer)[5], SDL_Point (&points_inner)[5]) {
  // COORDINATE SYSTEM
  // +---------------> X
  // |     Width
  // |
  // |
  // | Height
  // |
  // v
  // Y
  points_inner[0].x = points_outer[0].x + DEFAULT_BUTTON_MARGIN; 
  points_inner[0].y = points_outer[0].y + DEFAULT_BUTTON_MARGIN;

  points_inner[1].x = points_outer[1].x - DEFAULT_BUTTON_MARGIN;
  points_inner[1].y = points_outer[1].y + DEFAULT_BUTTON_MARGIN;

  points_inner[2].x = points_outer[2].x - DEFAULT_BUTTON_MARGIN;
  points_inner[2].y = points_outer[2].y - DEFAULT_BUTTON_MARGIN;

  points_inner[3].x = points_outer[3].x + DEFAULT_BUTTON_MARGIN;
  points_inner[3].y = points_outer[3].y - DEFAULT_BUTTON_MARGIN;

  points_inner[4].x = points_outer[4].x + DEFAULT_BUTTON_MARGIN;
  points_inner[4].y = points_outer[4].y + DEFAULT_BUTTON_MARGIN;
}

void utils_mim_yminmax_xminmax_from_points2d_vec(Point2D_Vec vec, int& y_min, int& y_max, int& x_min, int& x_max) {
  y_min = INT_MAX;
  y_max = INT_MIN;
  x_min = INT_MAX;
  x_max = INT_MIN;

  for (auto point : vec) {
    if (x_min > point.x) x_min = point.x;
    if (x_max < point.x) x_max = point.x;
    if (y_min > point.y) y_min = point.y;
    if (y_max < point.y) y_max = point.y;
  }
}

Point2D utils_mim_sdl_point_to_point_2d(SDL_Point pt) {
  Point2D temp;
  temp.x = pt.x;
  temp.y = pt.y;
  return temp;
}

void print_points(SDL_Point (&points)[5]) {
  printf("0 -> x: %d y: %d\n", points[0].x, points[0].y);
  printf("1 -> x: %d y: %d\n", points[1].x, points[1].y);
  printf("2 -> x: %d y: %d\n", points[2].x, points[2].y);
  printf("3 -> x: %d y: %d\n", points[3].x, points[3].y);
  printf("4 -> x: %d y: %d\n", points[4].x, points[4].y);
}

void print_color(SDL_Color color) {
  printf("Red  : %d\n", color.r);
  printf("Green: %d\n", color.g);
  printf("Blue : %d\n", color.b);
}


