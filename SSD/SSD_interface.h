/*
 * SSD_interfaace.h
 *
 *  Created on: Feb 3, 2016
 *      Author: m.mamdooh
 */


////////////////////////////////////////////////////////
//////////////////MACROS////////////////////////////////
////////////////////////////////////////////////////////
#ifndef SSD_INTERFAACE_H_
#define SSD_INTERFAACE_H_

#define SSD_u8NUM0     0
#define SSD_u8NUM1     1
#define SSD_u8NUM2     2
#define SSD_u8NUM3     3
#define SSD_u8NUM4     4
#define SSD_u8NUM5     5
#define SSD_u8NUM6     6
#define SSD_u8NUM7     7
#define SSD_u8NUM8     8
#define SSD_u8NUM9     9


#define SSD_u8DISP1 0
#define SSD_u8DISP2 1
#define SSD_u8DISP3 2
#define SSD_u8DISP4 3
#define SSD_u8DISP5 4
#define SSD_u8DISP6 5

#define SSD_u8ANODE   0
#define SSD_u8CATHODE 1

#if (SSD_u8CATHODE)
#define SSD_u8ONSTATE  0
#define SSD_u8OFFSTATE 1

#else
#define SSD_u8ONSTATE  1
#define SSD_u8OFFSTATE 0

#endif

////////////////////////////////////////////////////////
//////////////////PROTOTYPES////////////////////////////
////////////////////////////////////////////////////////


extern u8 SSD_u8Display(u8 Copy_u8DispIdx,u8 Copy_u8DisVal);
extern u8 SSD_u8GetVal(u8 Copy_u8DispIdx,u8* Copy_u8DisVal);
extern u8 SSD_u8TurnOn(u8 Copy_u8DispIdx);
extern u8 SSD_u8TurnOff(u8 Copy_u8DispIdx);
extern void SSD_voidInit(void) ;
#endif /* SSD_INTERFAACE_H_ */
