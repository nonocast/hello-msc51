#include <8052.h>

unsigned char codes[17] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00};

void delay(unsigned int i) {
  unsigned char j;
  for (i; i > 0; i--)
    for (j = 100; j > 0; j--)
      ;
}

// light(~(0x01 << (i%8)))
void light(int i) {
  P1 = i;
}

void beep(int i) {
  P2_3 = i;
}

void led(unsigned char c) {
  P2_4 = 1;
  P2_5 = 1;
  P2_6 = 1;
  P2_7 = 1;
  P0 = c;
}

void main() {
  int i = 0;
  while (++i) {
    delay(1000);
    beep(i % 2);
    led(codes[i % 17]);
    light(~(0x01 << (i % 8)));
  }
}
