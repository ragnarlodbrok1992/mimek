#include <SDL.h>
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

Button create_button_mim(SDL_Rect rect);
void inline render_button_mim(SDL_Renderer*& engine_renderer, Button& bt);

