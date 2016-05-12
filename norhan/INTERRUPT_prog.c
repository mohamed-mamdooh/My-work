/*
 * INTERRUPT_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#include "types.h"
#include "INTERRUPT_config.h"
#include "INTERRUPT_private.h"
#include "INTERRUPT_interface.h"
void (*ptr_INT0_ISR) (void);
void (*ptr_INT1_ISR) (void);
void (*ptr_INT2_ISR) (void);
/*initialize registers of interrupts*/
 void INT_voidInit(void){
	 /*select sensitivity of the int0 and 1*/
	 INTERRUPT_u8MCUCR |= (INT_u8ISC11INITVAL<<ISC11) | (INT_u8ISC10INITVAL<<ISC10) | (INT_u8ISC01INITVAL<<ISC01) | (INT_u8ISC00INITVAL<<ISC00);
	/*select sensitivity of int2*/
	 INTERRUPT_u8MCUCSR |= (INT_u8ISC2INITVAL<< ISC2);
	 /*enable interrupts or not*/
	 INTERRUPT_u8GICR  |= (INT_u8INT1INITVAL<<INT1) | (INT_u8INT0INITVAL<<INT0) | (INT_u8INT2INITVAL<<INT2);
 }
 /*INT0 assigning the ptr to ISR and calling it*/

 void Set_INT0_ISR(void (*ptr) (void)){
	 ptr_INT0_ISR=ptr;
 }

 ISR(INT0_vect){
	ptr_INT0_ISR;
}
/*INT1 assigning the ptr to ISR and calling it*/

void Set_INT1_ISR(void (*ptr) (void)){
	 ptr_INT1_ISR=ptr;
}

ISR(INT1_vect){
	ptr_INT1_ISR;
}
/*INT2 assigning the ptr to ISR and calling it*/
void Set_INT2_ISR(void (*ptr) (void)){
	 ptr_INT2_ISR=ptr;
}

ISR(INT2_vect){
	ptr_INT2_ISR;
}
void INT_voidEnGlobalInt(void)
{
__asm__("SEI");
}

void INT_voidDisEnGlobalInt(void)
{
__asm__("CLI");
}
