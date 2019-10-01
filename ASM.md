# ASM

之前在Mac上交叉编译51的代码需要用到sdcc, sdcc和gcc类似, gcc中的汇编器采用as, sdcc则是基于ASxxxx, 对应到8051就是sdas8051。

ASxxxx的asm套路和windows下不太一样, 最简单的就是通过sdcc用c来看一下,

app.c
```
__sbit __at(0x90) P1_0;

void main() {
  P1_0 = 0;
  while(1) {}
}
```

拉高P1_0引脚电压，通过sdcc得到的asm, 

app.asm
```
;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.9.0 #11195 (Mac OS X x86_64)
;--------------------------------------------------------
	.module app_02
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _P1_0
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P1_0	=	0x0090
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;	src/app-02.c:3: void main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	src/app-02.c:4: P1_0 = 0;
;	assignBit
	clr	_P1_0
;	src/app-02.c:6: while(1) {}
00102$:
;	src/app-02.c:7: }
	sjmp	00102$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
```

sdcc下文件类型:
```
- sourcefile.asm - Assembler source file created by the compiler
- sourcefile.lst - Assembler listing file created by the Assembler
- sourcefile.rst - Assembler listing file updated with linkedit information, created by linkage editor
- sourcefile.sym - symbol listing for the sourcefile, created by the assembler
- sourcefile.rel - Object file created by the assembler, input to Linkage editor
- sourcefile.map - The memory map for the load module, created by the Linker
- sourcefile.mem - A file with a summary of the memory usage
- sourcefile.ihx - The load module in Intel hex format . Both formats are documented in the documentation of srecord
- sourcefile.adb - An intermediate file containing debug information needed to create the .cdb file (with --debug)
- sourcefile.cdb - An optional file (with --debug) containing debug information. The format is documented in cdbfileformat.pdf
- sourcefile. - (no extension) An optional AOMF or AOMF51 file containing debug information (generated
with option --debug). The (Intel) absolute object module f ormat is a subformat of the OMF51 format and is commonly used by third party tools (debuggers, simulators, emulators).
- sourcefile.dump* - Dump file to debug the compiler it self (generated with option --dumpall)
```

asm到hex的5个步骤:
1. app.asm
2. app.lst
3. app.rel (app.obj)
5. app.ihx (app.hex)

ASxxxx的目标就是从asm生成rel文件，然后通过linker(sdld)将rel生成hex。

到现在我们有了一个大概的全貌:
- sdcc
- sdas8051
- sdld
注: sd: small device


通过sdcc --version可以看到几个步骤的指令,
```
+ /usr/local/bin/sdcpp -nostdinc -Wall -std=c11 -obj-ext=.rel -D__SDCC_CHAR_UNSIGNED -D__SDCC_MODEL_SMALL -D__SDCC_FLOAT_REENT -D__SDCC=3_9_0 -D__SDCC_VERSION_MAJOR=3 -D__SDCC_VERSION_MINOR=9 -D__SDCC_VERSION_PATCH=0 -DSDCC=390 -D__SDCC_REVISION=11195 -D__SDCC_mcs51 -D__STDC_NO_COMPLEX__=1 -D__STDC_NO_THREADS__=1 -D__STDC_NO_ATOMICS__=1 -D__STDC_NO_VLA__=1 -D__STDC_ISO_10646__=201409L -D__STDC_UTF_16__=1 -D__STDC_UTF_32__=1 -isystem /usr/local/bin/../share/sdcc/include/mcs51 -isystem /usr/local/Cellar/sdcc/3.9.0/share/sdcc/include/mcs51 -isystem /usr/local/bin/../share/sdcc/include -isystem /usr/local/Cellar/sdcc/3.9.0/share/sdcc/include  src/app-02.c 
+ /usr/local/bin/sdas8051 -plosgffw build/app-02.rel build/app-02.asm
+ /usr/local/bin/sdld -nf build/app-02.lk
```

app-02.lk是sdcc自动生成的,
```
-muwx
-i build/app-02.ihx
-M
-Y
-b HOME = 0x0000
-b XSEG = 0x0001
-b PSEG = 0x0001
-b ISEG = 0x0000
-b BSEG = 0x0000
-k /usr/local/bin/../share/sdcc/lib/small
-k /usr/local/Cellar/sdcc/3.9.0/share/sdcc/lib/small
-l mcs51
-l libsdcc
-l libint
-l liblong
-l libfloat
build/app-02.rel

-e
```





官方站点:
- [sdcc](http://sdcc.sourceforge.net)
- [ASxxxx](http://shop-pdp.net/ashtml/asxxxx.htm)
