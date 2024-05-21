#ifndef _MORTOR_DRIVER_h
#define _MORTOR_DRIVER_h

// I2Cアドレス
#define DRV_1_ADR 0x65  // DRV8830-1のI2Cアドレス
#define DRV_2_ADR 0x64  // DRV8830-2のI2Cアドレス
#define CTR_ADR 0x00    // CONTROLレジスタのサブアドレス
#define FLT_ADR 0x01    // FAULTレジスタのアドレス

// ブリッジ制御
#define M_STANBY B00   // スタンバイ
#define M_REVERSE B01  // 逆転
#define M_NORMAL B10   // 正転
#define M_BRAKE B11    // ブレーキ

// 電圧定義
#define MAX_VSET 0x2E  // 3.69V
#define MIN_VSET 0x06  // 0.48V

// デッドゾーン
#define DEAD_ZONE 16 //アナログスティックの不感地帯を決める

#include "Arduino.h"
#include <Wire.h>
class mortor_driver {
public:
  mortor_driver();
  int write_vset(byte mtr, byte vs, byte ctr);
  uint8_t write_vset_from_analog(int8_t analog_value, byte mtr);

private:
  double voltage_ratio;
};

#endif