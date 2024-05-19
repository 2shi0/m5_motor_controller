#include <Ps3Controller.h>
#include <M5Atom.h>
#include "mortor_driver.h"

mortor_driver m;

void setup() {
  Serial.begin(115200);

  //mortor driver init
  m.write_vset(DRV2_ADR, MIN_VSET, M_STANBY);

  //led init
  M5.begin(true, false, true);

  //dualshock3 init
  Ps3.begin("4C:75:25:CE:39:A6");
  Ps3.setPlayer(0);

  Serial.println("Ready.");
}
void loop() {
  if (!Ps3.isConnected()) {
    M5.dis.drawpix(0, 0, 0);
    delay(100);
    M5.dis.drawpix(0, 0, 225);
    delay(100);
    
    return;
  }

  //l.set_color(CRGB::Red);
  m.write_vset(DRV2_ADR, MAX_VSET, M_NORMAL);
  m.write_vset(DRV1_ADR, MAX_VSET, M_NORMAL);
  delay(3000);
  //l.set_color(CRGB::Blue);
  m.write_vset(DRV2_ADR, MAX_VSET, M_REVERSE);
  m.write_vset(DRV1_ADR, MAX_VSET, M_REVERSE);
  delay(3000);
}