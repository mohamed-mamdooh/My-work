/*
 * main.c
 *
 *  Created on: Feb 3, 2016
 *      Author: m.mamdooh
 */


#include "DIO-interface.h"
#include "Delay.h"
#include "TSW_interface.h"
#define latch 19
#define ds 18
#define clk 17

void Write_H(void) ;
void Write_O(void) ;
void Write_D(void) ;
void Write_A(void) ;
void Write_M(void) ;

void cols(u8 *PIN_NUM);
void rows(u8 *PIN_NUM);

void main (void)
{
 u8 x ;
	DIO_voidInit();

	u8 cola_H[]={1,1,1,1,1,1,1,1};
		u8 rowa_H[]={1,1,1,1,1,1,1,1};
		DIO_u8WritePinDir(17,1);
			DIO_u8WritePinDir(16,0);
    while(1)
    {


//    	Write_M() ;
//	Write_A() ;
//    	Write_M() ;
//    	Write_D() ;
//     	Write_O() ;
//        Write_H() ;

    	TSW_u8ReadState(0,&x);
if(x==1)
{
	DIO_u8WritePinVal(17,1);

}
else
{
	DIO_u8WritePinVal(17,0);

}
    	    }

}

void Write_M(void)
{
	////////////M//////////////////////
		u8 cola_M[]={1,0,0,0,0,0,0,0};
		u8 rowa_M[]={1,1,1,1,1,1,1,1};
		u8 colb_M[]={0,1,0,0,0,0,0,0};
		u8 rowb_M[]={0,1,0,0,0,0,0,0};
		u8 colc_M[]={0,0,1,0,0,0,0,0};
		u8 rowc_M[]={0,0,1,0,0,0,0,0};
		u8 cold_M[]={0,0,0,1,0,0,0,0};
		u8 rowd_M[]={0,0,0,1,0,0,0,0};
		u8 cole_M[]={0,0,0,0,1,0,0,0};
		u8 rowe_M[]={0,0,1,0,0,0,0,0};
		u8 colf_M[]={0,0,0,0,0,1,0,0};
		u8 rowf_M[]={0,1,0,0,0,0,0,0};
		u8 colg_M[]={0,0,0,0,0,0,1,0};
		u8 rowg_M[]={1,1,1,1,1,1,1,1};

		u8 x =  30;
		while(x)
	{

	cols(cola_M);
	rows(rowa_M);
	DIO_u8WritePinVal(latch,1);
	DELAY(10);
	DIO_u8WritePinVal(latch,0);

	cols(colb_M);
	rows(rowb_M);
	DIO_u8WritePinVal(latch,1);
	DELAY(10);
	DIO_u8WritePinVal(latch,0);

	cols(colc_M);
	rows(rowc_M);
	DIO_u8WritePinVal(latch,1);
	DELAY(10);
	DIO_u8WritePinVal(latch,0);

	cols(cold_M);
	rows(rowd_M);
	DIO_u8WritePinVal(latch,1);
	DELAY(10);
	DIO_u8WritePinVal(latch,0);

	cols(cole_M);
	rows(rowe_M);
	DIO_u8WritePinVal(latch,1);
	DELAY(10);
	DIO_u8WritePinVal(latch,0);

	cols(colf_M);
	rows(rowf_M);
	DIO_u8WritePinVal(latch,1);
	DELAY(10);
	DIO_u8WritePinVal(latch,0);

	cols(colg_M);
	rows(rowg_M);
	DIO_u8WritePinVal(latch,1);
	DELAY(10);
	DIO_u8WritePinVal(latch,0);

	x-- ;
	}
}

void Write_A(void)
{
	//////////////A//////////////////////
			u8 cola_A[]={1,0,0,0,0,0,0,0};
			u8 rowa_A[]={0,0,0,1,1,1,1,1};
			u8 colb_A[]={0,1,0,0,0,0,0,0};
			u8 rowb_A[]={0,0,1,0,0,0,0,0};
			u8 colc_A[]={0,0,1,0,0,0,0,0};
			u8 rowc_A[]={0,1,0,0,0,0,0,0};
			u8 cold_A[]={0,0,0,1,0,0,0,0};
			u8 rowd_A[]={1,0,0,0,0,0,0,0};
			u8 cole_A[]={0,0,0,0,1,0,0,0};
			u8 rowe_A[]={0,1,0,0,0,0,0,0};
			u8 colf_A[]={0,0,0,0,0,1,0,0};
			u8 rowf_A[]={0,0,1,0,0,0,0,0};
			u8 colg_A[]={0,0,0,0,0,0,1,0};
			u8 rowg_A[]={0,0,0,1,1,1,1,1};
			u8 colh_A[]={1,1,1,1,1,1,1,0};
			u8 rowh_A[]={0,0,0,0,0,1,0,0};

		u8 x = 30 ;
	while(x)
	{

	cols(cola_A);
	rows(rowa_A);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(colb_A);
	rows(rowb_A);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);
	DELAY(0.001);

	cols(colc_A);
	rows(rowc_A);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(cold_A);
	rows(rowd_A);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(cole_A);
	rows(rowe_A);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(colf_A);
	rows(rowf_A);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(colg_A);
	rows(rowg_A);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

		cols(colh_A);
		rows(rowh_A);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

	x-- ;
	}
}


