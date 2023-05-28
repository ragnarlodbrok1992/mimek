#ifndef _H_INPUT
#define _H_INPUT

#include <cstdint>
#include <stdio.h>

typedef struct Mouse_Pointer {
  int pos_x;
  int pos_y;
  uint32_t mouse_state;
} Mouse_Pointer;

void zero_mouse_pointer(Mouse_Pointer& mp);

void print_mouse_state(Mouse_Pointer& mp);

#endif /* _H_INPUT */

