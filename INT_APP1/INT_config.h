/*
 * INT_config.h
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */

#ifndef INT_CONFIG_H_
#define INT_CONFIG_H_
////////////////////////////////////////////////
////////////// MACROS /////////////////////////
//////////////////////////////////////////////

//MCUCR : INT1 ,INT0 sense control
// range : INT_u8LOWLEVEL , INT_u8LOGCHNG , INT_u8FALEDGE , INT_u8RISEDGE
#define INT_u8INT_0_SENSE     INT_u8RISEDGE
#define INT_u8INT_1_SENSE     INT_u8RISEDGE

//MCUCR : INT2 sense control
//range: INT_u8LOW --> FallingEdge , INT_u8HIGH --> RisingEdge
#define INT_u8INT_2_SENSE      INT_u8HIGH


//GICR : ENABLE - DISSABLE EX_INT
// range : INT_u8LOW --> DISABLE , INT_u8HIGH --> ENABLE
#define INT_u8INT_0_EN    INT_u8HIGH
#define INT_u8INT_1_EN    INT_u8LOW
#define INT_u8INT_2_EN    INT_u8LOW

//


#endif /* INT_CONFIG_H_ */
