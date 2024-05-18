#include "mortor_driver.h"

mortor_driver::mortor_driver(){
    Wire.begin();
}

/**
 * @fn
 * @brief 制御コマンド送信
 * @param mtr モーター(2つ)の選択 DRV_ADR1 / DRV_ADR2
 * @param vs 電圧(8bit値)
 * @param ctr M_STANBY(スタンバイ) / M_NORMAL(正転) / M_REVERSE(逆転) / M_BRAKE(ブレーキ)
 * @return 戻り値の説明
 * @sa 参照すべき関数を書けばリンクが貼れる
 * @detail 詳細な説明
 */
int mortor_driver::write_vset(byte mtr, byte vs, byte ctr) {
  Wire.beginTransmission(mtr);
  Wire.write(CTR_ADR);
  Wire.write( ctr + (vs<<2) );
  return Wire.endTransmission();
}