#define SW_ADDR  (volatile unsigned char*) 0x0000
#define LED_ADDR (volatile unsigned char*) 0x0000
#define HEX_ADDR (volatile unsigned char*) 0x0000

void write_out(unsigned char *val) {
  volatile unsigned char *hex = HEX_ADDR;
  volatile unsigned char *led = LED_ADDR;

  *hex = *val;
  *led = *val;
}

int main() {
  unsigned char cnt = 0;

  while (1) {
    cnt++;
    write_out(&cnt);
  }
}
