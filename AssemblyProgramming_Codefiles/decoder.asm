;Change the filepath as per your system location

.include "/home/my-pc/Downloads/AssemblyProgramming_Codefiles/m328Pdef.inc"

;Configure pins 2,3,4 and 5 on Arduino as Output
ldi r16, 0b00111100
out DDRD, r16
ldi r17, 0b00000101 ;the last 3 bits define the prescaler, 101 => division by 1024
out TCCR0B, r17 
;prescalar used = 1024. So new freq. of clock cycle = (16 MHz / 1024) = 16 kHz

clr r18 ;output bits. we are only interested in bit 6 from the right.

ldi r20,0b00100000	;initializing

;Writing number 5 on Seven Segment Display
Start:
ldi r16, 0b00000000
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00000100
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00001000
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00001100
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00010000
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00010100
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00011000
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00011100
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00100000
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

ldi r16, 0b00100100
out PORTD, r16
ldi r19, 0b01000000 ;times to run the loop = 64 for 1 second delay
	rcall PAUSE 

Rjmp Start

PAUSE:	;this is delay (function)
lp2:	;loop runs 64 times
		IN r17, TIFR0 ;tifr is timer interupt flag (8 bit timer runs 256 times)
		ldi r20, 0b00000010
		AND r17, r20 ;need second bit
		BREQ PAUSE 
		OUT TIFR0, r20	;set tifr flag high
	dec r19
	brne lp2
	ret

;prescalar * loop_iterations * timer_duration =~ 16 million cycles
;16 million cycles at 16 MHz = 1 second


