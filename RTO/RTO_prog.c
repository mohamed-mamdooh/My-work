/*
 * RTO_prog.c
 *
 *  Created on: Apr 20, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "RTO_private.h"
#include "RTO_config.h"
#include "RTO_interface.h"
#include "TIM0_interface.h"


void CallBack(void)
{
	u8 local_u8LoopCount ;
		for(local_u8LoopCount=0 ; local_u8LoopCount<RTO_u8TASKS_NUM ;local_u8LoopCount++)
		{
			TCB_ARR[local_u8LoopCount].counter--;
						if(TCB_ARR[local_u8LoopCount].counter==0)
						{
							TCB_ARR[local_u8LoopCount].counter=TCB_ARR[local_u8LoopCount].periodicity;
						}
		}
		RTO_voidSchadualar();
}

void RTO_voidInt(void)
{
	TIM0_voidSetter(CallBack);
	TIM0_voidInit();
	RTO_voidSchadualar();
}

void RTO_voidSetTickTime(u32 Copy_u32TickTime)
{
	TIM0_voidSetTick(Copy_u32TickTime);
	//TIM0_u8SetTime(Copy_u32TickTime);
}


void RTO_voidSchadualar(void)
{
	u8 local_u8LoopCount ;
	for(local_u8LoopCount=0 ; local_u8LoopCount<RTO_u8TASKS_NUM ;local_u8LoopCount++)
		{
			if(TCB_ARR[local_u8LoopCount].counter==1)
				{
					TCB_ARR[local_u8LoopCount].ptr();
				}
		}
}

void RTO_CreateTask(u16 Copy_u16TaskNum,u16 Copy_u16Period , u16 Copy_u16Count ,  void(*Fun)(void) )
{
	TCB_ARR[Copy_u16TaskNum].counter= Copy_u16Count ;
	TCB_ARR[Copy_u16TaskNum].periodicity=Copy_u16Period;
	TCB_ARR[Copy_u16TaskNum].ptr=Fun ;
}
