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
  char prev = 0;
  char curr = 1;

  while (1) {
    write_out(prev);

    char tmp = prev + curr;
    prev = curr;
    curr = tmp;
  }
}
