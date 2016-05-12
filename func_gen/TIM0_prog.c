/*
 * TIM_prog.c
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "TIM0_config.h"
#include "TIM0_interface.h"
#include "TIM0_private.h"
#include "DIO-utilites.h"

u32 TIM0_OFCOUNT=TIM0_u8LOW ;
u32 TIM0_CMCOUNT=TIM0_u8LOW;
u32 TIM0_u8TIME_OVFLW ;
u32 TIM0_u8TIME_OCOMP ;
u8 TIM0_u8TimeFlag =TIM0_u8LOW ;
void TIM0_voidInit(void)
{
	TCCR0|=TIM0_u8TCCR0INIT;
	TIMSK|=TIM0_u8TIMSKINIT;

	TIM0_u8TIME_OVFLW = ((256*TIM0_u8PRESCLER)/FCPU) ;
	 TIM0_u8TIME_OCOMP = ((OCR0*TIM0_u8PRESCLER)/FCPU);
}


void TIM0_u8SetTime(u32 Copy_u8TimVal)
{

	u32 Local_u8Time;
u8 str[10];
#if(TIM0_u8WFG==TIM0_u8NRMALMODE)
   Local_u8Time= (TIM0_OFCOUNT *TIM0_u8TIME_OVFLW ) ;

   if(Local_u8Time>Copy_u8TimVal)
   {
	   TIM0_u8TimeFlag=TIM0_u8HIGH ;
	}
   else
   {

   }
#elif(TIM0_u8WFG==TIM0_u8CTCMODE)

   Local_u8Time= (TIM0_CMCOUNT *TIM0_u8TIME_OCOMP) ;
  itoa(TIM0_CMCOUNT,str,10);
   CLCD_u8WriteDataStr("St");
   if(Local_u8Time>Copy_u8TimVal)
     {
  	   TIM0_u8TimeFlag=TIM0_u8HIGH ;
     }
     else
     {

     }
#endif
return  ;
}
void TIM0_voiResetTimer(void)
{
	TIM0_OFCOUNT=0 ;
	TIM0_CMCOUNT=0;
}
void TIM0_voiResetTimFlg(void)
{
	TIM0_u8TimeFlag=TIM0_u8LOW ;
}
void TIM0_u8TimerEnabl(void)
{
	TCCR0|=TIM0_u8TCCR0INIT;
}
void TIM0_u8TimerDisabl(void)
{
	TCCR0 &=TIM0_u8STOPTIMER;
}

u8 TIM0_u8GetTimFlg(void)
{
	return TIM0_u8TimeFlag;
}
void TIM0_voidSetComp(u8 Copy_u8CompVal)
{
	OCR0=Copy_u8CompVal;
}

ISR(__vector_11)
{
	 TIM0_OFCOUNT++ ;
}
ISR(__vector_15)
{
	 TIM0_CMCOUNT++ ;
}
