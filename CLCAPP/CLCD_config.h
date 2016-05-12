/*
 * CLCD_config.h
 *
 *  Created on: Mar 9, 2016
 *      Author: m.mamdooh
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/////////////////////////////////////////////
///////////////MACROS///////////////////////
///////////////////////////////////////////

#define CLC_u8D0 	DIO_u8PIN16
#define CLC_u8D1 	DIO_u8PIN17
#define CLC_u8D2 	DIO_u8PIN18
#define CLC_u8D3 	DIO_u8PIN19
#define CLC_u8D4 	DIO_u8PIN20
#define CLC_u8D5 	DIO_u8PIN21
#define CLC_u8D6 	DIO_u8PIN22
#define CLC_u8D7 	DIO_u8PIN23

#define CLC_u8RS 	DIO_u8PIN26
#define CLC_u8RW 	DIO_u8PIN25
#define CLC_u8EN 	DIO_u8PIN24

// comment !: number of used DATA LINES
// range : 8 DL --> HIGH  , 4 DL --> LOW
#define CLC_u8DLNUM  DIO_u8HIGH

// comment !: number of LCD DISPLAYED LINES
// range : 2 DispL --> HIGH  , 1 DispL --> LOW
#define CLC_u8DISPLNUM  DIO_u8HIGH

// comment !: number of dots per char
// range : 5*10 --> HIGH  , 5*7 --> LOW
#define CLC_u8DotsLNUM  DIO_u8HIGH



#define CLC_u8INITSTATE CLC_u8ENABLE



#endif /* CLCD_CONFIG_H_ */
