msp430-gcc -Os -mmcu=msp430g2231 -o test.elf test.c
msp430-objdump -DS test.elf > test.lst
msp430-objcopy -O ihex test.elf test.hex

