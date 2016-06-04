/*
 * main.c
 *
 *  Created on: Mar 7, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "DIO-utilites.h"
#include "Delay.h"

void main (void)
{
	u8 x =0,y=0 ,f=0;
	DIO_voidInit();

	while(1)
	{
	DIO_u8WritePinVal(0,get_bit(x,0));
	DIO_u8WritePinVal(1,get_bit(x,1));
	x++;
	DELAY(10);

	DIO_u8ReadPortVal(0,&y);
	//y&=0xFC ;
	switch(y)
	{
	case 0xAA:
		if(f==0)
		{
		DIO_u8WritePinVal(31,1);
		DELAY(50);
		DIO_u8WritePinVal(31,0);
		f=1 ;
		}
		break ;
	case 0x55:
		if(f==1)
		{
		DIO_u8WritePinVal(31,1);
		DELAY(50);
		DIO_u8WritePinVal(31,0);
		f=2 ;
		}
		break ;
	case 0xF0:
		if(f==2)
		{
		DIO_u8WritePinVal(31,1);
		DELAY(50);
		DIO_u8WritePinVal(31,0);
		f=3 ;
		}
			break ;
	case 0x0F:
		if(f==3)
				{
		DIO_u8WritePinVal(31,1);
		DELAY(50);
		DIO_u8WritePinVal(31,0);
		f=4 ;
				}
			break ;

	}

//	DIO_u8WritePinVal(30,0);
if(x==4)
	x=0;
if(f==4)
{
	DIO_u8WritePinVal(31,1);
}
	}
}
