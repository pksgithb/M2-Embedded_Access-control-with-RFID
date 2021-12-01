all:
        avr-gcc -Wall -g -Os -mmcu=atmega328 -o test.bin main code.c calculate hours.c calculate minutes.c calculate seconds.c initadc.c read adc.c write display.c finalcode.c
function.h main.c
exec: all
        avr-objcopy -j .text -j .data -os ihex test.bin test.hex
clean:
        rm -rf test.hex
