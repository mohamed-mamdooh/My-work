/*
 * main.c
 *
 *  Created on: Mar 22, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "UART_interface.h"
#include "DIO-interface.h"
#include "Delay.h"

u8 Tx[10]="M" ,Rx[10];

void receive(void);
void main (void)
{
	DIO_voidInit();
	USART_Init();

	while(1)
	{
		receive();
	}
}



void receive(void)
{
	Rx[1]=USART_Receive() ;

	//DELAY(100);
	if(Rx[1]=='M')
	{
	USART_Transmit(Tx[0]);
	//CLCD_u8WriteDataChar(Rx[0]);
	}
}
