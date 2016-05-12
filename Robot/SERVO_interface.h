/*
 * SERVO_interface.h
 *
 *  Created on: May 4, 2016
 *      Author: m.mamdooh
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void SERVO_SetAngle(u8 Copy_u8ServoIdx,u8 Copy_u8Angle);
void SERVO_voidInit(void);
void SERVO_SetMulAngle(void);
u8 SERVO_voidIncDC(u8 Copy_u8Pin , u8 Copy_u8DutyCycle);
u8 SERVO_voidDecDC(u8 Copy_u8Pin , u8 Copy_u8DutyCycle);
#endif /* SERVO_INTERFACE_H_ */
