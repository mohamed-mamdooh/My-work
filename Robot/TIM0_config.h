/*
 * TIM0_config.h
 *
 *  Created on: Mar 29, 2016
 *      Author: m.mamdooh
 */

#ifndef TIM0_CONFIG_H_
#define TIM0_CONFIG_H_
//TCCR0
//force o/p compare
// range TIM0_u8LOW--> disable  , TIM0_u8HIGH -->  enable
#define TIM0_u8FOC    TIM0_u8LOW


//WAVE form Generation
// Range : TIM0_u8NRMALMODE , TIM0_u8PWMMODE , TIM0_u8CTCMODE , TIM0_u8FPWMMODE
#define TIM0_u8WFG  TIM0_u8NRMALMODE

//compare match o/p mode
// range TIM0_u8LOW  , TIM0_u8HIGH
#define TIM0_u8COMP0  TIM0_u8LOW
#define TIM0_u8COMP1  TIM0_u8LOW
//pre-scaler
// range : TIM0_u8NOPS , TIM0_u8PS_8 , TIM0_u8PS_64  , TIM0_u8PS_256  , TIM0_u8PS_1024
#define TIM0_u8PRESCLER    TIM0_u8NOPS



//TIMSK
//enable / Disable timer overflow interrupt
// range TIM0_u8LOW--> disable  , TIM0_u8HIGH -->  enable
#define TIM0_u8TOEI      TIM0_u8HIGH

//enable / Disable o/p compare interrupt
// range TIM0_u8LOW--> disable  , TIM0_u8HIGH -->  enable
#define TIM0_u8OCEI      TIM0_u8LOW




//cpu frequancy in Khz
#define FCPU  16

#endif /* TIM0_CONFIG_H_ */
