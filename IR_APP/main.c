/*
 * main.c
 *
 *  Created on: Apr 3, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"


void main (void)
{
	u8 x ;
	DIO_voidInit();
while(1)
{
DIO_u8WritePinVal(24,1);
DIO_u8ReadPinVal(23,&x);
if(x==1)
	DIO_u8WritePinVal(28,1);
else if(x==0)
	DIO_u8WritePinVal(28,0);
}
}
