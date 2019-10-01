DEVICE=/dev/tty.usbserial-14310

biuld: app.ihx

flash: app.ihx
	stcgal -P stc89 -p ${DEVICE} app.ihx

app.ihx: app.rel
	sdld -nf app.lk

app.rel: app.asm
	sdas8051 -plosgffw app.rel app.asm

clean:
	rm *.lst *.rel *.sym *.ihx

.PHONY: all build clean