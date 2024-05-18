#include "led_manager.h"
led_manager::led_manager() {
  M5.begin(true, false, true);
}

void led_manager::set_color(CRGB color) {
  M5.dis.drawpix(0, (color.g << 16) | (color.r << 8) | color.b);
}