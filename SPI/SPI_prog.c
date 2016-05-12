/*
 * SPI_prog.c
 *
 *  Created on: Mar 30, 2016
 *      Author: m.mamdooh
 */

#include "type.h"
#include "DIO_utilites.h"
#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"

extern void SPI_voidInit(void)
{
	SPCR =SPI_u8SPCR_INIT ;
	SPSR|=SPI_u8SPSR_INIT ;

return ;
}
extern void SPI_voidResetColgFlag(void)
{
	u8 local_u8SPDRRead ;
	set_bit(SPSR,WCOL);
	local_u8SPDRRead =SPDR ;
	return ;
}
extern void SPI_voidResetIntFlag(void)
{
	u8 local_u8SPDRRead ;
	set_bit(SPSR,SPIF);
	local_u8SPDRRead =SPDR ;
	return ;
}
extern u8 SPI_u8ReadIntFlag(void)
{
    u8 local_u8IntFlag ;
    local_u8IntFlag=get_bit(SPSR,SPIF);
    return local_u8IntFlag ;
}
extern u8 SPI_u8ReadColgFlag(void)
{
	u8 local_u8IColgFlag ;
	local_u8IColgFlag=get_bit(SPSR,WCOL);
	return local_u8IColgFlag ;
}
extern void SPI_u8Transmit(u8 Copy_u8TransVal)
{
	SPDR = Copy_u8TransVal ;
	while(!(SPSR & (SPI_u8HIGH<<SPIF)));
	return ;
}
extern void SPI_u8Receive(u8 *Copy_u8ReceiveVal)
{
	while(!(SPSR & (SPI_u8HIGH<<SPIF)));
	*Copy_u8ReceiveVal = SPDR;
	return ;
}
