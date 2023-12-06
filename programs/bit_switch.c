#include <stdint.h>


void bit_switch(uint8_t *num, uint8_t pos1, uint8_t pos0) {
  uint8_t bit0 = 1 << pos0;
  uint8_t bit1 = 1 << pos1;
  uint8_t val0 = *num & bit0;
  uint8_t val1 = *num & bit0;

  *num &= (~bit0 & ~bit1);

  *num |= (val0 << (pos1 - pos0));
  *num |= (val1 >> (pos1 - pos0));
}
