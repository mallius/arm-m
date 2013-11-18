all:
	arm-linux-gcc -c led.S
	arm-linux-ld -Ttext=0x00000000 -o led.elf led.o	#mini2440,开启后从0地址执行程序
	arm-linux-objcopy -O binary led.elf led.bin
#cp led.bin /tftpboot
clean:
	rm -rf *.elf *.bin *.o
