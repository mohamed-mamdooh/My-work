/*
 * test.c
 *
 *  Created on: Dec 31, 2015
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "Delay.h"

#define LEDS DIO_u8PORT2

void DIO_voidBlink1(void);
void DIO_voidBlink2(void);
void DIO_voidBlink3(void);
void DIO_voidBlink4(void);
void DIO_voidBlink5(void);
void DIO_voidBlink6(void);
void DIO_voidBlink7(void);
void DIO_voidBlink8(void);
void DIO_voidBlink9(void);
int main()
{
	DIO_voidInit();
	DIO_u8WritePortDir(LEDS,255);
	DIO_u8WritePortDir(DIO_u8PORT3,255);
	DIO_u8WritePortVal(DIO_u8PORT3,0);
	while(1)
		{
		DIO_voidBlink1();
		DIO_voidBlink2();
		DIO_voidBlink3();
		DIO_voidBlink4();
		DIO_voidBlink5();
		DIO_voidBlink6();
		DIO_voidBlink7();
		DIO_voidBlink8();
		DIO_voidBlink9();


		}
	return 0;
}

void DIO_voidBlink1(void)
{
	u8 Local_u8loopcount=0 ;
			u8 Local_u8LedSeq=1 ;

			for(Local_u8loopcount=0;Local_u8loopcount<8;Local_u8loopcount++)
			{

				DIO_u8WritePortVal(LEDS,Local_u8LedSeq);
				DELAY(0.1);
				Local_u8LedSeq*=2;
			}
}
void DIO_voidBlink2(void)
{
	u8 Local_u8loopcount=0 ;
			u8 Local_u8LedSeq=3 ;

			for(Local_u8loopcount=0;Local_u8loopcount<8;Local_u8loopcount++)
			{

				DIO_u8WritePortVal(LEDS,Local_u8LedSeq);
				DELAY(0.1);
				Local_u8LedSeq*=4;
			}
}
void DIO_voidBlink3(void)
{
	u8 Local_u8loopcount=0 ;
	u8 Local_u8LedSeq=7 ;

				for(Local_u8loopcount=0;Local_u8loopcount<4;Local_u8loopcount++)
				{

					DIO_u8WritePortVal(LEDS,((1<<Local_u8loopcount)+(1<<Local_u8LedSeq)));
					DELAY(0.1);
					Local_u8LedSeq--;
				}
}
void DIO_voidBlink4(void)
{
	u8 Local_u8loopcount=0 ;
	u8 Local_u8LedSeq=3 ;

				for(Local_u8loopcount=4;Local_u8loopcount<8;Local_u8loopcount++)
				{

					DIO_u8WritePortVal(LEDS,((1<<Local_u8loopcount)+(1<<Local_u8LedSeq)));
					DELAY(0.1);
					Local_u8LedSeq--;
				}
}
void DIO_voidBlink5(void)
{
	u8 Local_u8loopcount=0 ;
	u8 Local_u8LedSeq=170 ;

				for(Local_u8loopcount=0;Local_u8loopcount<2;Local_u8loopcount++)
				{

					DIO_u8WritePortVal(LEDS,Local_u8LedSeq);
					DELAY(0.1);
					Local_u8LedSeq=~Local_u8LedSeq;
				}
}
void DIO_voidBlink6(void)
{
	u8 Local_u8loopcount=0 ;
	u8 Local_u8LedSeq=7 ;

				for(Local_u8loopcount=0;Local_u8loopcount<4;Local_u8loopcount+=2)
				{

					DIO_u8WritePortVal(LEDS,((1<<Local_u8loopcount) + (1<<(Local_u8loopcount+1)) + (1<<Local_u8LedSeq) + (1<<Local_u8LedSeq-1)));
					DELAY(0.1);
					Local_u8LedSeq-=2;
				}
}

void DIO_voidBlink7(void)
{
	u8 Local_u8loopcount=0 ;
	u8 Local_u8loopcount1=0 ;
	u8 Local_u8LedSeq=1 ;

				for(Local_u8loopcount=1;Local_u8loopcount<15;)
				{

					DIO_u8WritePortVal(LEDS,Local_u8loopcount);
					DELAY(0.1);
					Local_u8LedSeq*=2;
					Local_u8loopcount+=Local_u8LedSeq;
				}
				Local_u8LedSeq=128 ;

				for(Local_u8loopcount1=1;Local_u8loopcount1<5;Local_u8loopcount1++ )
				{
					Local_u8loopcount+=Local_u8LedSeq;
					DIO_u8WritePortVal(LEDS,Local_u8loopcount);
					DELAY(0.1);
					Local_u8LedSeq/=2;

				}
}

void DIO_voidBlink8(void)
{
	u8 Local_u8loopcount=0 ;
	u8 Local_u8LedSeq=15 ;

				for(Local_u8loopcount=0;Local_u8loopcount<2;Local_u8loopcount++)
				{

					DIO_u8WritePortVal(LEDS,Local_u8LedSeq);
					DELAY(0.1);
					Local_u8LedSeq=~Local_u8LedSeq;
				}
}

void DIO_voidBlink9(void)
{
	u8 Local_u8loopcount=1 ;
	u8 Local_u8loopcount1=0 ;
	u8 Local_u8LedSeq=1 ;

				for(Local_u8loopcount1=1;Local_u8loopcount1<5;Local_u8loopcount1++)
				{

					DIO_u8WritePortVal(LEDS,Local_u8loopcount);
					DELAY(0.1);
					Local_u8LedSeq*=4;
					Local_u8loopcount+=Local_u8LedSeq;
				}
				 Local_u8LedSeq=2 ;
				 Local_u8loopcount+=2 ;
				for(Local_u8loopcount1=1;Local_u8loopcount1<5;Local_u8loopcount1++)
				{

						DIO_u8WritePortVal(LEDS,Local_u8loopcount);
						DELAY(0.1);
						Local_u8LedSeq*=4;
						Local_u8loopcount+=Local_u8LedSeq;
				}
}
