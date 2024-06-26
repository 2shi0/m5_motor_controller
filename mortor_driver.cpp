#include "mortor_driver.h"

mortor_driver::mortor_driver() {
  voltage_ratio = (MAX_VSET - MIN_VSET) / (128.0 - DEAD_ZONE);
  Wire.begin();
}

/**
 * @fn
 * @brief 制御コマンド送信
 * @param mtr モーターの選択 DRV_1_ADR / DRV_1_ADR
 * @param vs 電圧 MIN_VSET ~ MAX_VSET
 * @param ctr M_STANBY(スタンバイ) / M_NORMAL(正転) / M_REVERSE(逆転) / M_BRAKE(ブレーキ)
 */
int mortor_driver::write_vset(byte mtr, byte vs, byte ctr) {
  Wire.beginTransmission(mtr);
  Wire.write(CTR_ADR);
  Wire.write(ctr + (vs << 2));
  return Wire.endTransmission();
}

bool mortor_driver::write_vset_from_analog(int8_t analog_value, byte mtr) {
  if (analog_value > -DEAD_ZONE && analog_value < DEAD_ZONE) {
    write_vset(mtr, MIN_VSET, M_BRAKE);
    return 0;
  }

  byte v = MIN_VSET + round((abs(analog_value) - DEAD_ZONE) * voltage_ratio);

  if (analog_value < 0) {  //-128~1 up
    write_vset(mtr, v, M_NORMAL);
  } else {  //0~127 down
    write_vset(mtr, v, M_REVERSE);
  }
  return 1;
}