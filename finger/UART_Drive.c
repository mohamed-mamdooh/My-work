
#include "type.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "DIO_utilites.h"

void USART_Init(void )
{

/* Set baud rate */
	UART_UBRRH = (u8)(BAUDRATE>>8); // writing on ubrh fitrst is mandatory because after reading ubrrl it trigers  the controller  to ubdate the baud rate immidiatlly
	UART_UBRRL = (u8)BAUDRATE;

	UART_UCSRA|=UCSRBA_u8INIT ;

	UART_UCSRB = UCSRB_u8INIT ;

//UCSRC=(u8)(1<<UMSEL); // switching the register to be UCSRC
	UART_UCSRC = UCSRC_u8INIT ;
}


void USART_Transmit( u16 Copy_u8Transdata )
{

/* Wait for empty transmit buffer */
while ( !( UART_UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
#if(UART_u8DATABITS==UART_9_DATABIT)
Copy_u8Transdata&=0x1F ;
UART_UCSRB&=0xFE ;
UART_UCSRB|=(Copy_u8Transdata>>8);
UART_UDR = (u8)(Copy_u8Transdata);
#else
UART_UDR = (u8)Copy_u8Transdata;
#endif

return ;
}

void USART_Receive( u16 *Copy_RecieveData )
{

	u8 Local_u8Read9Bit=0 ;
	*Copy_RecieveData=0 ;
/* Wait for data to be received */
while ( !(UART_UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
#if(UART_u8DATABITS==UART_9_DATABIT)
Local_u8Read9Bit= get_bit(UART_UCSRB,1) ;
*Copy_RecieveData=(Local_u8Read9Bit<<8) ;
*Copy_RecieveData|=(u16)UART_UDR ;
#else
*Copy_RecieveData =UART_UDR ;
#endif
return ;

}


