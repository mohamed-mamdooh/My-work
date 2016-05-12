/*
 * main.c
 *
 *  Created on: Apr 28, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "TIM0_interface.h"
#include "GLOB_INT.h"
#include "SERVO_interface.h"

#define d7 15
#define d6 14
#define d5 13
#define d4 12
#define d3 11
#define d2 10
#define d1 9
#define d0 8
#define c7 7
#define c6 6
#define c5 5
#define c4 4
#define c3 3
#define c2 2
#define c1 1
#define c0 0






int main()
{
	u8 ret[17]={0} ,flag=0;
	DIO_voidInit();
	TIM0_voidInit();
	SERVO_voidInit();
//	DIO_u8WritePortVal(0,1);
	SEI();

	while(1)
	{

     	//SERVO_SetAngle(1,0);

	if(flag<14)
	{
switch(flag)
{
	case 0 :
		ret[flag]=SERVO_voidIncDC(c0,45);
		break;
	case    1:
		ret[flag]=SERVO_voidIncDC(c1,50);
		break;
	case    2:
		ret[flag]=SERVO_voidIncDC(c2,98);
		break;
	case    3:
		ret[flag]=SERVO_voidIncDC(c3,8+0);
		break;
	case    4:
		ret[flag]=SERVO_voidIncDC(c4,45);
		break;

	case    5:
		ret[flag]=SERVO_voidIncDC(c5,50);
		break;

	case    6:
		ret[flag]=SERVO_voidIncDC(c6,80);
		break;

	case    7 :
		ret[flag]=SERVO_voidIncDC(c7,95);
		break;

	case    8:
		ret[flag]=SERVO_voidIncDC(d7,78);
		break;
	case    9:
		ret[flag]=SERVO_voidIncDC(d6,10);
		break;
	case    10:
			ret[flag]=SERVO_voidIncDC(d5,0);
			break;
	case    11:
			ret[flag]=SERVO_voidIncDC(d4,60);
			break;
	case    12:
			ret[flag]=SERVO_voidIncDC(d3,90);
			break;
	case    13:
			ret[flag]=SERVO_voidIncDC(d2,50);
			break;
}
	if(ret[flag]==1)
		flag++;

	}
	else
	{
		SERVO_SetMulAngle();
	}

	}
	return 0;
}



