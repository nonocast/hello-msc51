BUILD_DIR = ./
SRC_DIR= ./
ENTRY=app.asm
OUTPUT=app.ihx
PROTOCOL=stc89
DEVICE=/dev/tty.usbserial-14310

build: ${OUTPUT}

flash: build
	stcgal -P ${PROTOCOL} -p ${DEVICE} ${BUILD_DIR}${OUTPUT} 

${OUTPUT}:
	mkdir -p build && sdcc -o $(BUILD_DIR) ${SRC_DIR}${ENTRY}

clean:
	rm -f ${BUILD_DIR}*

.PHONY: all test clean