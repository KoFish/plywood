RGB_MATRIX_EFFECT(PLYWOOD)

#ifndef PLYWOOD_UNDERGLOW_VARIATION
#   define PLYWOOD_UNDERGLOW_VARIATION    6
#endif


// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static void PLYWOOD_complex_init(effect_params_t* params) { }

static HSV PLYWOOD_underglow(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t time) {
  hsv.h = qsub8(hsv.h, PLYWOOD_UNDERGLOW_VARIATION / 2) + scale8(cos8(time), PLYWOOD_UNDERGLOW_VARIATION);
  return hsv;
}

static HSV PLYWOOD_keylight(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t time) {
  // scale8_video(i, sc) = ((i * sc) / 256) +? 1 = [1-sc]
  // sin8(d) = sine of d [0-255] gives a value between [0-255]
  uint8_t theta = time + dist;
  hsv.v = scale8_video(abs8(sin8(theta) - 128) * 2, hsv.v);
  return hsv;
}

static bool PLYWOOD_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  HSV hsv = rgb_matrix_config.hsv;

  // g_rgb_timer is an 32-bit int, scale it down into a value
  // between 0-MAX where MAX is a value between 0 and 127
  uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);

  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();

    int16_t dx = g_led_config.point[i].x - k_rgb_matrix_center.x;
    int16_t dy = g_led_config.point[i].y - k_rgb_matrix_center.y;
    // sqrt16 takes a 16-bit and returns a 8-bit
    uint8_t dist = sqrt16(dx * dx + dy * dy);

    HSV output_hsv = hsv;

    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) {
      output_hsv = PLYWOOD_keylight(hsv, dx, dy, dist, time);
    } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
      output_hsv = PLYWOOD_underglow(hsv, dx, dy, dist, time);
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
