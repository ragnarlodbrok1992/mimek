#ifndef _H_TYPES
#define _H_TYPES

#include <vector>

enum STATUS {
  UnFocused,
  Focused,
  Clicked
};

typedef struct Button {
  SDL_Rect rect;
  SDL_Color color;

  STATUS status;

} Button;


typedef std::vector<Button> Button_Vec;

#endif /* _H_TYPES */

