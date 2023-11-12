RGB_MATRIX_EFFECT(PLYWOOD)

#ifndef PLYWOOD_UNDERGLOW_VARIATION
#   define PLYWOOD_UNDERGLOW_VARIATION    6
#endif

#ifndef PLYWOOD_KEYLIGHT_SHIFT
#   define PLYWOOD_KEYLIGHT_SHIFT 128
#endif

#ifndef PLYWOOD_KEYLIGHT_LAYER_SELECT_SHIFT
#   define PLYWOOD_KEYLIGHT_LAYER_SELECT_SHIFT 16
#endif

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#include "quantum.h"

static uint8_t add8_rollover(uint8_t a, uint8_t b) {
  uint16_t i = a + b;
  if (i > 0xFF) { return i - 0xFF; }
  else { return i; }
}

static uint8_t sub8_rollover(uint8_t a, uint8_t b) {
    int16_t i = a - b;
    if (i < 0) { return 0xFF + i; }
    else { return i; }
}

static void PLYWOOD_complex_init(effect_params_t* params) { }

static HSV PLYWOOD_underglow(HSV hsv, uint16_t x, int16_t dx, uint16_t y, int16_t dy, uint8_t dist, uint16_t time) {
  uint8_t animation = scale8(cos8(time), PLYWOOD_UNDERGLOW_VARIATION);
  hsv.h = sub8_rollover(hsv.h, PLYWOOD_UNDERGLOW_VARIATION / 2) + animation;
  return hsv;
}

static HSV PLYWOOD_layer_highlight(uint8_t layer, HSV hsv, uint8_t phase, uint8_t slow_phase) {
  if (IS_LAYER_ON(layer)) {
    hsv.h = add8_rollover(hsv.h, PLYWOOD_KEYLIGHT_LAYER_SELECT_SHIFT);
    hsv.s = sub8(hsv.s, scale8(phase, hsv.s / 2));
    hsv.v = hsv.v - scale8(0xFF - phase, hsv.v / 3);
  } else {
    hsv.v = hsv.v - scale8(0xFF - slow_phase, (hsv.v * 2) / 3);
  }
  return hsv;
}

#define PL_INDICATE(id) \
  if (PLYWOOD_INDICATOR_ ## id) { \
    hsv.v = orgv; \
    hsv = PLYWOOD_layer_highlight((PLYWOOD_INDICATOR_LAYER_ ## id), hsv, fast_phase, slow_phase); \
  }

static HSV PLYWOOD_keylight(HSV hsv, uint16_t x, int16_t dx, uint16_t y, int16_t dy, uint8_t dist, uint16_t time) {
  // scale8_video(i, sc) = ((i * sc) / 256) +? 1 = [1-sc]
  // sin8(d) = sine of d [0-255] gives a value between [0-255]
  uint8_t theta = time + dist;
  if (hsv.v == 0) hsv.v = 1;
  uint8_t orgv = hsv.v;
  uint8_t slow_phase = sin8(theta);
  uint8_t fast_phase = sin8(add8_rollover(add8_rollover(theta, theta), theta));
  hsv.v = sub8(hsv.v, scale8(slow_phase, hsv.v));

  PL_INDICATE(L1);
  PL_INDICATE(L2);
  PL_INDICATE(L3);
  PL_INDICATE(L4);
  PL_INDICATE(L5);
  PL_INDICATE(R1);
  PL_INDICATE(R2);
  PL_INDICATE(R3);
  PL_INDICATE(R4);
  PL_INDICATE(R5);

  return hsv;
}

#undef PL_INDICATE

static bool PLYWOOD_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  HSV hsv = rgb_matrix_config.hsv;

  // g_rgb_timer is an 32-bit int, scale it down into a value
  // between 0-MAX where MAX is a value between 0 and 127
  uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);

  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();

    int16_t x = g_led_config.point[i].x;
    int16_t y = g_led_config.point[i].y;
    int16_t dx = x - k_rgb_matrix_center.x;
    int16_t dy = y - k_rgb_matrix_center.y;
    // sqrt16 takes a 16-bit and returns a 8-bit
    uint8_t dist = sqrt16(dx * dx + dy * dy);

    HSV output_hsv = hsv;

    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
      output_hsv.h = 0;
    } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
      output_hsv = PLYWOOD_keylight(hsv, x, dx, y, dy, dist, time);
    } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
      output_hsv = PLYWOOD_underglow(hsv, x, dx, y, dy, dist, time);
    }

    RGB output_rgb = rgb_matrix_hsv_to_rgb(output_hsv);
    rgb_matrix_set_color(i, output_rgb.r, output_rgb.g, output_rgb.b);
  }

  return rgb_matrix_check_finished_leds(led_max);
}
static bool PLYWOOD(effect_params_t* params) {
  if (params->init) PLYWOOD_complex_init(params);
  return PLYWOOD_complex_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
