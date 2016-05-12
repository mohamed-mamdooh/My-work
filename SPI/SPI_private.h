/*
 * SPI_private.h
 *
 *  Created on: Mar 30, 2016
 *      Author: m.mamdooh
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPCR *((volatile u8*)(0x2D))
#define SPSR *((volatile u8*)(0x2E))
#define SPDR *((volatile u8*)(0x2F))

#define SPI_u8CLK_4     4
#define SPI_u8CLK_16    16
#define SPI_u8CLK_64    64
#define SPI_u8CLK_128   128
#define SPI_u8CLK_2     2
#define SPI_u8CLK_8     8
#define SPI_u8CLK_32    32

#if (SPI_u8CLK == SPI_u8CLK_4)
#define SPR0_IINT       SPI_u8LOW
#define SPR1_IINT       SPI_u8LOW
#define SPRI2x_IINT     SPI_u8LOW
#elif (SPI_u8CLK == SPI_u8CLK_16)
#define SPR0_IINT       SPI_u8HIGH
#define SPR1_IINT       SPI_u8LOW
#define SPRI2x_IINT     SPI_u8LOW
#elif (SPI_u8CLK == SPI_u8CLK_64)
#define SPR0_IINT       SPI_u8LOW
#define SPR1_IINT       SPI_u8HIGH
#define SPRI2x_IINT     SPI_u8LOW
#elif (SPI_u8CLK == SPI_u8CLK_128)
#define SPR0_IINT       SPI_u8HIGH
#define SPR1_IINT       SPI_u8HIGH
#define SPRI2x_IINT     SPI_u8LOW
#elif (SPI_u8CLK == SPI_u8CLK_2)
#define SPR0_IINT       SPI_u8LOW
#define SPR1_IINT       SPI_u8LOW
#define SPRI2x_IINT     SPI_u8HIGH
#elif (SPI_u8CLK == SPI_u8CLK_8)
#define SPR0_IINT       SPI_u8LOW
#define SPR1_IINT       SPI_u8LOW
#define SPRI2x_IINT     SPI_u8HIGH
#elif (SPI_u8CLK == SPI_u8CLK_32)
#define SPR0_IINT       SPI_u8LOW
#define SPR1_IINT       SPI_u8HIGH
#define SPRI2x_IINT     SPI_u8HIGH
#endif


#define conc(x0,x1,x2,x3,x4,x5,x6,x7)     conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define conchelper(x0,x1,x2,x3,x4,x5,x6,x7) 0b##x7##x6##x5##x4##x3##x2##x1##x0

#define SPI_u8SPCR_INIT  conc(SPR0_IINT,SPR1_IINT,SPI_u8CPHA_INIT,SPI_u8CLKPOL_INIT,SPI_u8MSTRSLAV_INIT,SPI_u8DATAORD_INIT,SPI_u8SPIEN_INIT,SPI_u8INTEN_INIT)
#define SPI_u8SPSR_INIT  conc(SPRI2x_IINT,0,0,0,0,0,0,0)

//SPCR
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7


//SPSR
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#endif /* SPI_PRIVATE_H_ */
