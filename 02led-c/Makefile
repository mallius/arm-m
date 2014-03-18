all: start.S led.c
	arm-linux-gcc -c -g start.S -o start.o
	arm-linux-gcc -c -g led.c -o led.o
	arm-linux-ld -Ttext=0x00000000  start.o led.o -o start.elf
	arm-linux-objcopy -O binary start.elf start.bin
#cp start.bin /tftpboot
clean:
	rm -rf *.elf *.bin *.o
