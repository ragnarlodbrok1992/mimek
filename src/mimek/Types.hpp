#ifndef _H_TYPES
#define _H_TYPES

#include <vector>
#include "Color.hpp"

#define OUTBAR_SIZE_BUTTON 15

enum STATUS {
  UnFocused,
  Focused,
  Clicked
};

typedef struct Point2D {
  int x;
  int y;
} Point2D;

typedef struct Button {
  size_t id;

  SDL_Rect rect;
  int outbar_size = OUTBAR_SIZE_BUTTON; // in pixels

  SDL_Color main_color;
  SDL_Color light_color; // Color should be in some relation to main color
  SDL_Color outline = WHITE; // White of course
  SDL_Color innerlines = GRAY; // Gray

  STATUS status;

} Button;


typedef std::vector<Button> Button_Vec;
typedef std::vector<Point2D> Point2D_Vec;

#endif /* _H_TYPES */

