/*
 * main.c
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "KPD_interface.h"
#include "CLCD_interface.h"
#include "INT_interface.h"
#include "TIM0_interface.h"
#include "Delay.h"
#define LED1_PIN 28
#define LED2_PIN 29
#define LED3_PIN 30

volatile u8 tog1 =0 , tog2=0 , tog3=0 ,FLAG1=0 ,FLAG2=0 ,FLAG3=0;
u32 TIMER_READ  ;
void LED1_ON (void);
void LED2_ON (void);
void LED3_ON (void) ;
void light();
int main ()
{
	u8 KPD_READ ;

	DIO_voidInit();
	CLC_voidInit();
	KPD_voidInit();
	INT_voidInit();
	TIM0_voidInit();
	SEI();
while(1)
{

	KPD_u8Read(&KPD_READ);
	//itoa(x,str,10);
 //    DIO_u8ReadPinVal(SW_PIN,&SW_READ);

	if(KPD_READ ==1 )
     {
		CallBackINT0(LED3_ON);
     }
     else if(KPD_READ ==5)
     {
    	CallBackINT0(LED2_ON);
     }
     else if(KPD_READ ==9 )
	 {
		CallBackINT0(LED1_ON);

	 }

	light();
}
return 0;

}
void LED1_ON (void)
{
	FLAG1^=1 ;

	tog1=0 ;
	tog2=0 ;
	tog3=0 ;
}


void LED2_ON (void)
{

	FLAG2^=1 ;

	tog1=0 ;
	tog2=0 ;
	tog3=0 ;
}
void LED3_ON (void)
{
	FLAG3^=1 ;

	tog1=0 ;
	tog2=0 ;
	tog3=0 ;
}

void light()
{
	TIM0_u8SetTime(1000);
	if(TIM0_u8GetTimFlg()==1)
	{
		if(FLAG1==1)
			tog1^=1 ;
		if(FLAG2==1)
			tog2^=1 ;
		if(FLAG3==1)
		    tog3^=1 ;

		DIO_u8WritePinVal(LED1_PIN ,tog1) ;
		DIO_u8WritePinVal(LED2_PIN ,tog2) ;
		DIO_u8WritePinVal(LED3_PIN ,tog3) ;
		TIM0_voiResetTimFlg();
		TIM0_voiResetTimer();
	}
}
