;Change the filepath as per your system location

.include "/home/spoken/Assembly/m328Pdef.inc"

;Configure pin 13 on Arduino as Output

ldi r16, 0b00100000
out DDRB, r16

; Making pin 13 LOW
ldi r17, 0b00000000
out PortB, r17

Start:
Rjmp Start
