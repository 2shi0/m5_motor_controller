#include "M5Atom.h"
#include "led_manager.h"

led_manager l;

void setup() {
  l.set_color(CRGB::Red);
}
void loop() {
  l.set_color(CRGB::Red);
  delay(1000);
  l.set_color(CRGB::Blue);
  delay(1000);
  l.set_color(CRGB::White);
  delay(1000);
}