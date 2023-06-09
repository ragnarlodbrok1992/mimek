#ifndef _H_COLOR
#define _H_COLOR

#include <SDL.h>

constexpr SDL_Color WHITE = {255, 255, 255, 255};
constexpr SDL_Color BLACK = {0,   0,   0,   255};

constexpr SDL_Color RED   = {255, 0,   0,   255};
constexpr SDL_Color GREEN = {0,   255, 0,   255};
constexpr SDL_Color BLUE  = {0,   0,   255, 255};

constexpr SDL_Color LIGHT_GRAY = {211, 211, 211, 255};
constexpr SDL_Color SILVER     = {192, 192, 192, 255};
constexpr SDL_Color DARK_GRAY  = {169, 169, 169, 255};
constexpr SDL_Color GRAY       = {128, 128, 128, 255};

constexpr SDL_Color YELLOW     = {255, 255, 0,   255};

// Default button colors
constexpr SDL_Color DEFAULT_BUTTON_PURPLE = {163, 73, 164, 255};

void color_mim_change_lightness(SDL_Color& main_color, SDL_Color& light_color, float brightness);
void color_mim_rgb_to_hsl(uint8_t& r, uint8_t& g, uint8_t& b, int& h, float& s, float& l);

#endif /* _H_COLOR */

