/*
 * RTO_interface.h
 *
 *  Created on: Apr 20, 2016
 *      Author: m.mamdooh
 */

#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_
#include "RTO_private.h"
#include "RTO_config.h"

struct TCB
{
	void (*ptr)(void) ;
	TCBT counter;
	TCBT periodicity ;
}TCB_ARR[RTO_u8TASKS_NUM];

void RTO_voidInt(void);
void RTO_voidSchadualar(void);
void RTO_CreateTask(u16 Copy_u16TaskNum,u16 Copy_u16Period,u16 Copy_u16Count, void(*Fun)(void));
void RTO_voidSetTickTime(u32 Copy_u32TickTime);
//void CallBack(void);

#endif /* RTO_INTERFACE_H_ */
