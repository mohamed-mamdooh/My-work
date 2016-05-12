/*
 * FING_prog.c
 *
 *  Created on: Apr 20, 2016
 *      Author: m.mamdooh
 */
#include "UART_interface.h"
#include "TIM0_interface.h"

void FING_voidInit(void)
{


}

u8  FING_u8HandShake(u8 * Copy_u8ChipAdd)
{
	u8 Local_u8Count ;
	const u8 Local_u8HndShkArr[7]={0x01,0x00,0x04,0x17,0x00,0x00,0x1C};
	u16 Local_u8RxData;

    TIM0_u8SetTime(500);
	while(TIM0_u8GetTimFlg()==0);

	FING_voidSendHeader();

  for(Local_u8Count=3 ; Local_u8Count>=0;Local_u8Count--)
  {
	  USART_Transmit(Copy_u8ChipAdd[Local_u8Count]) ;
  }
  for(Local_u8Count=0;Local_u8Count<7;Local_u8Count++)
  {
	  USART_Transmit(Local_u8HndShkArr[Local_u8Count]);
  }

  for(Local_u8Count=0 ; Local_u8Count<10;Local_u8Count++)
  {
	  USART_Receive(&Local_u8RxData);
  }
  TIM0_voiResetTimFlg();
  TIM0_voiResetTimer();

  return Local_u8RxData ;

}
u8  FING_u8SetAdd(u8 * Copy_u8ChipOldAdd , u8 * Copy_u8ChipNewAdd)
{
	u8 Local_u8Count,Local_u8CastChkSum ;
	const u8 Local_u8HndShkArr[4]={0x01,0x00,0x07,0x15};
	u16 Local_u16RxData ,Local_u16CastChkSum ;
	u64 Local_u64ChekSum=0;
	FING_voidSendHeader();

  for(Local_u8Count=3 ; Local_u8Count>=0;Local_u8Count++)
  	  {
	  USART_Transmit(Copy_u8ChipOldAdd[Local_u8Count]) ;
  	  }
  for(Local_u8Count=0;Local_u8Count<4;Local_u8Count++)
  	  {
	  USART_Transmit(Local_u8HndShkArr[Local_u8Count]);
	  Local_u64ChekSum+=Local_u8HndShkArr[Local_u8Count];
  	  }

  for(Local_u8Count=3 ; Local_u8Count>=0;Local_u8Count++)
   	   {
 	  USART_Transmit(Copy_u8ChipNewAdd[Local_u8Count]);
 	 Local_u64ChekSum+=Copy_u8ChipNewAdd[Local_u8Count];
   	   }
  //Cjeck sum calculations
  Local_u16CastChkSum=(u16)Local_u64ChekSum ;
  Local_u8CastChkSum=(u8)Local_u64ChekSum ;
  USART_Transmit(Local_u8CastChkSum);
  Local_u16CastChkSum>>=8;
  USART_Transmit(Local_u16CastChkSum);


  for(Local_u8Count=0 ; Local_u8Count<10;Local_u8Count++)
  {
	  USART_Receive(&Local_u16RxData);
  }

  return Local_u16RxData ;
}

void FING_voidSendHeader(void)
{
	USART_Transmit(0xEF);
	USART_Transmit(0x01);
	  return ;
}

u8  FING_u8SetSysPra(u8 * Copy_u8ChipAdd,u8 *Copy_u8ParamArr)
{
	u8 Local_u8Count;
	const u8 Local_u8SysPra[6]={0x01,0x00,0x03,0x0f,0x00,0x13};
	u16 Local_u16RxData,Local_u16Param;

	FING_voidSendHeader();

	for(Local_u8Count=3 ; Local_u8Count>=0;Local_u8Count--)
	  {
		  USART_Transmit(Copy_u8ChipAdd[Local_u8Count]) ;
	  }
	for(Local_u8Count=0;Local_u8Count<6;Local_u8Count++)
	  {
		  USART_Transmit(Local_u8SysPra[Local_u8Count]);
	  }
	for(Local_u8Count=0 ; Local_u8Count<10;Local_u8Count++)
	  {
		  USART_Receive(&Local_u16RxData);
	  }
	for(Local_u8Count=0 ; Local_u8Count<16;Local_u8Count++)
		  {
			  USART_Receive(&Local_u16Param);
			  Copy_u8ParamArr[Local_u8Count]=(u8)Local_u16Param ;
		  }
	  return Local_u16RxData ;

}
