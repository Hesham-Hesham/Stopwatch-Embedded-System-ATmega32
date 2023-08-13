/*
 * decoder_for_six_sevenSegments.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Hesha
 */

#ifndef DECODER_FOR_SIX_SEVENSEGMENTS_H_
#define DECODER_FOR_SIX_SEVENSEGMENTS_H_

#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DECODER_PORT 					PORTC_ID
#define DECODER_FIRST_PIN 				PIN0_ID


#define SEVEN_SEGMENT_ENABLE_PORT		PORTA_ID
#define SEVEN_SEGMENT_ENABLE_FIRST_PIN 	PIN0_ID



#define COMMON_ANODE 					1
#define COMMON_CATHODE 					0


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description : displays the number of each digit on its respective 7-seg
 *
 */
void DECODER_display_multiplixed_7seg(void);


/*
 * Description : turns off all the six 7segments based on their type
 *
 */
void DECODER_turnOff_allDigits(void);


/*
 * Description : turns off all the six 7segments based on their type
 *
 */
void DECODER_sevSeg_init(void);

#endif /* DECODER_FOR_SIX_SEVENSEGMENTS_H_ */
