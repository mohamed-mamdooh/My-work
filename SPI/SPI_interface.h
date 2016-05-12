/*
 * SPI_interface.h
 *
 *  Created on: Mar 30, 2016
 *      Author: m.mamdooh
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
//////////////////////////////////////
/////////// MACRO ///////////////////
////////////////////////////////////
#define SPI_u8LOW   0
#define SPI_u8HIGH  1

///////////////////////////////////
////////// APIs //////////////////
/////////////////////////////////
extern void SPI_u8Transmit(u8 Copy_u8TransVal) ;
extern void SPI_u8Receive(u8 *Copy_u8ReceiveVal) ;
extern u8 SPI_u8ReadIntFlag(void);
extern u8 SPI_u8ReadColgFlag(void);
extern void SPI_voidResetIntFlag(void);
extern void SPI_voidResetColgFlag(void);
extern void SPI_voidInit(void) ;



#endif /* SPI_INTERFACE_H_ */
