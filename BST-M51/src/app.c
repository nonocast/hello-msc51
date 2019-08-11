#include <8052.h>

void delay(unsigned int i) {
  unsigned char j;
  for (i; i > 0; i--)
    for (j = 100; j > 0; j--)
      ;
}

void main() {
  while (1) {
    P1 = 0x55;
    delay(1000);
    P1 = 0xAA;
    delay(1000);
  }
}
