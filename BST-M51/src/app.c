#include <8052.h>
#define true 1
#define false 0
typedef unsigned char BYTE;
typedef unsigned int WORD;

void usartConfig() {
  SCON = 0x50;
  TMOD = 0x20;
  PCON = 0x00;
  TH1 = 0xfd;
  TL1 = 0xfd;
  ES = 1;
  EA = 1;
  TR1 = 1;
}

void delay(unsigned int i) {
  unsigned char j;
  for (i; i > 0; i--)
    for (j = 100; j > 0; j--)
      ;
}

void beep(int i) {
  P2_3 = i;
}

void main() {
  usartConfig();

  // all led off
  P1 = 0xff;

  while (true) {
    if (P3_4 == 0) {
      // 去干扰
      delay(10);
      if (P3_4 == 0) {
        while (P3_4 == 0) {
          // clicking
          P1_0 = 0;
        }
        // click up

        // send data
        SBUF = 0x30;
        while (!TI)
          ;
        TI = 0;

        P1_0 = 1;
      }
    }

    if (P3_5 == 0) {
      // 去干扰
      delay(10);
      if (P3_5 == 0) {
        while (P3_5 == 0) {
          // clicking
          P1_0 = 0;
        }
        // click up

        // send data
        SBUF = 0x31;
        while (!TI)
          ;
        TI = 0;

        P1_0 = 1;
      }
    }
  }
}

void sendUart(BYTE data) {
  while (!TI)
    ;
  TI = 0;
  SBUF = data;
}

// void uart() __interrupt(4) {
//   unsigned char data;
//   data = SBUF;
//   RI = 0;
//   SBUF = data;
//   while (!TI)
//     ;
//   TI = 0;
// }