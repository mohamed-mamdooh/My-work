/*
 * INTERRUPT_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef INTERRUPT_PRIVATE_H_
#define INTERRUPT_PRIVATE_H_

#define INTERRUPT_u8MCUCR *((volatile u8*)(0x55))
#define INTERRUPT_u8MCUCSR *((volatile u8*)(0x54))
#define INTERRUPT_u8GIFR *((volatile u8*)(0x5A))
#define INTERRUPT_u8GICR *((volatile u8*)(0x5B))
#define INTERRUPT_u8SREG *((volatile u8*)(0x5F))

//this the prototype of the isr
#define ISR(vector)\
	void vector (void) __attribute__((signal,used,externally_visible));\
	void vector (void)//the function itself
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3

 ISR(INT0_vect);
 ISR(INT1_vect);
 ISR(INT2_vect);

#endif /* INTERRUPT_PRIVATE_H_ */
