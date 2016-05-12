/*
 * INT_interface.h
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */

#ifndef INT_INTERFACE_H_
#define INT_INTERFACE_H_

//MCUCSR
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

//MCUCR
#define ISC2    6

//GICR
#define INT1   7
#define INT0   6
#define INT2   5

// GIFR
#define INTF2   5
#define INTF0   6
#define INTF1   7



//////////////////////////////////////////////////
/////////////// APIs ////////////////////////////
////////////////////////////////////////////////

#define ISR(vector) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) ;\
		void vector(void)

void INT_voidInit(void);
void CallBackINT0(void (* Copy_PtrToFn)(void));
void CallBackINT1(void (* Copy_PtrToFn)(void));
void CallBackINT2(void (* Copy_PtrToFn)(void));
void SEI(void);
void CEI(void);


#endif /* INT_INTERFACE_H_ */
