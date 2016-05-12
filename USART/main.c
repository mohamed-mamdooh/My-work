/*
 * main.c
 *
 *  Created on: Mar 22, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "UART_interface.h"
#include "DIO-interface.h"
#include "CLCD_interface.h"
#include "Delay.h"

u8 Tx[10]="M" ,Rx[10];
void trans(void);
void receive(void);
void main (void)
{
	DIO_voidInit();
	CLC_voidInit();
	USART_Init();

	while(1)
	{
		trans();
	}
}

void trans(void)
{
	USART_Transmit(Tx[0]);
	DELAY(100);
//	Rx[0]=USART_Receive() ;
	CLCD_u8WriteDataChar(Rx[0]);
}

void receive(void)
{
	//Rx[1]=USART_Receive() ;

	//DELAY(100);
	if(Rx[1]=='M')
	{
	USART_Transmit(Tx[0]);
	//CLCD_u8WriteDataChar(Rx[0]);
	}
}
