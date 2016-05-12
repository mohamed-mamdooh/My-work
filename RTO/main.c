/*
 * main.c
 *
 *  Created on: Apr 20, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "TIM0_interface.h"
#include "RTO_interface.h"
#include "DIO-interface.h"
#include "GLOB_INT.h"

u8 tog1=0 ,one_count=0 ,zero_count=0 ,flag=0 ,Tick=50,tog2=1;
u32 time=0 ;
	u8 str[10];
void APP_voidTask1 (void);
void APP_voidTask2 (void);
void APP_voidTask3 (void);
void main (void)
{
	DIO_voidInit();
	RTO_CreateTask(0,1 , 3 ,APP_voidTask2);
	//RTO_CreateTask(1,6 , 4 ,APP_voidTask3);
  //  RTO_CreateTask(1,1000 , 1 ,APP_voidTask3);

	RTO_voidInt();

	RTO_voidSetTickTime(50);
	SEI();

	while(1)
	{

	}


}
void APP_voidTask1 (void)
{
	//time++;
//u8 x ;
//	DIO_u8ReadPinVal(7,&x);
//	if(x==0)
//	{
//		zero_count++;
//      //flag=1;
//		DIO_u8WritePinVal(24,1);
//	}
	//else
	{
		one_count++;
		flag=2;
	}

	if(flag==2)
	{
		time=zero_count+one_count ;
		time*=Tick ;
//		time=1/time ;
		zero_count=0 ;
		one_count=0 ;
		flag=0;
	}



}
void APP_voidTask2 (void)
{
//	tog2^=1;
//	DIO_u8WritePinVal(1,1);
//	u8 x ;
//		DIO_u8ReadPinVal(31,&x);
//		if(x==1)
//		{
//			zero_count++;
//	      //flag=1;
//			DIO_u8WritePinVal(24,1);
//		}
tog1^=1;
	DIO_u8WritePinVal(3,tog1);
}
void APP_voidTask3 (void)
{
//	itoa(time,str,10);
//tog1^=1;
	DIO_u8WritePinVal(3,0);
}
