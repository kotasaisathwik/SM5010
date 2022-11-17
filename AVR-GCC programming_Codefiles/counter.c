// display digits from 0 to 9

#include  <avr/io.h>
#include <util/delay.h>

void sevenseg(int);

int main (void)
{
  DDRD |= 0x3C;
  DDRB |= ((1 << DDB0));
  while(1)
 {
     for(int i = 0; i < 10; i++)
     {
       sevenseg(i);
       _delay_ms (1000L); 
     }
   }
  return 0;
}


void sevenseg(int dec)
{
  switch(dec)
  {
     case 0: 
             PORTB = ((1 << 0));
             PORTD = 0b00000000;
             break;

     case 1: 
             PORTB = ((1 << 0));
             PORTD = 0b00000100;
             break;

     case 2: 
             PORTB = ((0 << 0));
             PORTD = 0b00001000;
             break;

     case 3: 
             PORTB = ((0 << 0));
             PORTD = 0b00001100;
             break;

     case 4: 
             PORTB = ((0 << 0));
             PORTD = 0b00010000;
             break;

     case 5: 
             PORTB = ((0 << 0));
             PORTD = 0b00010100;
             break;

     case 6: 
             PORTB = ((0 << 0));
             PORTD = 0b00011000;
             break;

     case 7: 
             PORTB = ((1 << 0));
             PORTD = 0b00011100;
             break;

     case 8: 
             PORTB = ((0 << 0));
             PORTD = 0b00100000;
             break;

     case 9: 
             PORTB = ((0 << 0));
             PORTD = 0b00100100;
             break;
     default: 
             PORTB = ((1 << 0));
             PORTD = 0b00000000;
             break;

  }
}
