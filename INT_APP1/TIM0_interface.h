/*
 * TIM0_interface.h
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */

#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_


/// TIMSK
#define TOIE0   0
#define OCIE0   1


// TIFR
#define TOV0    0
#define OCF0    1


// TCCR0
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7


//#define TIM0_u8TIME_OVFLW  ((256*TIM0_u8PRESCLER)/FCPU)
void TIM0_voidInit(void);
void TIM0_u8TimerEnabl(void) ;
void TIM0_u8TimerDisabl(void) ;
void TIM0_u8SetTime(u32 Copy_u8TimVal);
void TIM0_voiResetTimer(void);
void TIM0_voiResetTimFlg(void);
u8 TIM0_u8GetTimFlg(void);
void TIM0_voidSetComp(u8 Copy_u8CompVal);

#endif /* TIM0_INTERFACE_H_ */
