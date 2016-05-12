#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define UART_BAUD_RATE 2400

#include "mirf.h"

uint8_t txrxrole = 0; // 1 transmitter 0 receiver

#define buffersize mirf_PAYLOAD
uint8_t buffer[buffersize];

uint8_t rxaddr[5] = {0x01, 0x02, 0x03, 0x04, 0x05};
uint8_t txaddr[5] = {0x01, 0x02, 0x03, 0x04, 0x05};

#define BUTTONROLE PC0
#define ROLETX 1
#define ROLERX 0
#define BUTTONSEND PC1
#define LEDOUT PC5
#define LEDOUTPAUSE 300

//main here
int main(void)
{
	mirf_init();
	_delay_ms(50);

	DDRC &= ~(1<<BUTTONROLE) | ~(1<<BUTTONSEND); // 1111 1110 | 1111 1101
	DDRC |= (1<<LEDOUT);
	PORTC &= ~(1<<LEDOUT);

	//uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );

	sei();

	mirf_config();

	mirf_set_rxaddr(0, rxaddr);
	mirf_set_txaddr(txaddr);

	if ((PINC & (1<<BUTTONROLE)) == 0)
		txrxrole = ROLERX;
	else
		txrxrole = ROLETX;

	if(txrxrole == ROLETX) {
		PORTC |= (1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
		PORTC &= ~(1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
	} else if(txrxrole == ROLERX) {
		PORTC |= (1 << LEDOUT); _delay_ms(LEDOUTPAUSE);
		PORTC &= ~(1 << LEDOUT); _delay_ms(LEDOUTPAUSE);
		PORTC |= (1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
		PORTC &= ~(1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
	}

	for(int i=0; i<buffersize; i++)
		if(txrxrole == 1)
			buffer[i] = i+10;
		else
			buffer[i] = 0;

	while(1) {
		if(txrxrole == ROLETX)
		{
			if ((PINC & (1<<BUTTONSEND)) != 0)
			{
				mirf_write(buffer);

				PORTC |= (1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
				PORTC &= ~(1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
			}
		}
		else if(txrxrole == ROLERX)
		{
			if(mirf_read_ready())
			{
		//		uart_putc(mirf_get_status());
				mirf_read(buffer);
//				for(int i=0; i<buffersize; i++)
//					uart_putc(buffer[i]);

				PORTC |= (1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
				PORTC &= ~(1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
				PORTC |= (1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
				PORTC &= ~(1<<LEDOUT); _delay_ms(LEDOUTPAUSE);
			}
		}
	}
}




