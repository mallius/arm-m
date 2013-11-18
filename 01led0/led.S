.global _start
_start:
	ldr	r0,=0x56000010	//GPBCON
	ldr	r1,=0x15400	//GPB5:output
	str	r1,[r0]

	ldr	r0,=0x56000014	//GPBDAT
	mov	r1,#0x1C0	//只有GPB8=0,点亮
	str	r1,[r0]

halt:
	b halt
