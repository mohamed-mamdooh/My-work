/*
 * DIO_delay.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef DIO_DELAY_H_
#define DIO_DELAY_H_
#include "DIO_delay_config.h"
#define DELAY(NumberOfMsec) do{\
for(u32 Local_u32Counter=NumberOfMsec*DIO_u32CLKSPEED/4000000;Local_u32Counter>0;Local_u32Counter--)\
{__asm__("NOP");\
	}\
}while(0)
#endif /* DIO_DELAY_H_ */
