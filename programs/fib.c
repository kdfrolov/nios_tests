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
  unsigned char prev = 0;
  unsigned char curr = 1;

  while (1) {
    write_out(&prev);

    unsigned char tmp = prev + curr;
    prev = curr;
    curr = tmp;
  }
}
