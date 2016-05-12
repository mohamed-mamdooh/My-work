
#include "type.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


void USART_Init( )
{

/* Set baud rate */
UBRRH = (u8)(BAUDRATE>>8); // writing on ubrh fitrst is mandatory because after reading ubrrl it trigers  the controller  to ubdate the baud rate immidiatlly
UBRRL = (u8)BAUDRATE;

UCSRA|=UCSRBA_u8INIT ;

UCSRB = UCSRB_u8INIT ;

UCSRC=(u8)(1<<UMSEL); // switching the register to be UCSRC
UCSRC = UCSRC_u8INIT ;
}


void USART_Transmit( u8 data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );
/* Put data into buffer, sends the data */
UDR = data;
}

u8 USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
/* Get and return received data from buffer */
return UDR;

}
