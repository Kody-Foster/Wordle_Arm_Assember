	.arch armv7-a
	.text
	.align	2
	.global	getColorCodes
	.syntax unified
	.fpu vfpv3-d16
	.type	getColorCodes, %function
getColorCodes:
	push {r4, r5, fp, lr}
	mov fp, sp
	sub	sp, sp, #44		@ make space for locals
	str	r0, [fp, #-32]	@ store answer address
	str	r1, [fp, #-36]	@ store guess address
	str	r2, [fp, #-40]	@ store colorAray address

	sub	r3, fp, #24
	mov	r2, #0			@ save loop 1 control variable
	str	r2, [r3]
	strb r2, [r3, #4]

	mov r4, #0
	b	loop1			@loop1 begins the scan for Greens
lookForGreen:
	ldr	r2, [fp, #-36]	@ load address of guess
	add r3, r2, r4
	ldrb	r2, [r3]	@ zero_extendqisi2
	ldr	r1, [fp, #-32]	@ load answer address
	add	r3, r1, r4
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r2, r3			@ compare guess[i] and answer[i]
	bne	incLoop1
	lsl r3, r4, #2	
	ldr	r2, [fp, #-40]	@load codeArray address
	add	r3, r2, r3
	mov	r2, #2			
	str	r2, [r3]		@ store 2 in codeArray for Green
	sub	r2, fp, #24		@ load answer flag bool address
	add r3, r2, r4
	mov	r2, #1
	strb	r2, [r3]	@ set answer flag to true
incLoop1:
	add r4, r4, #1
loop1:
	cmp r4, #4			@loop control variable
	ble	lookForGreen

	mov r4, #0
	b	loop2

LookForYellows:
	lsl r3, r4, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	ldr	r3, [r3]
	cmn	r3, #1
	bne	incLoop2

	mov r5, #0
	b	loop3
InnerLoop:
	ldr	r2, [fp, #-36]
	add r3, r2, r4
	ldrb	r2, [r3]	@ zero_extendqisi2
	ldr	r1, [fp, #-32]
	add r3, r1, r5
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r2, r3
	bne	incLoop3
	sub	r2, fp, #24
	add r3, r2, r5
	ldrb	r3, [r3]	@ zero_extendqisi2
	eor	r3, r3, #1
	uxtb	r3, r3
	cmp	r3, #0
	beq	incLoop3
	lsl r3, r4, #2
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	mov	r2, #1
	str	r2, [r3]
	sub	r2, fp, #24
	add r3, r2, r5
	mov	r2, #1
	strb	r2, [r3]
	b	incLoop2
incLoop3:
	add r5, r5, #1
loop3:
	cmp r5, #4
	ble	InnerLoop
incLoop2:
	add r4, r4, #1
loop2:

	cmp r4, #4
	ble	LookForYellows
	add	sp, fp, #0


	pop {r4, r5, fp, pc}
	bx	lr
	.size	getColorCodes, .-getColorCodes
