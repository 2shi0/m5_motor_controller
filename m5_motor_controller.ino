#include <Ps3Controller.h>
#include <M5Atom.h>
#include "mortor_driver.h"

//mortor driver init
mortor_driver m;

CRGB display_color(uint8_t r, uint8_t g, uint8_t b) {
  return (CRGB)((r << 16) | (g << 8) | b);
}

void setup() {
  Serial.begin(115200);

  //led init
  M5.begin(true, false, true);

  //dualshock3 init
  Ps3.begin("4C:75:25:CE:39:A6");
  Ps3.setPlayer(0);

  Serial.println("Ready.");
}

bool r, l;
void loop() {
  if (!Ps3.isConnected()) {
    M5.dis.drawpix(0, 0, 0);
    delay(100);
    M5.dis.drawpix(0, 0, 255);
    delay(100);

    return;
  }

  r = m.write_vset_from_analog(Ps3.data.analog.stick.ry, DRV_1_ADR);
  vTaskDelay(1 / portTICK_RATE_MS);
  l = m.write_vset_from_analog(Ps3.data.analog.stick.ly, DRV_2_ADR);
  vTaskDelay(1 / portTICK_RATE_MS);

  if (r || l)
    M5.dis.drawpix(0, display_color(255, 0, 0));
  else
    M5.dis.drawpix(0, 0, 225);
}