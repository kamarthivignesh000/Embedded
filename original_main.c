
#include <avr/io.h>
int main(void)
{

    DDRC|=(1<<PC0);
    DDRD&=~(1<<PD0);
    DDRB&=~(1<<PB0);
    PORTD|=(1<<PD0);
    PORTB|=(1<<PB0);

    while(1)
    {

        if((PIND&(1<<PD0))==0)
        {
            if((PINB&(1<<PB0))==0)
            {
                PORTC|=(1<<PC0);
            }
            else
            {
                PORTC&=~(1<<PC0);
            }
        }
        else
        {
            PORTC&=~(1<<PC0);
        }
    }
    return 0;
}
