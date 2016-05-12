/*
 * TSW_config.h
 *
 *  Created on: Feb 11, 2016
 *      Author: m.mamdooh
 */

#ifndef TSW_CONFIG_H_
#define TSW_CONFIG_H_
/*Comment: SW  MODE */
/*Range! :TSW_SINGLE_MODE or TSW_MULTI_MODE*/





/*Comment: max switch index*/
/*range: 1 to 24*/
#define TSW_SW_MAXIDX    TSW_u8SW1_IDX
/*Comment: SWitches */
/*Range! :from DIO_u8PIN0 to DIO_u8PIN31*/
#define TSW_u8SW1 		DIO_u8PIN8
#define TSW_u8SW2
#define TSW_u8SW3
#define TSW_u8SW4
#define TSW_u8SW5
#define TSW_u8SW6
#define TSW_u8SW7
#define TSW_u8SW8
#define TSW_u8SW9
#define TSW_u8SW10
#define TSW_u8SW11
#define TSW_u8SW12
#define TSW_u8SW13
#define TSW_u8SW14
#define TSW_u8SW15
#define TSW_u8SW16

#define BOUNCETIME		10
#endif /* TSW_CONFIG_H_ */
