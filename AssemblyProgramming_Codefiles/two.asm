;Program to turn on the dot LED
;Change the filepath as per your system location

.include "/home/spoken/Assembly/m328Pdef.inc"

;Configure pins 2-7 on Arduino as Output
ldi r16, 0b11111100
out DDRD, r16

; Configure pin 8 on Arduino as Output
ldi r16, 0b00000001
out DDRB, r16

;Writing number 2 on Seven Segment Display
ldi r17, 0b10010000
out PortD, r17
ldi r17, 0b00000000
out PortB, r17

Start:
Rjmp Start

