#include "Color.hpp"
#include "Utils.hpp"
#include "macros.hpp"

#include <SDL.h>

void color_mim_change_lightness(SDL_Color& main_color, SDL_Color& changed_color, float brightness) {
  // COMPILETIME_NOT_IMPLEMENTED
}

void color_mim_rgb_to_hsl(uint8_t& r, uint8_t& g, uint8_t& b, int& h, float& s, float& l) {
  // COMPILETIME_NOT_IMPLEMENTED
  float min, max, delta;
  float rf, bf, gf;
  float hue;

  rf = r / 255.0f;
  gf = g / 255.0f;
  bf = b / 255.0f;

  min = utils_mim_min_3_floats(rf, gf, bf);
  max = utils_mim_max_3_floats(rf, gf, bf);

  delta = max - min;

  l = (max + min) / (float)2.0;

  printf("Delta in function: %f\n", delta);

  if (delta == 0.0) {
    h = 0;
    s = 0.0f;
  } else {
    s = (l <= 0.5) ? (delta / (max + min)) : (delta / (2 - max - min));


    if (rf == max) {
      hue = ((gf - bf) / 6) / delta;
    } else if (gf == max) {
      hue = (1.0f / 3) + (((bf - rf) / 6) / delta);
    } else {
      hue = (2.0f / 3) + (((rf - gf) / 6) / delta);
    }

    if (hue < 0) hue += 1;
    if (hue > 1) hue -= 1;

    // DEBUG 
    printf("Hue in function: %f\n", hue);

    h = (int)(hue * 360);
  }
}
