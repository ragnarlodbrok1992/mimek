#ifndef _H_TYPES
#define _H_TYPES

#include <vector>
#include "Color.hpp"
#include "Text.hpp"


enum STATUS {
  UN_FOCUSED,
  FOCUSED,
  CLICKED 
};

enum LAYOUT_TYPE {
  TOP_BOTTOM_LINE,
  LEFT_RIGHT_LINE
};

typedef struct Point2D {
  int x;
  int y;
} Point2D;

typedef struct Button {
  size_t id;

  STATUS status;

  // Movable elements - can be dragged around
  // void update_movable_elements(int x, int y);
  SDL_Rect rect;

  // @TODO: colors based on status
  SDL_Color main_color;
  SDL_Color light_color; // Color should be in some relation to main color

  SDL_Color focused_main_color;
  SDL_Color focused_light_color;

  SDL_Color clicked_main_color;
  SDL_Color clicked_light_color;

  SDL_Color outline = WHITE; // White of course
  SDL_Color innerlines = GRAY; // Gray

} Button;

typedef std::vector<Button>  Button_Vec;

typedef struct Layout {
  Button_Vec buttons; 

  LAYOUT_TYPE layout_type;

  // Movable elements - can be dragged around
  // void update_movable_elements(int x, int y);
  SDL_Rect top_bar; // Kinda lighter - allows to drag around layouts
  SDL_Rect background;

  SDL_Color background_color; // It should have lower alpha value?

  bool is_sticked;
} Layout;

typedef std::vector<Point2D> Point2D_Vec;
typedef std::vector<Layout>  Layout_Vec;

#endif /* _H_TYPES */

