/*
 * Delay.h
 *
 *  Created on: Feb 2, 2016
 *      Author: m.mamdooh
 */

#include "Delay_config.h"
#ifndef DELAY_H_
#define DELAY_H_
//#define DELAY(Copy_u8DelayVal)  do{ \
//							u32 x,y=Copy_u8DelayVal;\
//							 while(y --){x=2600; while(x--);}\
//							} while(0)


//#define DELAY(Copy_u8DelayVal)  do{ \
//							u32 Local_u32Duration;\
//							for(Local_u32Duration=0UL;Local_u32Duration<((Copy_u8DelayVal*DELAY_u32SYSCLOCK)/8000UL);Local_u32Duration ++)\
//							{__asm__("NOP");}} while(0)
//void DELAY (u32 mytime)
//{
//for(u32 i = mytime; i > 0; i--)
//{
//	for(u32 j=4000000/36000;j>0;j--)
//	{
//		__asm("NOP");
//	}
//}
//}


//
#define DELAY(Copy_U64DelayMs)   do{ u32 Local_U32LoopCounter;  u64 Local_U64DelayCounter; \
                                    for( Local_U64DelayCounter = Copy_U64DelayMs/8;  Local_U64DelayCounter > 0;  Local_U64DelayCounter-- ){ \
                                    for ( Local_U32LoopCounter = ((Delay_SysClock * 1)/8);  Local_U32LoopCounter > 0;  Local_U32LoopCounter-- ){ \
                                   __asm__("NOP"); }  \
                                  } \
                                  }while(0)



#endif /* DELAY_H_ */
