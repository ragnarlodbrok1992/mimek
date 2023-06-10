#include "Color.hpp"
#include "Utils.hpp"
#include "macros.hpp"

#include <SDL.h>

void color_mim_change_lightness(SDL_Color& main_color, SDL_Color& changed_color, float brightness) {
  int h;
  float s, l;

  color_mim_rgb_to_hsl(main_color.r, main_color.g, main_color.b, h, s, l);
  l = brightness; // Should this be changed like this?
  color_mim_hsl_to_rgb(h, s, l, changed_color.r, changed_color.g, changed_color.b);
}

void color_mim_rgb_to_hsl(uint8_t& r, uint8_t& g, uint8_t& b, int& h, float& s, float& l) {
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

    h = (int)(hue * 360);
  }
}

void color_mim_hsl_to_rgb(int& h, float& s, float& l, uint8_t& r, uint8_t& g, uint8_t& b) {
  if (s == 0.0) {
    r = (uint8_t) (l * 255);
    g = (uint8_t) (l * 255);
    b = (uint8_t) (l * 255);
  } else {
    float v1, v2;
    float hue = (float) h / 360;

    v2 = (l < 0.5) ? (l * (1 + s)) : (l + s) - (l * s);
    v1 = 2 * l - v2;

    r = (uint8_t) (255 * color_mim_hue_to_rgb(v1, v2, hue + (1.0f / 3)));
    g = (uint8_t) (255 * color_mim_hue_to_rgb(v1, v2, hue));
    b = (uint8_t) (255 * color_mim_hue_to_rgb(v1, v2, hue - (1.0f / 3)));
  }
}

float color_mim_hue_to_rgb(float v1, float v2, float vH) {
  if (vH < 0) vH += 1;
  if (vH > 1) vH -= 1;

  if ((6 * vH) < 1) return (v1 + (v2 - v1) * 6 * vH);
  if ((2 * vH) < 1) return v2;
  if ((3 * vH) < 2) return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);

  return v1;
}
