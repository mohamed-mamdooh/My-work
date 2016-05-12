/*
 * main.c
 *
 *  Created on: Apr 10, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "TIM0_interface.h"
#include "CLCD_interface.h"
#include "GLOB_INT.h"

void main (void)
{
	u8 tog=0 ,test ,flag=0 ,x ;

	DIO_voidInit();
	TIM0_voidInit();
	//CLC_voidInit();

   SEI();

while(1)
{
	//TIM0_voidSetComp(50);
	if(flag==0)
	TIM0_u8SetTime(100);
	else
		TIM0_u8SetTime(10);

	test=TIM0_u8GetTimFlg() ;

  if(test==1)
	{
		tog^=1 ;

		TIM0_voiResetTimFlg();
		TIM0_voiResetTimer();
		flag^=1;
	}
////  DIO_u8WritePinVal(7,1);
////  if(x==1)
//	  DIO_u8WritePinVal(28,1);
//	  DIO_u8WritePinVal(28,0);
}
}
