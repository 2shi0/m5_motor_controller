#include "led_manager.h"
#include "mortor_driver.h"

led_manager l;
mortor_driver m;

void setup() {
  m.write_vset(DRV2_ADR, MIN_VSET, M_STANBY); 
}
void loop() {
  l.set_color(CRGB::Red);
  m.write_vset(DRV2_ADR, MAX_VSET, M_NORMAL);
  m.write_vset(DRV1_ADR, MAX_VSET, M_NORMAL);
  delay(3000);
  l.set_color(CRGB::Blue);
  m.write_vset(DRV2_ADR, MAX_VSET, M_REVERSE);
  m.write_vset(DRV1_ADR, MAX_VSET, M_NORMAL);
  delay(3000);
}