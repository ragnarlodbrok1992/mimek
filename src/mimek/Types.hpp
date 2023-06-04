#ifndef _H_TYPES
#define _H_TYPES

#include <vector>

enum STATUS {
  UnFocused,
  Focused,
  Clicked
};



typedef struct Button {
  size_t id;

  SDL_Rect rect;
  // SDL_Rect inner_rect;

  SDL_Color main_color;
  SDL_Color light_color; // Color should be in some relation to main color
  SDL_Color outline = {0, 0, 0, 255}; // Black of course
  SDL_Color innerlines = {127, 127, 127, 255}; // Gray

  STATUS status;

} Button;


typedef std::vector<Button> Button_Vec;

#endif /* _H_TYPES */

