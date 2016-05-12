/*
 * TSW_interface.h
 *
 *  Created on: Feb 11, 2016
 *      Author: m.mamdooh
 */

#ifndef TSW_INTERFACE_H_
#define TSW_INTERFACE_H_


/***************************************************************/
/*************PUBLIC DEFINITIONS*********************************/
/*************************************************************/

/*Comment: number of connected switches*/
#define TSW_u8SW1_IDX 		0
#define TSW_u8SW2_IDX 		1
#define TSW_u8SW3_IDX 		2
#define TSW_u8SW4_IDX 		3
#define TSW_u8SW5_IDX	 	4
#define TSW_u8SW6_IDX 		5
#define TSW_u8SW7_IDX 		6
#define TSW_u8SW8_IDX 		7
#define TSW_u8SW9_IDX 		8
#define TSW_u8SW10_IDX      9
#define TSW_u8SW11_IDX      10
#define TSW_u8SW12_IDX		11
#define TSW_u8SW13_IDX		12
#define TSW_u8SW14_IDX		13
#define TSW_u8SW15_IDX		14
#define TSW_u8SW16_IDX		15



/*comment!: switch mode*/
#define TSW_SINGLE_MODE   0
#define TSW_MULTI_MODE    1



/*Comment!= Switch estate */
#define TSW_u8PRESSED 	1
#define TSW_u8RELEASED	0
#define TSW_BOUNCE 2
/***************************************************************/
/*************PUBLIC FUNCTIONS*********************************/
/*************************************************************/
extern u8 TSW_u8ReadState(u8 Copy_u8SwIdx,u8 * Copy_u8PtrToState);

extern void TSW_voidinit(void);

#endif /* TSW_INTERFACE_H_ */
