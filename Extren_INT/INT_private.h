/*
 * INT_private.h
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */

#ifndef INT_PRIVATE_H_
#define INT_PRIVATE_H_

#define MCUCR   *((volatile u8*)(0x55))
#define MCUCSR  *((volatile u8*)(0x54))
#define GICR 	*((volatile u8*)(0x5B))
#define GIFR    *((volatile u8*)(0x5A))


#define INT_u8HIGH    1
#define INT_u8LOW     0

#define INT_u8LOWLEVEL  2
#define INT_u8LOGCHNG   3
#define INT_u8FALEDGE   4
#define INT_u8RISEDGE   5

#if (INT_u8INT_1_SENSE==INT_u8LOWLEVEL)
#define INT_u8ISC10    0
#define INT_u8ISC11    0
#elif (INT_u8INT_1_SENSE==INT_u8LOGCHNG)
#define INT_u8ISC10    1
#define INT_u8ISC11    0
#elif (INT_u8INT_1_SENSE==INT_u8FALEDGE)
#define INT_u8ISC10    0
#define INT_u8ISC11    1
#elif (INT_u8INT_1_SENSE==INT_u8RISEDGE)
#define INT_u8ISC10    1
#define INT_u8ISC11    1
#endif

#if (INIT_u8INT_0_SENSE==INT_u8LOWLEVEL)
#define INT_u8ISC00    0
#define INT_u8ISC01    0
#elif (INT_u8INT_0_SENSE==INT_u8LOGCHNG)
#define INT_u8ISC00    1
#define INT_u8ISC01    0
#elif (INT_u8INT_0_SENSE==INT_u8FALEDGE)
#define INT_u8ISC00    0
#define INT_u8ISC01    1
#elif (INT_u8INT_0_SENSE==INT_u8RISEDGE)
#define INT_u8ISC00    1
#define INT_u8ISC01    1
#endif



#define conc(x0,x1,x2,x3,x4,x5,x6,x7)     conchelper(x0,x1,x2,x3,x4,x5,x6,x7)
#define conchelper(x0,x1,x2,x3,x4,x5,x6,x7) 0b##x7##x6##x5##x4##x3##x2##x1##x0

#define INT_u8GICR_INIT  conc(0,0,0,0,0,INT_u8INT_2_EN,INT_u8INT_0_EN,INT_u8INT_1_EN)
#define INT_u8MCUCRR_INIT conc(INT_u8ISC00 ,INT_u8ISC01 ,INT_u8ISC10 ,INT_u8ISC11,0,0,0,0)
#define INIT_u8MCUCSR_INIT conc(0,0,0,0,0,0,INT_u8INT_2_SENSE,0)


#endif /* INT_PRIVATE_H_ */
