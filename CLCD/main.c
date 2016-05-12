/*
 * main.c
 *
 *  Created on: Mar 9, 2016
 *      Author: m.mamdooh
 */
#include "DIO-interface.h"
#include "CLCD_interface.h"
#include "Delay.h"
#include "CLCD_private.h"
void main ()
{
	u16 x=5 ;
	u8 str[8];
	DIO_voidInit();
	CLC_voidInit();
	__asm__("SEI");
	u8 i ;
	u8 c[] ="MAMDOOH" ;
	u8 ML[]={0x1f,0x09,0x09,0x09,0x09,0x0f,0x00,0x00};
	u8 DL[]={0x00,0x01,0x01,0x01,0x1f,0x00,0x00,0x00};
	u8 OL[]={0x1f,0x11,0x11,0x1f,0x01,0x1f,0x00,0x00};
	u8 HL[]={0x1f,0x01,0x0f,0x08,0x08,0x08,0x0f,0x00};
	while(1)
	{
		//CLCD_u8WriteComand(CLC_u8CLRDISP);
		CLCD_u8WriteDataStr("LIFT");
		CLCD_u8WriteComand(CLC_u8NEWL);
		//itoa((255-x),str,10);
		//CLCD_u8WriteDataStr(str);
		//CLCD_u8WriteComand(CLC_u8STL);

//		CLCD_u8WriteOnCGRam(HL,0);
//		CLCD_u8WriteOnCGRam(OL,1);
//		CLCD_u8WriteOnCGRam(DL,2);
//		CLCD_u8WriteOnCGRam(ML,3);
//		CLCD_u8WriteOnCGRam(ML,4);
//
//		CLCD_u8WriteComand(CLC_u8STL);
//for(i=0;i<6;i++)
//		CLCD_u8WriteDataChar(i);


	//CLCD_u8WriteComand(0x18);
	//CLCD_u8WriteComand(0x1C);
//	while(1);
	}
}
