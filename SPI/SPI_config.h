/*
 * SPI_config.h
 *
 *  Created on: Mar 30, 2016
 *      Author: m.mamdooh
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_
/////////////////////////////////////////////////////
///////////////////// MACROS ////////////////////////
////////////////////////////////////////////////////

//SPCR
// enable inturrept
//range: SPI_u8LOW --> Disable, SPI_u8HIGH --> Enable
#define SPI_u8INTEN_INIT  SPI_u8LOW

// enable inturrept
//range: SPI_u8LOW --> DISABLE , SPI_u8HIGH-->Enable
#define SPI_u8SPIEN_INIT  SPI_u8HIGH

// data order
//range: SPI_u8LOW-->MSB first , SPI_u8HIGH --> LSB first
#define SPI_u8DATAORD_INIT  SPI_u8LOW

// MASTER / SLAVE Select
//range: SPI_u8LOW-->SLAVE  , SPI_u8HIGH --> master
#define SPI_u8MSTRSLAV_INIT  SPI_u8LOW

// Clock polarity
//range: SPI_u8LOW-->LOW on idle LOW , SPI_u8HIGH --> HIGH on idle HIGH
#define SPI_u8CLKPOL_INIT  SPI_u8LOW

// sampling
/*CPHA 0->sample at leading edge 1->sample trailing edge*/
#define SPI_u8CPHA_INIT		SPI_u8LOW

//CLOCK
//Range SPI_u8CLK_2 ,SPI_u8CLK_4 ,SPI_u8CLK_8 ,SPI_u8CLK_16,SPI_u8CLK_32 ,SPI_u8CLK_64 ,SPI_u8CLK_64 , SPI_u8CLK_128
 #define SPI_u8CLK           SPI_u8CLK_2





#endif /* SPI_CONFIG_H_ */
