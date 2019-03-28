#include <stdbool.h>

#include "LPC13xx.h"
#include "delay.h"
#include "leddriver.h"

#define PRESCALE (72000-1) //72000 PCLK clock cycles to increment TC by 1 


/*
static bool but1_pressed (void) {
	uint32_t pin_data = (~LPC_GPIO2->DATA & 0x200) >> 9;

	if (pin_data) return true;
	if (pin_data) return false;

	return 0;
}

int main (void)
{
	init_leds();
	init_delay();

	while (1) {
		//set_leds(1);
		//delay_ms(500);
		//set_leds(0);
		delay_ms(1);

		if (but1_pressed()) {
			set_led(1, 0);
			delay_ms(25);

			while (but1_pressed()) {}
			delay_ms(25);
		}
		set_led(1, 0);


		/
	}
}
*/


void initTimer0(void)
{
	/*Assuming CCLK (System Clock) = 72Mhz (set by startup code)*/
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9); //Enable 32Bit Timer0 Clock
	LPC_TMR32B0->CTCR = 0x0;
	LPC_TMR32B0->PR = PRESCALE; //Increment LPC_TMR32B0->TC at every 71999+1 clock cycles
	//72000 clock cycles @72Mhz = 1 mS
	LPC_TMR32B0->TCR = 0x02; //Reset Timer
}


int main (void) {
	initTimer0(); //Initialize Timer0
	LPC_GPIO1->DIR = (1<<6); //Configure PIO1_6 as output

	LPC_TMR32B0->TCR = 0x02; //Reset Timer
	LPC_TMR32B0->TCR = 0x01; //Enable timer

	while(1)
	{
		LPC_GPIO1->DATA = (1<<6); //Turn PIN ON

		while(LPC_TMR32B0->TC < 8); //wait until timer counter reaches the desired delay

		LPC_TMR32B0->TCR = 0x02; //Reset Timer
		LPC_TMR32B0->TCR = 0x01; //Enable timer

		LPC_GPIO1->DATA = ~(1<<6); //Turn OFF LED

		while(LPC_TMR32B0->TC < 2); //wait until timer counter reaches the desired delay

		LPC_TMR32B0->TCR = 0x02; //Reset Timer
		LPC_TMR32B0->TCR = 0x01; //Enable timer
	}
}

//int main (void) {
//
//	LPC_GPIO1->DIR = (1<<6); //Configure PIO1_6 as output
//	
//	/*Assuming CCLK (System Clock) = 72Mhz (set by startup code)*/
//	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9); //Enable 32Bit Timer0 Clock
//	LPC_TMR32B0->CTCR = 0x0;
//	LPC_TMR32B0->PR = PRESCALE; //Increment LPC_TMR32B0->TC at every 71999+1 clock cycles
//	//72000 clock cycles @72Mhz = 1 mS
//
//	LPC_TMR32B0->TCR = 0x02; //Reset Timer
//
//	LPC_TMR32B0->MR0 = 1;
//	LPC_TMR32B0->MR1 = 9;
//	LPC_TMR32B0->MCR |= (1<<4) | (1<<3) | (1<<0);
//
//	LPC_TMR32B0->TCR = 0x01; //Enable timer
//
//	NVIC_EnableIRQ(TIMER_32_0_IRQn);
//
//	while(1) {
//		__WFI();
//	}
//}
//
//
//void TIMER_32_0_Handler (void) {
//
//	if (LPC_TMR32B0->IR & 0x01) {
//		LPC_GPIO1->DATA = (1<<6); //Turn PIN ON
//		LPC_TMR32B0->IR = 0x01; // Reset int
//	} else if (LPC_TMR32B0->IR & 0x02) {
//		LPC_GPIO1->DATA = ~(1<<6); //Turn PIN OFF
//		LPC_TMR32B0->IR = 0x02; // Reset int
//	}
//
//
//
//}