#include "Input.hpp"

void zero_mouse_pointer(Mouse_Pointer& mp) {
  mp.pos_x = 0;
  mp.pos_y = 0;
  mp.mouse_state = 0;
}

void print_mouse_state(Mouse_Pointer& mp) {
  printf("Mouse -> pos_x:         %d\n", mp.pos_x);
  printf("Mouse -> pos_y:         %d\n", mp.pos_y);
  printf("Mouse -> mouse_state: 0x%x\n", mp.mouse_state);
}

