/**
 * @file project_main.c
 * @author Vignesh
 * @brief 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

#include "user_utils.h"
#include "sample.h"

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void)
{
	/* Configure LED Pin */
	DDRC|=(1<<PC0);
    DDRD&=~(1<<PD0);
    DDRB&=~(1<<PB0);
    PORTD|=(1<<PD0);
    PORTB|=(1<<PB0);
}

/**
 * @brief Changing state of LED
 * 
 * @param state 
 */
void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}

/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 */
int main(void)
{
	/* Initialize Peripherals */
	peripheral_init();

	for(;;)
	{
		if((SW2_PIN&(1<<SW2_PORT))==0)
		{
			if((SW1_PIN&(1<<SW1_PORT))==0)
			{
				change_led_state(LED_ON);
				delay_ms(LED_ON_TIME);
			}
			else
			{
				change_led_state(LED_OFF);
				delay_ms(LED_OFF_TIME);
			}
		}
		else
		{
			change_led_state(LED_OFF);
			delay_ms(LED_OFF_TIME);
		}
	}
	return 0;
}
