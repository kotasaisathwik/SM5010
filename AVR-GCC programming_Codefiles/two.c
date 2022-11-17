// display digit 2

#include  <avr/io.h>
#include <util/delay.h>

int main (void)
{
  DDRD |= 0xFC;
  DDRB |= ((1 << DDB0));
 
 while(1)
  {
     PORTB = ((0 << PB0));
     PORTD = 0b10010000;
  }
  return 0;
}
