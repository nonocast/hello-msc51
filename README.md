手上正好有[手把手教你学51单片机](https://item.jd.com/11446466.html)和开发板就顺便学一下，书上都是Windows和Keil，网上搜了一下在Mac下也是ok的。

# 在Mac下搭建单片机开发环境
- editor: vscode
- compiler: [sdcc](http://sdcc.sourceforge.net)
- flash: [stcgal](https://github.com/grigorig/stcgal)
- board: [KST-51单片机开发板](https://item.taobao.com/item.htm?spm=a230r.1.14.15.b4761f640tzWJf&id=3253746357&ns=1&abbucket=5#detail)

# Step 1: 通过sdcc编译出ihx
```
brew install sdcc
```
然后头文件位置
```
/usr/local/Cellar/sdcc/3.9.0/share/sdcc/include/mcs51
```

```
sdcc app.c
```

## sdcc和keil差异
- Keil中的reg51.h/reg52.h改为8051.h/8052.h
- Keil中的P2^0改为P2_0
- Keil中的sbit LED = P2^0;改为#define LED P2_0
- Keil的interrupt改为_interrupt

## vscode settings
- includePath加入include files
```
"includePath": [
  ...
  "/usr/local/Cellar/sdcc/3.9.0/share/sdcc/include/mcs51"
]
```
- 设置代码风格
在C/C++ Settings中设置:
- C_Cpp.Clang_format_fallback Style: { BasedOnStyle: Google, IndentWidth: 2 }
- C_Cpp.intelliSenseEngine: Tag Parser

# Step 2: 通过stcgal刷机
```
pip3 install stcgal
```

开发板usb插到Mac上，不需要装任何驱动，直接ls /dev/tty.usbserial*
```
/dev/tty.usbserial-14310
```
在linux下,everything is file

开撸，
/src/app.c
```
#include <8052.h>

#define LED P0_0
#define ADDR0 P1_0
#define ADDR1 P1_1
#define ADDR2 P1_2
#define ADDR3 P1_3
#define ENLED P1_4

void main() {
  while (1) {
    ENLED = 0;
    ADDR3 = 1;
    ADDR2 = 1;
    ADDR1 = 1;
    ADDR0 = 0;
    LED = 0;
  }
}
```

然后Makefile
```
BUILD_DIR = build/
SRC_DIR= src/
ENTRY=app.c
OUTPUT=app.ihx
PROTOCOL=stc89
DEVICE=/dev/tty.usbserial-14310

build: ${OUTPUT}

flash: build
	stcgal -P ${PROTOCOL} -p ${DEVICE} ${BUILD_DIR}${OUTPUT} 

${OUTPUT}:
	mkdir build && sdcc -o $(BUILD_DIR) ${SRC_DIR}${ENTRY}

clean:
	rm -f ${BUILD_DIR}*
```

齐活
```
make
make flash
```

#EOF