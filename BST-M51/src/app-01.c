#include <8052.h>
#define true 1

unsigned char codes[17] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00};

int i = 0;

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

/**
 * 按下k2按键时会beep，同时切换P1.0,P1.1相反
 */
void app1() {
  P1 = 0xff;
  while (true) {
    if (P3_4 == 0) {
      delay(10);
      if (P3_4 == 0) {
        while (P3_4 == 0) {
          beep(0);
        }
        beep(1);
        if (P1_0 == 0) {
          P1_0 = 1;
          P1_1 = 1;
        } else {
          P1_0 = 0;
          P1_1 = 0;
        }
      }
    }
  }
}

void app2() {
  int i = 0;
  while (++i) {
    delay(1000);
    beep(i % 2);
    led(codes[i % 17]);
    light(~(0x01 << (i % 8)));
  }
}

/** 
 * c.10 定时器
 */
void app3() {
  // 初始化灯灭
  P1_0 = 1;

  // 声明定时器的工作方式 M1M0=10, 即工作方式2
  TMOD = 0x10;

  // 设置初始值
  TH1 = 0x4C;
  TL1 = 0x00;

  // 打开总中断
  EA = 1;

  // 打开定时器T0中断
  ET1 = 1;

  // 启动T0
  TR1 = 1;
}

void timer1() __interrupt(3) {
  TH1 = 0x4C;
  TL1 = 0x00;
  i = i + 1;
}

void main() {
  app1();
}