/*
 * main.c
 *
 *  Created on: Apr 10, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include  "DIO-interface.h"
#include "ADC_interface.h"
#include "TIM0_interface.h"
#include "GLOB_INT.h"



void main (void)
{
	u16 ADC_read ;
	u8 tog ;
   DIO_voidInit();
   ADC_voidInit();
   TIM0_voidInit();
   ADC_voidEnable();
   SEI();

   while(1)
   {
	   ADC_u8ReadCh_SSht(0,&ADC_read);
	   TIM0_u8SetTime(ADC_read);
	   if(TIM0_u8GetTimFlg()==1)
	   {
		   tog^=1;
          DIO_u8WritePinVal(28,tog);
          TIM0_voiResetTimer();
          TIM0_voiResetTimFlg();
	   }
   }

}
