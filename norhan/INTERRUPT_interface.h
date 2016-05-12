/*
 * INTERRUPT_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef INTERRUPT_INTERFACE_H_
#define INTERRUPT_INTERFACE_H_
/**************************************************************************************************************/
/********************************************public Definitions *************************************************/
/**************************************************************************************************************/
/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5


/* GIFR */
#define INTF1   7
#define INTF0   6
#define INTF2   5

/* MCUCR */
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* MCUCSR */
#define ISC2    6

/**************************************************************************************************************/
/*******************************************functions Definitions *************************************************/
/**************************************************************************************************************/
extern void INT_voidInit(void);

extern  void Set_INT0_ISR(void (*ptr_DIO_ISR) (void));
extern  void Set_INT1_ISR(void (*ptr_DIO_ISR) (void));
extern  void Set_INT2_ISR(void (*ptr_DIO_ISR) (void));

extern void INT_voidEnGlobalInt(void);
extern void INT_voidDisEnGlobalInt(void);
#endif /* INTERRUPT_INTERFACE_H_ */
