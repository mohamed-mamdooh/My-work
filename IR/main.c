#include <avr/io.h>
#include <avr/interrupt.h>
#include "type.h"
#include "DIO-interface.h"
#include "TIM0_interface.h"
#include "INT_interface.h"
//u8 flag = 0xff;
//static u32 counter = 0;

void main()
    {

  //  u32 TimeRead;
    //u8 counter = 0;

    DIO_voidInit();
    INT_voidInit();
    TIM0_voidInit();
    DDRA = 0xff;
//    DDRD=0xff;
//    DDRC=0;
//    PORTD=0;
    PORTA = 0xff;

    /*Comment!: set up timer with no prescaler and CTC mode*/

    TCCR1B |= (1 << WGM12) | (1 << CS10);

    /*Comment!: initialize counter*/
    TCNT1 = 0;

    /*Comment!: set compare value*/
    OCR1A = 4000 / 80;

    /*Comment!: enable compare interrupt*/
    TIMSK |= (1 << OCIE1A);

    /*Comment!: enable global interrupt*/
    sei();

    while (1)
	{


	}

    return;
    }

ISR (TIMER1_COMPA_vect)
    {

//    counter++;
    /*Comment!: disable global interrupt*/

//cli();
    /*Comment!: toggle pin*/

	PORTA = ~PORTA;
	//PORTA = 0;



    /*Comment!: enable global interrupt*/
    // sei();
    }

