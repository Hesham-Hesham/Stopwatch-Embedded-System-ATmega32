/*
 * external_interrupt.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Hesha
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "external_interrupt.h"
#include "std_types.h"
#include "timer1.h"
#include "common_macros.h"

/*
 * Description : enable external interrupt 0 with falling edge triggering
 *
 */
void EXTERNAL_INTERRUPT_int0_init(void){

	CLEAR_BIT(DDRD,2);		//input
	SET_BIT(PORTD,2);		//internal pullup
	SET_BIT(MCUCR,ISC01);	//falling edge
	SET_BIT(GICR,INT0);		//external interrupt enable
	SET_BIT(SREG,7);   	//general interrupt enable

}


/*
 * Description : enable external interrupt 1 with rising edge triggering
 *
 */
void EXTERNAL_INTERRUPT_int1_init(void){

	CLEAR_BIT(DDRD,3);		//input
	SET_BIT(MCUCR,ISC11);	//rising edge
	SET_BIT(MCUCR,ISC10);	//rising edge

	SET_BIT(GICR,INT1);		//external interrupt enable
	SET_BIT(SREG,7);   	//general interrupt enable
}


/*
 * Description : enable external interrupt 2 with falling edge triggering
 *
 */
void EXTERNAL_INTERRUPT_int2_init(void){

	CLEAR_BIT(DDRB,2);		//input
	SET_BIT(PORTB,2);		//internal pullup
	//ISC2 in MCUCSR -->0	//falling edge
	SET_BIT(GICR,INT2);		//external interrupt enable
	SET_BIT(SREG,7);   	//general interrupt enable

}



ISR(INT0_vect){
	//reset stopwatch

	uint8 i=0;
	for(i=0;i<6;i++){				//loop through all the digits
		counters[i]=0;				//reset all digits
	}
	TCNT1  |= 0;					//reset current ticks
}

ISR(INT1_vect){
	//pause stopwatch
	CLEAR_BIT(TIMSK,OCIE1A);		//t1 interrupt disable
//	TIMSK  &= ~(1<<OCIE1A);			//t1 interrupt disable
}

ISR(INT2_vect){
	//resume stopwatch
//	TIMSK  |= (1<<OCIE1A);			//t1 interrupt enable
	SET_BIT(TIMSK,OCIE1A);		//t1 interrupt enable
	TCNT1  |= 0;					//reset current ticks

}

