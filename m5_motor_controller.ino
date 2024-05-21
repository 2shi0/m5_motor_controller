#include <Ps3Controller.h>
#include <M5Atom.h>
#include "mortor_driver.h"

//mortor driver init
mortor_driver m;

void setup() {
  Serial.begin(115200);

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

  /*
  m.write_vset(DRV_1_ADR, MAX_VSET, M_NORMAL);
  m.write_vset(DRV_2_ADR, MAX_VSET, M_NORMAL);
  delay(3000);
  m.write_vset(DRV_1_ADR, MAX_VSET, M_REVERSE);
  m.write_vset(DRV_2_ADR, MAX_VSET, M_REVERSE);
  delay(3000);
  */

  Serial.println(m.write_vset_from_analog(Ps3.data.analog.stick.ly, DRV_1_ADR));
}