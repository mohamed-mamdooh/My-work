/*
 * app.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include "types.h"
#include "utils.h"
#include "DIO_interface.h"
#include "DIO_delay.h"
#include "INTERRUPT_interface.h"

/*DONT FORGETTO CHANGE THE VALUES OF THE ISR REGISTERS TO MAKE IT WORKING
 */

#define PWMPin		0
#define PINOFLED	2
//#define INT0		26
/*Global flag that becomes 1 when the 10 counts pass*/
volatile static u8 INT0_u8Flag=0;

/*ISR of toggling the led after 10 counts on INT0*/
void INT0_voidToggleLed(void) {
	volatile static u8 Counter = 0;
	if (Counter == 10)	//count till the counter comes to 10 then toggle the led
			{
		INT0_u8Flag = 1;
		Counter=0;
	}
	else{Counter++;}

}


void main(void) {
	u8 Local_u8PWDVal = 0;
	u8 Local_u8LEDVal=0;
	DIO_voidInit();
	INT_voidInit();
	Set_INT0_ISR(INT0_voidToggleLed);
	DIO_u8WritePinDir(PINOFLED, 1);

	DIO_u8WritePinDir(PWMPin, 1);
	INT_voidEnGlobalInt();
	while (1)
	{	 Local_u8PWDVal=!Local_u8PWDVal;
		DIO_u8WritePinVal(PWMPin,Local_u8PWDVal);//change value of PWMpin to make it square wave
		if(INT0_u8Flag==1){//if flag ==1 that means 10 counts passed change toggle the led
			Local_u8LEDVal=!Local_u8LEDVal;
			DIO_u8WritePinVal(PINOFLED, Local_u8LEDVal);
			INT0_u8Flag=0;
		}
		else{
		}
		DELAY(100);
	}

}


