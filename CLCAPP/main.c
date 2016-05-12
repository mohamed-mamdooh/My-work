/*
 * main.c
 *
 *  Created on: Mar 9, 2016
 *      Author: m.mamdooh
 */
#include "DIO-interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "TSW_interface.h"
#include "DIO_utilites.h"

#define st1 31
#define st2 28
#define st3 30
#define st4 29

u8 m=1 ,flg=0,f=0;
u16 ADCREAD=0 , c=0 , count=0 ;
 u8 old_ADC,flag1=0 ;

 void step() ;
void ADC_conv();
void Write_LCD();
void Read_sw(void);
void write_name();
void main ()
{

	DIO_voidInit();
	CLC_voidInit();
	TSW_voidinit() ;
	ADC_voidInit();
	ADC_voidEnable();


	while(1)
	{

		Read_sw();
	}
}

void ADC_conv()
{

	ADC_u8ReadCh_SSht(0 , &ADCREAD);

	//	if(ADCREAD!=old_ADC)
	//		old_ADC=ADCREAD ;

	if(ADCREAD-old_ADC > 5 && flag1==0)
	{
	old_ADC=ADCREAD ;
	Write_LCD();
	}

	//else
	//{
	if(ADCREAD<=132 && ADCREAD>124)
	{
		flg=2 ;
	}
	else if (ADCREAD>132)
	{
		count+=(old_ADC);
		if(count>1500)
		{

			step();
			count=ADCREAD	;
		}
		flg=0 ;

	}
	else if (ADCREAD<=124)
	{
		c+=((255-old_ADC)) ;
		if(c>1500)
		{
			step();
			c=ADCREAD	;
		}
		flg=1 ;
	}
	//}
}
void step()
{
	if (flg==0)
{
	DIO_u8WritePinVal(st1,get_bit(m,0));
	DIO_u8WritePinVal(st2,get_bit(m,1));
	DIO_u8WritePinVal(st3,get_bit(m,2));
	DIO_u8WritePinVal(st4,get_bit(m,3));
}
	else
{
		DIO_u8WritePinVal(st4,get_bit(m,0));
		DIO_u8WritePinVal(st3,get_bit(m,1));
		DIO_u8WritePinVal(st2,get_bit(m,2));
		DIO_u8WritePinVal(st1,get_bit(m,3));
}

	m<<=1 ;
	if(m==16)
		m=1 ;
}
void Write_LCD(void)
{
	u8 str[8];
	switch (flg)
	{
	case 0:
		CLCD_u8WriteComand(CLC_u8CLRDISP);
		CLCD_u8WriteDataStr("RIGHT");
		CLCD_u8WriteComand(CLC_u8NEWL);
		itoa((ADCREAD),str,10);
		CLCD_u8WriteDataStr(str);
		CLCD_u8WriteComand(CLC_u8STL);
		break ;
	case 1:
		CLCD_u8WriteComand(CLC_u8CLRDISP);
		CLCD_u8WriteDataStr("LEFT ");
		CLCD_u8WriteComand(CLC_u8NEWL);
		itoa(((256-ADCREAD)),str,10);
		CLCD_u8WriteDataStr(str);
		CLCD_u8WriteComand(CLC_u8STL);
		break ;
	case 2:
		CLCD_u8WriteComand(CLC_u8CLRDISP);
		CLCD_u8WriteDataStr("STOP ");
		CLCD_u8WriteComand(CLC_u8NEWL);
		CLCD_u8WriteDataStr("000");
		CLCD_u8WriteComand(CLC_u8STL);
		break ;
	case 3 :

		break ;
	default :
		break ;
	}

}
void Read_sw(void)
{
	u8 READsw  ;
	TSW_u8ReadState(0,&READsw);
	if(READsw==1)
	{
		if(f==0)
		{
		f=1 ;
		flag1=1 ;

		old_ADC=0;
		if(ADCREAD<10)
			old_ADC=20;

		write_name();
		}
		ADC_conv();
	}
	else
	{
		if(f==1)
		{
			flag1=0 ;
		f=0 ;
		}
		ADC_conv();

	}

}
void write_name()
{
	u8 ML[]={0x1f,0x09,0x09,0x09,0x09,0x0f,0x00,0x00};
	u8 DL[]={0x00,0x01,0x01,0x01,0x1f,0x00,0x00,0x00};
	u8 OL[]={0x1f,0x11,0x11,0x1f,0x01,0x1f,0x00,0x00};
	u8 HL[]={0x1f,0x01,0x0f,0x08,0x08,0x08,0x0f,0x00};
	u8 i ;

	CLCD_u8WriteComand(CLC_u8CLRDISP);
	CLCD_u8WriteOnCGRam(HL,0);
	CLCD_u8WriteOnCGRam(OL,1);
	CLCD_u8WriteOnCGRam(DL,2);
	CLCD_u8WriteOnCGRam(ML,3);
	CLCD_u8WriteOnCGRam(ML,4);

	CLCD_u8WriteComand(CLC_u8STL);

	for(i=0;i<5;i++)
		CLCD_u8WriteDataChar(i);

	CLCD_u8WriteComand(CLC_u8NEWL);
	CLCD_u8WriteDataStr("   ");
	CLCD_u8WriteComand(CLC_u8STL);
}
