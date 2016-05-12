#include "type.h"
#include "TSW_config.h"
#include "TSW_interface.h"
#include "DIO-interface.h"
#include "Delay.h"


#if (TSW_SW_MAXIDX==TSW_u8SW1_IDX)
u8 const TSW_SWtchs[]= { TSW_u8SW1 };

#elif (TSW_SW_MAXIDX==TSW_u8SW2_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2};
#elif (TSW_SW_MAXIDX==TSW_u8SW3_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3};
#elif (TSW_SW_MAXIDX==TSW_u8SW4_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4};
#elif (TSW_SW_MAXIDX==TSW_u8SW5_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5};
#elif (TSW_SW_MAXIDX==TSW_u8SW6_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6};
#elif (TSW_SW_MAXIDX==TSW_u8SW7_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7};
#elif (TSW_SW_MAXIDX==TSW_u8SW8_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8};
#elif (TSW_SW_MAXIDX==TSW_u8SW9_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9};
#elif (TSW_SW_MAXIDX==TSW_u8SW10_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9,TSW_u8SW10};
#elif (TSW_SW_MAXIDX==TSW_u8SW11_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9,TSW_u8SW10,TSW_u8SW11};
#elif (TSW_SW_MAXIDX==TSW_u8SW12_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9,TSW_u8SW10,TSW_u8SW11,TSW_u8SW12};
#elif (TSW_SW_MAXIDX==TSW_u8SW13_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9,TSW_u8SW10,TSW_u8SW11,TSW_u8SW12,TSW_u8SW13};
#elif (TSW_SW_MAXIDX==TSW_u8SW14_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9,TSW_u8SW10,TSW_u8SW11,TSW_u8SW12,TSW_u8SW13,TSW_u8SW14};
#elif (TSW_SW_MAXIDX==TSW_u8SW15_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9,TSW_u8SW10,TSW_u8SW11,TSW_u8SW12,TSW_u8SW13,TSW_u8SW14,TSW_u8SW15};
#elif (TSW_SW_MAXIDX==TSW_u8SW16_IDX)
u8 TSW_SWtchs[]= {TSW_u8SW1,TSW_u8SW2,TSW_u8SW3,TSW_u8SW4,TSW_u8SW5,TSW_u8SW6,TSW_u8SW7,TSW_u8SW8,TSW_u8SW9,TSW_u8SW10,TSW_u8SW11,TSW_u8SW12,TSW_u8SW13,TSW_u8SW14,TSW_u8SW15,TSW_u8SW16};

#endif



static u8 TSW_ButtonState=TSW_u8RELEASED;
u8 const CheckErr[2]={error,ok} ;
static u8 TSW_ButtonVal;
static u8 TSW_laststat;
static u8 TSW_LowCounter;
static u8 TSW_HighCounter;


extern void TSW_voidinit(void)
{

	TSW_ButtonState=TSW_u8RELEASED ;
	TSW_laststat=TSW_u8RELEASED;
	TSW_ButtonVal=TSW_u8RELEASED ;
	TSW_LowCounter=TSW_u8RELEASED ;
	TSW_HighCounter=TSW_u8RELEASED;
}

extern u8 TSW_u8ReadState(u8 Copy_u8SwIdx,u8 * Copy_u8PtrToState)
{
	//u8 local_u8GetButtonStateStatus=ok;
		DIO_u8ReadPinVal(TSW_SWtchs[Copy_u8SwIdx],&TSW_ButtonVal);

		switch  (TSW_ButtonState)
		{
			case TSW_u8RELEASED:
				if(TSW_ButtonVal==1)
					{
					TSW_ButtonState=TSW_BOUNCE;
					TSW_laststat=TSW_u8RELEASED;
					* Copy_u8PtrToState=TSW_laststat;
					}
				else
				{
					*Copy_u8PtrToState=TSW_u8RELEASED;
				}
				break;
			case TSW_u8PRESSED:
				if(TSW_ButtonVal==0)
						{
					TSW_ButtonState=TSW_BOUNCE;
							TSW_laststat=TSW_u8PRESSED;
							* Copy_u8PtrToState=TSW_laststat;
						}
				else
				{
					*Copy_u8PtrToState=TSW_u8PRESSED;
				}
				break;
			case TSW_BOUNCE:
				if(TSW_ButtonVal==1)
				{
					TSW_HighCounter++;
					*Copy_u8PtrToState=TSW_laststat;
				}
				else
				{
					TSW_LowCounter++;
					*Copy_u8PtrToState=TSW_laststat;
				}
				if(TSW_HighCounter==BOUNCETIME)
				{
					TSW_ButtonState=TSW_u8PRESSED;
					TSW_HighCounter=0;
					TSW_LowCounter=0;
					*Copy_u8PtrToState=TSW_u8PRESSED;
				}
				else if (TSW_LowCounter==BOUNCETIME)
				{
					TSW_ButtonState=TSW_u8RELEASED;
					TSW_LowCounter=0;
					TSW_HighCounter=0;
					*Copy_u8PtrToState=TSW_u8RELEASED;
				}
				else
				{

				}

				break;
			default:
				break;
			}

return CheckErr[Copy_u8SwIdx<15];
}

