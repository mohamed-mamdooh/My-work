/*
 * main.c
 *
 *  Created on: Apr 20, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "CLCD_interface.h"
#include "UART_interface.h"
#include "TIM0_interface.h"

void main()
{
	DIO_voidInit();
	CLC_voidInit();
	USART_Init();
    TIM0_voidInit();
	while(1)
	{



	}

}

