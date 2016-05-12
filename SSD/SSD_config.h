/*
 * SSD_config.h
 *
 *  Created on: Feb 3, 2016
 *      Author: m.mamdooh
 */

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_
////////////////////////////////////////////////////////
//////////////////MACROS////////////////////////////////
////////////////////////////////////////////////////////
//comment!: spacific
//range!: common cathode or common anode
#define SSD_u8DISP1LAYTYPE     SSD_u8CATHODE
#define SSD_u8DISP2LAYTYPE     SSD_u8CATHODE
#define SSD_u8DISP3LAYTYPE     SSD_u8CATHODE
#define SSD_u8DISP4LAYTYPE     SSD_u8CATHODE
#define SSD_u8DISP5LAYTYPE     SSD_u8CATHODE
#define SSD_u8DISP6LAYTYPE     SSD_u8CATHODE

//comment!:segment initial Value
//range!: from 0 to 9
#define SSD_u8DISP1_INITVAL   SSD_u8NUM0
#define SSD_u8DISP2_INITVAL   SSD_u8NUM0
#define SSD_u8DISP3_INITVAL   SSD_u8NUM0
#define SSD_u8DISP4_INITVAL   SSD_u8NUM0
#define SSD_u8DISP5_INITVAL   SSD_u8NUM0
#define SSD_u8DISP6_INITVAL   SSD_u8NUM0

//comment!:segment initial state
//range!: on or off
#define SSD_u8DISP1_INITSTATE   SSD_u8ONSTATE
#define SSD_u8DISP2_INITSTATE   SSD_u8ONSTATE
#define SSD_u8DISP3_INITSTATE   SSD_u8ONSTATE
#define SSD_u8DISP4_INITSTATE   SSD_u8ONSTATE
#define SSD_u8DISP5_INITSTATE   SSD_u8ONSTATE
#define SSD_u8DISP6_INITSTATE   SSD_u8ONSTATE


//comment!: display max. index
//range!: 0 to
#define SSD_u8DISPMAXIDX   SSD_u8DISP1
//comment!:segments connected pins
//range!: 0 to 31
#define SSD_u8DISP1COM          DIO_u8PIN8
#define SSD_u8DISP1SEGA         DIO_u8PIN1
#define SSD_u8DISP1SEGB         DIO_u8PIN2
#define SSD_u8DISP1SEGC         DIO_u8PIN3
#define SSD_u8DISP1SEGD         DIO_u8PIN4
#define SSD_u8DISP1SEGE         DIO_u8PIN5
#define SSD_u8DISP1SEGF         DIO_u8PIN6
#define SSD_u8DISP1SEGG         DIO_u8PIN7

#define SSD_u8DISP2COM
#define SSD_u8DISP2SEGA
#define SSD_u8DISP2SEGB
#define SSD_u8DISP2SEGC
#define SSD_u8DISP2SEGD
#define SSD_u8DISP2SEGE
#define SSD_u8DISP2SEGF
#define SSD_u8DISP2SEGG

#define SSD_u8DISP3COM
#define SSD_u8DISP3SEGA
#define SSD_u8DISP3SEGB
#define SSD_u8DISP3SEGC
#define SSD_u8DISP3SEGD
#define SSD_u8DISP3SEGE
#define SSD_u8DISP3SEGF
#define SSD_u8DISP3SEGG

#define SSD_u8DISP4COM
#define SSD_u8DISP4SEGA
#define SSD_u8DISP4SEGB
#define SSD_u8DISP4SEGC
#define SSD_u8DISP4SEGD
#define SSD_u8DISP4SEGE
#define SSD_u8DIS4SEGF
#define SSD_u8DIS4SEGG

#define SSD_u8DISP5COM
#define SSD_u8DISP5SEGA
#define SSD_u8DISP5SEGB
#define SSD_u8DISP5SEGC
#define SSD_u8DISP5SEGD
#define SSD_u8DISP5SEGE
#define SSD_u8DISP5SEGF
#define SSD_u8DISP5SEGG

#define SSD_u8DISP6COM
#define SSD_u8DISP6SEGA
#define SSD_u8DISP6SEGB
#define SSD_u8DISP6SEGC
#define SSD_u8DISP6SEGD
#define SSD_u8DISP6SEGE
#define SSD_u8DISP6SEGF
#define SSD_u8DISP6SEGG





#endif /* SSD_CONFIG_H_ */
