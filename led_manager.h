#ifndef _LED_MANAGER_h
#define _LED_MANAGER_h
#include "Arduino.h"
#include "M5Atom.h"
class led_manager {
public:
  led_manager();
  void set_color(CRGB color);
};
#endif