#define SW_ADDR  (volatile unsigned char*) 0x0000
#define LED_ADDR (volatile unsigned char*) 0x0000
#define HEX_ADDR (volatile unsigned char*) 0x0000

void write_out(unsigned char *val) {
  volatile unsigned char *hex = HEX_ADDR;
  volatile unsigned char *led = LED_ADDR;

  *hex = *val;
  *led = *val;
}

void read_from(unsigned char *val) {
  volatile unsigned char *sw = SW_ADDR;
  *val = *sw;
}

void swapBits(unsigned char *n, unsigned char p1, unsigned char p2) {
  if (((*n & (1 << p1)) >> p1) ^ ((*n & (1 << p2)) >> p2)) {
    *n ^= 1 << p1;
    *n ^= 1 << p2;
  }
}

void swap_var(unsigned char *num) {
  swapBits(num, 1, 0);
  swapBits(num, 3, 1);
  swapBits(num, 4, 3);
  swapBits(num, 5, 2);
  swapBits(num, 7, 5);
}

int main() {
  unsigned char val;
  while (1) {
    read_from(&val);
    swap_var(&val);
    write_out(&val);
  }
}
