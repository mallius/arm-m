.global _start
_start:
loop:
	ldr	r0,=0x56000010	//GPBCON
	ldr	r1,=0x15400	//GPB5:output
	str	r1,[r0]

	ldr	r0,=0x56000014	//GPBDAT
	mov	r1,#0x1C0	//只有GPB8=0,点亮
	str	r1,[r0]
	
	mov	r3,#8000
	bl 	delay

	mov	r1,#0x1E0	//全灭灯，5号一闪一闪
	//mov	r1,#0x180	//5号6号亮
	str	r1,[r0]
	
	bl	delay

	b loop
delay:
	subs 	r3,r3,#1
	cmp 	r3,#0x0	
	bne 	delay
	mov	pc, lr
