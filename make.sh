#	
#	Author: Kevin Henderson
#	Email: umhendek@gmail.com
#	Date: 12-28-12
#

msp430-gcc -Os -mmcu=msp430g2231 -o test.elf test.c
msp430-objdump -DS test.elf > test.lst
msp430-objcopy -O ihex test.elf test.hex

