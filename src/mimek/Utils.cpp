#include "Utils.hpp"

#include "Types.hpp"
#include "macros.hpp"
#include <stdio.h>

void utils_mim_clamp_float(float& value) {
  COMPILETIME_NOT_IMPLEMENTED
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
  // @TODO: make inner points
  points_inner[0].x = points_outer[0].x + OUTBAR_SIZE_BUTTON; 
  points_inner[0].y = points_outer[0].y + OUTBAR_SIZE_BUTTON;

  points_inner[1].x = points_outer[1].x - OUTBAR_SIZE_BUTTON;
  points_inner[1].y = points_outer[1].y + OUTBAR_SIZE_BUTTON;

  points_inner[2].x = points_outer[2].x - OUTBAR_SIZE_BUTTON;
  points_inner[2].y = points_outer[2].y - OUTBAR_SIZE_BUTTON;

  points_inner[3].x = points_outer[3].x + OUTBAR_SIZE_BUTTON;
  points_inner[3].y = points_outer[3].y - OUTBAR_SIZE_BUTTON;

  points_inner[4].x = points_outer[4].x + OUTBAR_SIZE_BUTTON;
  points_inner[4].y = points_outer[4].y + OUTBAR_SIZE_BUTTON;
}

void print_points(SDL_Point (&points)[5]) {
  printf("0 -> x: %d y: %d\n", points[0].x, points[0].y);
  printf("1 -> x: %d y: %d\n", points[1].x, points[1].y);
  printf("2 -> x: %d y: %d\n", points[2].x, points[2].y);
  printf("3 -> x: %d y: %d\n", points[3].x, points[3].y);
  printf("4 -> x: %d y: %d\n", points[4].x, points[4].y);
}
