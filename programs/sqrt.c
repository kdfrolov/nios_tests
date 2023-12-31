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

int isqrt(int x) {
    int m, y, b;
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
  unsigned char val;
  while (1) {
    read_from(&val);
    val = (unsigned char)isqrt(val);
    write_out(&val);
  }
}
