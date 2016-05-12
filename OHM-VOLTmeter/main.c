/*
 * main.c
 *
 *  Created on: Mar 17, 2016
 *      Author: m.mamdooh
 */
#include "type.h"
#include "DIO-interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "TSW_interface.h"
#include "Delay.h"

u16 Adc_Read  ,Adc_ReadV;
u8 str[5],strV[5],SW_Read ,count=0 , f=0;
f32 volt ,ResVal;
u16 SensRead=0 , old_SensRead=1 ;
void ohmeter(void);
void voltmeter(void);
void Tempsensor (void) ;
int main(void)
{

	DIO_voidInit();
	ADC_voidInit();
	CLC_voidInit();
	ADC_voidEnable();
	while(1)
	{
		//voltmeter();
		//ohmeter();
		Tempsensor ();
	}
return 0 ;
}
void voltmeter(void)
{
	ADC_u8ReadCh_SSht(0,&Adc_ReadV);
    volt=Adc_ReadV*0.005;
    volt*=2.4;
	itoa((u8)volt,strV,10) ;
	CLCD_u8WriteDataStr(strV);
	CLCD_u8WriteComand(CLC_u8STL);
}
void ohmeter(void)
{
	   DIO_u8ReadPinVal(24,&SW_Read);

			if(SW_Read==1&&f==0)
			{
				count++ ;
				if(count==3)
					count=0 ;

			       CLCD_u8WriteComand(CLC_u8CLRDISP );
			       f=1 ;
			}

			else if(SW_Read==0)
				{
					f=0 ;
				}
			else
			{

			}
			switch(count)
			{
			case 0 :
				ADC_u8ReadCh_SSht(0,&Adc_Read);
				ResVal=  (0.005 *(Adc_Read))*100 / (5-(0.005 *(Adc_Read))) ;
				CLCD_u8WriteDataStr("Range= 100 ohm");
				break ;
			case 1 :
				ADC_u8ReadCh_SSht(0,&Adc_Read);
				ResVal=  (0.005 *(Adc_Read))*1000 / (5-(0.005 *(Adc_Read))) ;
				CLCD_u8WriteDataStr("Range= 1K ohm");
				break ;
			case 2 :
				ADC_u8ReadCh_SSht(0,&Adc_Read);
				ResVal=  (0.005 *(Adc_Read))*10000 / (5-(0.005 *(Adc_Read))) ;
				CLCD_u8WriteDataStr("Range= 10K ohm");
				break ;


			default:
				break ;
			}

			itoa((u16) ResVal,str,10) ;
			CLCD_u8WriteComand(CLC_u8NEWL);
			CLCD_u8WriteDataStr("RES=");
			CLCD_u8WriteDataStr(str);
	        CLCD_u8WriteComand(CLC_u8STL);
}
void Tempsensor (void)
{


 //TSEN_u8ReadTSensr(0,&SensRead);

	ADC_u8ReadCh_SSht(0,&SensRead);
if(SensRead != old_SensRead)
 {
	 CLCD_u8WriteComand(CLC_u8CLRDISP );
	 CLCD_u8WriteComand(CLC_u8STL);
	 volt=SensRead*0.005;
	 itoa( SensRead,str,10)  ;
	 CLCD_u8WriteDataStr("TEMP= ");
	 CLCD_u8WriteDataStr(str);
	 old_SensRead = SensRead ;
 }
}
