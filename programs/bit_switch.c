#define SW_ADDR  (volatile char*) 0x0000
#define LED_ADDR (volatile char*) 0x0000
#define HEX_ADDR (volatile char*) 0x0000

void write_out(char val) {
  volatile char *sw = SW_ADDR;
  volatile char *led = LED_ADDR;

  *sw = val;
  *led = val;
}

void bit_switch(char *num, char pos1, char pos0) {
  char bit0 = 1 << pos0;
  char bit1 = 1 << pos1;
  char val0 = *num & bit0;
  char val1 = *num & bit0;

  *num &= (~bit0 & ~bit1);

  *num |= (val0 << (pos1 - pos0));
  *num |= (val1 >> (pos1 - pos0));
}

void inverse(char *num) {
  bit_switch(num, 7, 0);
  bit_switch(num, 6, 1);
  bit_switch(num, 5, 2);
  bit_switch(num, 4, 3);
}

void sw_var(char *num) {
  bit_switch(num, 1, 0);
  bit_switch(num, 3, 1);
  bit_switch(num, 4, 3);
  bit_switch(num, 5, 2);
  bit_switch(num, 7, 5);
}

int main() {
  // pass
}
