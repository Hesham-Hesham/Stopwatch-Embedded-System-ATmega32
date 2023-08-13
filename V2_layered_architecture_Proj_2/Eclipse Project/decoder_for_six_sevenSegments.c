/*
 * six_sevenSegments.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Hesha
 */

#include <util/delay.h>

#include "gpio.h"
#include "std_types.h"
#include "decoder_for_six_sevenSegments.h"
#include "timer1.h"


/*******************************************************************************
 *                         Static Functions Prototypes                           *
 *******************************************************************************/

static void DECODER_writeOn_single_sevSeg(uint8 num);




void DECODER_sevSeg_init(void){

	//4 pins for decoder
	GPIO_setupPinDirection(DECODER_PORT, PIN0_ID+0, PIN_OUTPUT);
	GPIO_setupPinDirection(DECODER_PORT, PIN0_ID+1, PIN_OUTPUT);
	GPIO_setupPinDirection(DECODER_PORT, PIN0_ID+2, PIN_OUTPUT);
	GPIO_setupPinDirection(DECODER_PORT, PIN0_ID+3, PIN_OUTPUT);
	//the equivalent is
//	DDRC |= 0x0F; //4 pins for decoder

	//0,1,2,3,4,5 of portA are output
	GPIO_setupPinDirection(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+0, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+1, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+2, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+3, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+4, PIN_OUTPUT);
	GPIO_setupPinDirection(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+5, PIN_OUTPUT);
	//the equivalent is
//	DDRA |= 0xC0; //0,1,2,3,4,5 of portA are output

	DECODER_turnOff_allDigits();
}
/*
 * Description : takes the selected number and outputs it on the seven segment
 *
 */
static void DECODER_writeOn_single_sevSeg(uint8 num){ //decoder is connected to first 4 bits of C (0,1,2,3)

	uint8 decoder_pins= (1<<DECODER_FIRST_PIN) | (1<< (DECODER_FIRST_PIN+1) )\
						| (1<< (DECODER_FIRST_PIN+2) ) | (1<< (DECODER_FIRST_PIN+3) );

	GPIO_writePort(PORTC_ID,( (num & decoder_pins) | ( GPIO_readPort(PORTC_ID) & ~decoder_pins ) ) );

	//the equivalent bit insertion is
//		PORTC = (num&0x0F) |(PORTC&0xF0);
}


/*
 * Description :
 *
 */
void DECODER_display_multiplixed_7seg(void){

	uint8 i=0;

	for(i=0;i<6;i++){
		GPIO_writePin(PORTA_ID, i, LOGIC_HIGH);		//7-seg number (i) is on

		DECODER_writeOn_single_sevSeg(counters[i]);	//display the number (i) on 7-seg number (i)

		_delay_ms(1);
		DECODER_turnOff_allDigits();
	}

}



/*
 * Description :	disables all the six seven segments based on their type
 *
 */
void DECODER_turnOff_allDigits(void){
	//common anode		vcc-->on 	GND---->off
	//common cathode 	vcc-->off 	GND---->on

#if		COMMON_CATHODE
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+0, LOGIC_HIGH);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+1, LOGIC_HIGH);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+2, LOGIC_HIGH);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+3, LOGIC_HIGH);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+4, LOGIC_HIGH);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+5, LOGIC_HIGH);

#elif 	COMMON_ANODE
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+0, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+1, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+2, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+3, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+4, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+5, LOGIC_LOW);

	//the equivalent is
//	PORTA &= 0xC0;		// 0,1,2,3,4,5 of portA = 0 -----> all six 7-segs off

#else //default is common anode
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+0, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+1, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+2, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+3, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+4, LOGIC_LOW);
	GPIO_writePin(SEVEN_SEGMENT_ENABLE_PORT, SEVEN_SEGMENT_ENABLE_FIRST_PIN+5, LOGIC_LOW);

#endif

}
