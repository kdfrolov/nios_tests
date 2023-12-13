#define SW_ADDR  (volatile char*) 0x0000
#define LED_ADDR (volatile char*) 0x0000
#define HEX_ADDR (volatile char*) 0x0000

void write_out(char val) {
  volatile char *sw = SW_ADDR;
  volatile char *led = LED_ADDR;

  *sw = val;
  *led = val;
}

char read_from() {
  volatile char *led = LED_ADDR;
  return *led;
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
  char val = read_from();

  char res = (char)isqrt(val);
  write_out(res);
}
