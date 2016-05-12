/*
 * SERVO_prog.c
 *
 *  Created on: May 4, 2016
 *      Author: m.mamdooh
 */
#include "DIO-interface.h"
#include "TIM0_interface.h"
#include "TIM0_private.h"
#include "DIO-utilites.h"
u8 volatile flag=0,state=0,idx=0,indx=0;
u16 const SERVO_Angle_HIGH[19]={0,78,156,233,311,389,466,544,622,700,778,855,933,1011,1089,1166,1244,1322,1400};
u8 PIN_NUM;
//u8 MUL_arr[100]={127,127,127,127,127,127,127,127,127,127,63,63,63,63,63,63,63,63,63,63,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,15,15,15,15,15,15,15,15,15,15,7,7,7,7,7,7,7,7,7,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
static u8 Duty_Cycle[17]={0};
u8 MUL_arr1[100]={0};
u8 MUL_arr2[100]={0};
void func(void)
{

	flag=idx;
	//DIO_u8WritePinVal(PIN_NUM,state);

	*((volatile u8*)(0x32))=state;
	*((volatile u8*)(0x35))=state;
	TCNT0=0;
}

void SERVO_SetAngle(u8 Copy_u8ServoNums,u8 Copy_u8Angle)
{
	u8 Local_u8Map=	(Copy_u8Angle/10);
	PIN_NUM=Copy_u8ServoNums;
			if(flag==0&&idx==0)
			{
				TIM0_voidSetTick(17800);
				state=1;
				idx=1;
			}
			else if(flag==1&&idx==1)
			{
				TIM0_voidSetTick(800);
				state=1;
				idx=2;
			}
			else if (flag==2&&idx==2)
			{
				TIM0_voidSetTick(SERVO_Angle_HIGH[Local_u8Map]); // high
				state=0;
				idx=3;
			}
			else if (flag==3&&idx==3)
			{
				TIM0_voidSetTick(1000-SERVO_Angle_HIGH[Local_u8Map]);//low
				state=0;
				idx=0;
			}
}


void SERVO_SetMulAngle(void)
{

			if(flag==0&&idx==0)
			{
				TIM0_voidSetTick(17800);
				idx=1;
				state=0xff;
			}
			else if(flag==1&&idx==1)
			{
				TIM0_voidSetTick(800);
				idx=2;
				//state=0;
			}
			else if (flag==2&&idx==2)
			{
				if(TCNT0>120)
				{
					*((volatile u8*)(0x32))= MUL_arr2[indx];
					*((volatile u8*)(0x35))=MUL_arr1[indx];
						indx++;
						if(indx==99)
						{
							indx=0;
							idx=0;
							flag=0;
						}
						TCNT0=0;
				}
			}

}

void SERVO_voidInit(void)
{
	TIM0_voidSetter(func);
}

u8 SERVO_voidIncDC(u8 Copy_u8Pin , u8 Copy_u8DutyCycle)
{
u8 Local_u8Return=0 ;
if(Copy_u8Pin<8)
{
	if(Duty_Cycle[Copy_u8Pin] < Copy_u8DutyCycle)
	{
		set_bit(MUL_arr1[Duty_Cycle[Copy_u8Pin]],Copy_u8Pin);
		Duty_Cycle[Copy_u8Pin]++;
	}
	else
	{
		Local_u8Return=1;
	}
}
else
{
	if(Duty_Cycle[Copy_u8Pin] < Copy_u8DutyCycle)
		{
			set_bit(MUL_arr2[Duty_Cycle[Copy_u8Pin]],(Copy_u8Pin-8));
			Duty_Cycle[Copy_u8Pin]++;
		}
		else
		{
			Local_u8Return=1;
		}
}


	return Local_u8Return;
}

u8 SERVO_voidDecDC(u8 Copy_u8Pin , u8 Copy_u8DutyCycle)
{

	u8 Local_u8Return=0 ;
	if(Copy_u8Pin<8)
	{
		if(Duty_Cycle[Copy_u8Pin] > Copy_u8DutyCycle)
		{
			Duty_Cycle[Copy_u8Pin]--;
		clr_bit(MUL_arr1[Duty_Cycle[Copy_u8Pin]],Copy_u8Pin);
		}
		else
		{
			Local_u8Return=1;
		}
	}
	else
	{
		if(Duty_Cycle[Copy_u8Pin] > Copy_u8DutyCycle)
			{
				Duty_Cycle[Copy_u8Pin]--;
				clr_bit(MUL_arr1[Duty_Cycle[Copy_u8Pin]],(Copy_u8Pin-8));
			}
			else
			{
				Local_u8Return=1;
			}
	}
	return Local_u8Return;
}

