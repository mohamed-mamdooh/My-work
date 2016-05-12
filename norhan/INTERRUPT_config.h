/*
 * INTERRUPT_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

/*configuration of interrupt sensitivity INT0,INT1 in MCUCR register*/
#define INT_u8ISC11INITVAL		1
#define INT_u8ISC10INITVAL		1
#define INT_u8ISC01INITVAL		1
#define INT_u8ISC00INITVAL		1

/*configuration of interrupt sensitivity INT2 in MCUCSR register rising edge->1 falling edge->0*/
#define INT_u8ISC2INITVAL		1

/*Enabling interrupts or not in GICR 1->enabled,0->disabled*/
#define INT_u8INT1INITVAL		0
#define INT_u8INT0INITVAL		1
#define INT_u8INT2INITVAL		0



#endif /* INTERRUPT_CONFIG_H_ */
