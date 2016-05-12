/*
 * main.c

 *
 *  Created on: Feb 26, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "KPD_interface.h"
#include "Delay.h"
#include "DIO-utilites.h"
void call() ;
void main (void)
{
	u8 x=1 ;

	DIO_voidInit();
	KPD_voidInit();

	while(1)
	{


		KPD_u8Read(&x) ;


		switch(x)
	{
	case 4 :
		DIO_u8WritePinVal(8,1);
           break ;
	}


	}

}
void call()
{
	int x=4000 ;
	while(--x)
		{

		}
}
