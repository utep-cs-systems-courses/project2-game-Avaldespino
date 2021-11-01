	.arch msp430g2553

	.p2align 1,0

	.text

	.extern red
	.extern green
	.extern buzzer
	.extern buzzer_set_period
	
	
	.global stateOne
stateOne:
	Mov #0, &green
	Mov #1, &red
	Mov buzzer, r12
	Call buzzer_set_period
	pop r0
	
	

	
