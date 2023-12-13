#define SW_ADDR  (volatile char*) 0x0000
#define LED_ADDR (volatile char*) 0x0000
#define HEX_ADDR (volatile char*) 0x0000

void write_out(char val) {
  volatile char *sw = SW_ADDR;
  volatile char *led = LED_ADDR;

  *sw = val;
  *led = val;
}

int main() {
  char cnt = 0;

  while (1) {
    cnt++;
    write_out(cnt);
  }
}
