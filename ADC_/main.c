/*
 * main.c
 *
 *  Created on: Mar 8, 2016
 *      Author: m.mamdooh
 */

#include"DIO-interface.h"
#include"ADC_interface.h"

void main ()
{
	u16 x ;
	u8 f=1;
	DIO_voidInit();
	ADC_voidInit();
	ADC_voidEnable();
while(1)
{

	ADC_u8ReadCh_SSht(0,&x) ;
	if(f==1)
	{
if(x<220)
{
	DIO_u8WritePinVal(16,1);
f=0;
}
else
{
	DIO_u8WritePinVal(16,0);
}
	}
}
}
