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

uint8_t read_from() {
  volatile uint8_t *led = LED_ADDR;
  return *led;
}

uint32_t isqrt(uint32_t x) {
    uint32_t m, y, b;
    m = 0x40000000;
    y = 0;
    while (m != 0) {
        b = y |  m;
        y >>= 1;
        if (x >= b) {
            x -= b;
            y |= m;
        }
        m >>= 2;
    }
    return y;
}

int main() {
  uint8_t val = read_from();

  uint8_t res = (uint8_t)isqrt(val);
  write_out(res);
}
