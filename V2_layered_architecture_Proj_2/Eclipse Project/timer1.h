/*
 * timer1.h
 *
 *  Created on: Apr 30, 2023
 *      Author: Hesha
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"


/*******************************************************************************
 *                              Shared Variables	                           *
 *******************************************************************************/
extern uint8 counters[6]; //their representation in the 6 7-segs  _5_  _4_ | _3_  _2_ | _1_ _0_


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void TIMER1_init(void);


#endif /* TIMER1_H_ */
