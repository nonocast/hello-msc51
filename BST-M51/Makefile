BUILD_DIR = build/
SRC_DIR= src/
ENTRY=app-02.c
OUTPUT=app-02.ihx
PROTOCOL=stc89
DEVICE=/dev/tty.usbserial-14310

build: ${OUTPUT}

flash: build
	stcgal --debug -P ${PROTOCOL} -p ${DEVICE} ${BUILD_DIR}${OUTPUT} 

${OUTPUT}:
	mkdir -p build && sdcc -V -o $(BUILD_DIR) ${SRC_DIR}${ENTRY}

clean:
	rm -f ${BUILD_DIR}*

test-compile:
	gcc test/test.c -o build/test

test: test-compile
	./build/test

.PHONY: all test clean