void Write_D(void)
{
	//////////////D//////////////////////
	u8 cola_D[]={1,0,0,0,0,0,0,0};
	u8 rowa_D[]={1,1,1,1,1,1,1,1};
	u8 colb_D[]={0,1,0,0,0,0,0,0};
	u8 rowb_D[]={1,0,0,0,0,0,0,1};
	u8 colc_D[]={0,0,1,0,0,0,0,0};
	u8 rowc_D[]={1,0,0,0,0,0,0,1};
	u8 cold_D[]={0,0,0,1,0,0,0,0};
	u8 rowd_D[]={0,1,0,0,0,0,1,0};
	u8 cole_D[]={0,0,0,0,1,0,0,0};
	u8 rowe_D[]={0,0,1,1,1,1,0,0};

	u8 x =30 ;

	while(x)
	{

    cols(cola_D);
	rows(rowa_D);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(colb_D);
	rows(rowb_D);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(colc_D);
	rows(rowc_D);
    DIO_u8WritePinVal(latch,1);
    DELAY(0.001);
    DIO_u8WritePinVal(latch,0);

    cols(cold_D);
	rows(rowd_D);
	DIO_u8WritePinVal(latch,1);
	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	cols(cole_D);
	rows(rowe_D);
    DIO_u8WritePinVal(latch,1);
    DELAY(0.001);
    DIO_u8WritePinVal(latch,0);
     x-- ;
	}


}

void Write_O(void)
{
	//////////////D//////////////////////
		u8 cola_O[]={1,0,0,0,0,0,0,0};
		u8 rowa_O[]={0,0,1,1,1,1,0,0};
		u8 colb_O[]={0,1,0,0,0,0,0,0};
		u8 rowb_O[]={0,1,0,0,0,0,1,0};
		u8 colc_O[]={0,0,1,0,0,0,0,0};
		u8 rowc_O[]={1,0,0,0,0,0,0,1};
		u8 cold_O[]={0,0,0,1,0,0,0,0};
		u8 rowd_O[]={1,0,0,0,0,0,0,1};
		u8 cole_O[]={0,0,0,0,1,0,0,0};
		u8 rowe_O[]={1,0,0,0,0,0,0,1};
		u8 colf_O[]={0,0,0,0,0,1,0,0};
		u8 rowf_O[]={0,1,0,0,0,0,1,0};
		u8 colg_O[]={0,0,0,0,0,0,1,0};
		u8 rowg_O[]={0,0,1,1,1,1,0,0};

		u8 x = 30 ;
		while(x)
		{

		cols(cola_O);
		rows(rowa_O);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		cols(colb_O);
		rows(rowb_O);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		cols(colc_O);
		rows(rowc_O);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		cols(cold_O);
		rows(rowd_O);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		cols(cole_O);
		rows(rowe_O);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		cols(colf_O);
		rows(rowf_O);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		cols(colg_O);
		rows(rowg_O);
		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		x--;
		}
}

void Write_H(void)
{
	u8 cola_H[]={1,0,0,0,0,0,0,0};
	u8 rowa_H[]={1,1,1,1,1,1,1,0};
	u8 colb_H[]={1,1,1,1,1,1,1,1};
	u8 rowb_H[]={0,0,0,1,0,0,0,0};
	u8 colc_H[]={0,0,0,0,0,0,0,1};
	u8 rowc_H[]={1,1,1,1,1,1,1,0};


	u8 x = 50 ;
			while(x)
			{

cols(cola_H);
rows(rowa_H);
DIO_u8WritePinVal(latch,1);
DELAY(0.001);
DIO_u8WritePinVal(latch,0);

cols(colb_H);
rows(rowb_H);
DIO_u8WritePinVal(latch,1);
DELAY(0.001);
DIO_u8WritePinVal(latch,0);

cols(colc_H);
rows(rowc_H);
DIO_u8WritePinVal(latch,1);
DELAY(0.001);
DIO_u8WritePinVal(latch,0);

x--;
			}
}


void rows(u8 *PIN_NUM)
{
	u8 i ;

	for(i=0 ;i<8;i++ )
	{
       if(PIN_NUM[i]==1)
    	   DIO_u8WritePinVal(ds,0);
       else
    	   DIO_u8WritePinVal(ds,1);

       DIO_u8WritePinVal(clk,1);
       	DELAY(0.01);

       	DIO_u8WritePinVal(clk,0);

	}

}
void cols(u8 *PIN_NUM)
{
	u8 i ;
	for(i=0 ;i<8;i++ )
	{
       if(PIN_NUM[i]==1)
    	   DIO_u8WritePinVal(ds,1);
       else
    	   DIO_u8WritePinVal(ds,0);

       	DIO_u8WritePinVal(clk,1);
       	DELAY(0.01);

       	DIO_u8WritePinVal(clk,0);
	}

}

