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

int main() {
  uint8_t cnt = 0;

  while (1) {
    cnt++;
    write_out(cnt);
  }
}
