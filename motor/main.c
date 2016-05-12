/*
 * main.c
 *
 *  Created on: Feb 23, 2016
 *      Author: m.mamdooh
 */
#include "DIO-interface.h"
#include "Delay.h"
#include "KPD_interface.h"
#include "DIO-utilites.h"

#define latch  25
#define ds 	26
#define clk 24

#define btn  4
#define Rdir 8        //24
#define Ldir 9       //25

#define st1 10
#define st2 11
#define st3 12
#define st4 13


u8 x ,m=1 ;
u8 state=0,flag=0,press=0 ,f=2 , init=0 ,flg;
u32 count=0 ;
void step();
void Write_non(void);
void Mstop();
void Mright();
void Mleft() ;
void counter();
void init_state();
void Write_L(void) ;
void Write_R(void) ;
void cols(u8 *PIN_NUM);
void rows(u8 *PIN_NUM);
void cont_press();
void on_press();
void light();
void init_press();
void main()
{

	DIO_voidInit();
	KPD_voidInit();
	while(1)
	{
		init_state();
		//DIO_u8WritePinVal(Ldir,1);
		light();
	//	step();
//DELAY(1);

    }
}

void init_state()
{
	DIO_u8ReadPinVal(btn,&x);

		           	     	 if(x==1&&flag==0)
		           	     	 {

		           	     		 flag=1;
//		           	     		DELAY(0.2);
		           	     		press=1 ;
		           	     	init_press();
		           	     		counter();
		           	     		if(count<250 && press==1 )
		           	     		{
		           	     			cont_press();
		           	     		}
		           	     		else if(count>=250 && press==1)
		           	     		{
	   //                           Mright();
	                              on_press();

		           	     		}

		           	     	//light();
		                   }

		           	  	 else if(x==0)
		           	      {
		           	    	  flag=0;
		           	    	 count=0 ;
		           	      }

		//           	  	light();
}

void init_press()
{
	if(init==0)
		Mright();
	else if (init==1)
		Mleft();

}
void cont_press()
{
	while(press==1)
	{
	 DIO_u8ReadPinVal(btn,&x);
	 //DELAY(0.2);

	 if(x==1)
	 {
		 press=2 ;
		 Mstop();
		 //init=0;
	 }
	 light();
	}
}
void on_press()
{
	init = !init ;
	while(press==1)
		{

		DIO_u8ReadPinVal(btn,&x);
		//DELAY(1);

		if(x==0)
		{
			Mstop();
			press=2 ;
		}
//		else if(x==1 )
//		{
//
//     //       init_press();
//
//			press=2 ;
//		}
		light();
		}
}
void counter()
{
	while(x==1)
	{
		DIO_u8ReadPinVal(btn,&x);
		count++;
	light();
	}
}
void Mright()
{
	DIO_u8WritePinVal(Rdir,1);
	DIO_u8WritePinVal(Ldir,0);
	f=0;
	init=0 ;
}
void Mleft()
{
	DIO_u8WritePinVal(Ldir,1);
	DIO_u8WritePinVal(Rdir,0);
	f=1 ;
	init=1 ;
	//Write_L() ;
}
void Mstop()
{
	DIO_u8WritePinVal(Rdir,0);
	DIO_u8WritePinVal(Ldir,0);
	f=2 ;
}

void Write_R(void)
{

		u8 colb_R[]={0,1,0,0,0,0,0,0};
	    u8 rowb_R[]={1,1,1,1,1,1,1,0};
	    u8 colc_R[]={0,0,1,0,0,0,0,0};
	    u8 rowc_R[]={1,0,1,0,1,0,0,0};
	    u8 cold_R[]={0,0,0,1,0,0,0,0};
	    u8 rowd_R[]={1,0,1,0,0,1,0,0};
	    u8 cole_R[]={0,0,0,0,1,0,0,0};
	    u8 rowe_R[]={1,1,1,0,0,0,1,0};



//u8 y=20 ;

	//    	  DIO_u8ReadPinVal(btn,&x);
	    rows(rowb_R);
	    cols(colb_R);
	    DIO_u8WritePinVal(latch,1);
	    DIO_u8WritePinVal(latch,0);

	    rows(rowc_R);
	    cols(colc_R);
	    DIO_u8WritePinVal(latch,1);
	    DIO_u8WritePinVal(latch,0);

	    rows(rowd_R);
	    cols(cold_R);
	    DIO_u8WritePinVal(latch,1);
	    DIO_u8WritePinVal(latch,0);

	    rows(rowe_R);
	    cols(cole_R);

	    DIO_u8WritePinVal(latch,1);
	    DIO_u8WritePinVal(latch,0);

//
//    	if(x==1)
//    		break ;

}
void Write_L(void)
{
	    u8 cola_U[]={0,1,0,0,0,0,0,0};
		u8 rowa_U[]={0,1,1,1,1,1,1,0};
		u8 colb_U[]={0,0,1,1,1,0,0,0};
		u8 rowb_U[]={0,0,0,0,0,0,1,0};
		//DELAY(1);

			//    	DIO_u8ReadPinVal(btn,&x);


		rows(rowa_U);
		cols(cola_U);

		DIO_u8WritePinVal(latch,1);

		DIO_u8WritePinVal(latch,0);


		rows(rowb_U);
		cols(colb_U);

		DIO_u8WritePinVal(latch,1);

		DIO_u8WritePinVal(latch,0);



}
void Write_non(void)
{
	    u8 cola_N[]={0,0,0,0,0,0,0,0};
		u8 rowa_N[]={0,0,0,0,0,0,0,0};

		rows(rowa_N);
		cols(cola_N);

		DIO_u8WritePinVal(latch,1);

		DIO_u8WritePinVal(latch,0);

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
       	//DELAY(0.01);

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
       	//DELAY(0.01);

       	DIO_u8WritePinVal(clk,0);
	}

}
void light(void)
{
	u8 readpad  ;
	static u64 c=0,old_c;

	if(f==0)
		Write_R() ;
	else if (f==1)
		Write_L() ;
	else if (f==2)
		Write_non();

	 KPD_u8Read(&readpad);
	 if(readpad)
	 {
		 	 if(readpad==16)
		 		 flg=!flg;

		 	 else
		 {
		 		 c=readpad;
		 		 old_c=c ;
		 }
	 }
	 else
	 {
		   c*=old_c;

		 if(c>15000)
		 {
			 step();
			 c=old_c ;
		 }

	 }

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
