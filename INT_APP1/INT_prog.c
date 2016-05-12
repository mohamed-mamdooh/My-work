/*
 * INT_prog.c
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "INT_config.h"
#include "INT_interface.h"
#include "INT_private.h"
#include "DIO-utilites.h"


void (*INT_u16INT_0_PTR)(void) ;
void (*INT_u16INT_1_PTR)(void) ;
void (*INT_u16INT_2_PTR)(void);

void INT_voidInit(void)
{
	MCUCR |= INT_u8MCUCR_INIT ;
	MCUCSR|=INIT_u8MCUCSR_INIT ;
	GICR|= INT_u8GICR_INIT;

}

u8 INT_u8ReadIntFlag(void)
{
	u8 Local_u8IntType=8 ;

	if(get_bit(GIFR,INTF0))
	{
		assign_bit(Local_u8IntType,0,1)  ;
	}
    if(get_bit(GIFR,INTF1))
	{
		assign_bit(Local_u8IntType,1,1) ;
	}
    if(get_bit(GIFR,INTF2))
	{
    	assign_bit(Local_u8IntType,2,1) ;
	}

	return Local_u8IntType ;
}

/// INT 0
ISR(__vector_1)
{

	INT_u16INT_0_PTR();
}
// INT1
ISR(__vector_2)
{

	INT_u16INT_1_PTR();
}
//INT2
ISR(__vector_3)
{

	INT_u16INT_2_PTR();
}
void CallBackINT0(void (*Copy_PtrToFn)(void))
{
	INT_u16INT_0_PTR=Copy_PtrToFn ;

}
void CallBackINT1(void (*Copy_PtrToFn)(void))
{
	INT_u16INT_1_PTR=Copy_PtrToFn ;
}
void CallBackINT2(void (*Copy_PtrToFn)(void))
{
	INT_u16INT_2_PTR=Copy_PtrToFn ;
}
void SEI(void)
{
	__asm__("SEI") ;
}

void CLI(void)
{
__asm__("CLI") ;
}
