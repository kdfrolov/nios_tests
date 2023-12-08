#include <stdint.h>

#define SW_ADDR  (volatile uint8_t*) 0x0000
#define LED_ADDR (volatile uint8_t*) 0x0000
#define HEX_ADDR (volatile uint8_t*) 0x0000

void write_out(uint8_t val) {
  volatile uint8_t *sw = SW_ADDR;
  volatile uint8_t *led = LED_ADDR;

  *sw = val;
  *led = val;
}

void bit_switch(uint8_t *num, uint8_t pos1, uint8_t pos0) {
  uint8_t bit0 = 1 << pos0;
  uint8_t bit1 = 1 << pos1;
  uint8_t val0 = *num & bit0;
  uint8_t val1 = *num & bit0;

  *num &= (~bit0 & ~bit1);

  *num |= (val0 << (pos1 - pos0));
  *num |= (val1 >> (pos1 - pos0));
}

void inverse(uint8_t *num) {
  bit_switch(num, 7, 0);
  bit_switch(num, 6, 1);
  bit_switch(num, 5, 2);
  bit_switch(num, 4, 3);
}

void sw_var(uint8_t *num) {
  bit_switch(num, 1, 0);
  bit_switch(num, 3, 1);
  bit_switch(num, 4, 3);
  bit_switch(num, 5, 2);
  bit_switch(num, 7, 5);
}

int main() {
  // pass
}
