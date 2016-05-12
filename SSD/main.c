/*
 * main.c
 *
 *  Created on: Feb 3, 2016
 *      Author: m.mamdooh
 */

#include "type.h"
#include "SSD_interface.h"
#include "DIO-interface.h"
#include "Delay.h"
#include "SSD_config.h"

#define latch  17
#define ds 18
#define clk 16

void Write_H(void) ;
void Write_O(void) ;
void Write_D(void) ;
void Write_A(void) ;
void Write_M(void) ;
void Write_R(void) ;
void Write_I(void) ;
void Write_U(void) ;
void Write_N(void) ;
void cols(u8 *PIN_NUM);
void rows(u8 *PIN_NUM);


u8 arr[4]={0,1,2,3};
	u8 *x=6 ;
	u8 flag=0;
void main (void)
{



	DIO_voidInit();
    SSD_voidInit();
    while(1)
    {
       	Write_M() ;
      	Write_A() ;
     	Write_M() ;
  	Write_D() ;
      Write_O() ;
   Write_H() ;

       }

}

void Start_SSD(void)
{

	DIO_u8WritePinVal(8,SSD_u8OFFSTATE);
	DIO_u8WritePinVal(9,SSD_u8OFFSTATE);
	DIO_u8WritePinVal(10,SSD_u8OFFSTATE);
	DIO_u8WritePinVal(11,SSD_u8OFFSTATE);
	SSD_u8Display(0,arr[0]);
		           //	DELAY(1);
	DIO_u8WritePinVal(8,SSD_u8ONSTATE);
	DIO_u8WritePinVal(8,SSD_u8ONSTATE);
	DELAY(10);
	DIO_u8WritePinVal(8,SSD_u8ONSTATE);
	DIO_u8WritePinVal(8,SSD_u8ONSTATE);

	DIO_u8WritePinVal(8,SSD_u8OFFSTATE);
		DIO_u8WritePinVal(9,SSD_u8OFFSTATE);
		DIO_u8WritePinVal(10,SSD_u8OFFSTATE);
		DIO_u8WritePinVal(11,SSD_u8OFFSTATE);
		SSD_u8Display(0,arr[1]);
			       	 //   DELAY(1);
	            DIO_u8WritePinVal(9,SSD_u8ONSTATE);
	            DIO_u8WritePinVal(9,SSD_u8ONSTATE);
	            DELAY(1);
	            DIO_u8WritePinVal(9,SSD_u8ONSTATE);
	            DIO_u8WritePinVal(9,SSD_u8ONSTATE);

	            DIO_u8WritePinVal(8,SSD_u8OFFSTATE);
	            		DIO_u8WritePinVal(9,SSD_u8OFFSTATE);
	            		DIO_u8WritePinVal(10,SSD_u8OFFSTATE);
	            		DIO_u8WritePinVal(11,SSD_u8OFFSTATE);
	            		SSD_u8Display(0,arr[2]);
	            		// DELAY(1);
	            DIO_u8WritePinVal(10,SSD_u8ONSTATE);
	            DIO_u8WritePinVal(10,SSD_u8ONSTATE);




	      	DIO_u8WritePinVal(8,SSD_u8OFFSTATE);
	      		            		DIO_u8WritePinVal(9,SSD_u8OFFSTATE);
	      		            		DIO_u8WritePinVal(10,SSD_u8OFFSTATE);
	      		            		DIO_u8WritePinVal(11,SSD_u8OFFSTATE);
	      		            		 SSD_u8Display(0,arr[3]);
	      		            			         //   DELAY(1);
	            DIO_u8WritePinVal(11,SSD_u8ONSTATE);


	           	     	/////////////////////////////////////
	           	     	 DIO_u8ReadPinVal(16,x);

	           	     	 if(*x==1&&flag==0)
	           	     	 {
	           	     		 flag=1 ;
	           	     		DELAY(1);
	           	     		 if (arr[0]<9)
	           	     		 {
	           	     			 arr[0]++;
	           	     		 }
	           	     		 else if (arr[1]<9)
	           	     		{
	           	     			arr[1]++;
	           	     			 arr[0]=0 ;
	           	     		}
	           	     		else if (arr[2]<9)
	           	     		 {
	           	     			 arr[2]++;
	           	     			 arr[0]=0;
	           	     			 arr[1]=0;
	           	     		 }
	           	     		 else if (arr[1]<9)
	           	     		 {
	           	     			 arr[3]++;
	           	     			 arr[0]=0;
	           	     			 arr[1]=0;
	           	     			 arr[2]=0;
	           	     		 }

	           	     	 }

	           	     	 else if(*x==0)
	           	     	{
	           	     		flag=0;
	           	     	}

}
void Write_M(void)
{
	//Start_SSD();
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
			Start_SSD();
			rows(rowa_M);
			cols(cola_M);

	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	rows(rowb_M);
	cols(colb_M);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	rows(rowc_M);
	cols(colc_M);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	rows(rowd_M);
	cols(cold_M);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);


	rows(rowe_M);
	cols(cole_M);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	//Start_SSD();

	rows(rowf_M);
	cols(colf_M);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	rows(rowg_M);
	cols(colg_M);
	DIO_u8WritePinVal(latch,1);
//	DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	x-- ;

	}
}

void Write_A(void)
{
	 //Start_SSD();
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
		Start_SSD();

		rows(rowa_A);
		cols(cola_A);
	DIO_u8WritePinVal(latch,1);
	//Start_SSD();
	DIO_u8WritePinVal(latch,0);

	rows(rowb_A);
	cols(colb_A);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	//Start_SSD();
	DIO_u8WritePinVal(latch,0);

	rows(rowc_A);
	cols(colc_A);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	//Start_SSD();
	DIO_u8WritePinVal(latch,0);

	rows(rowd_A);
	cols(cold_A);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	//Start_SSD();
	DIO_u8WritePinVal(latch,0);

	rows(rowe_A);
	cols(cole_A);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	//Start_SSD();
	DIO_u8WritePinVal(latch,0);

	rows(rowf_A);
	cols(colf_A);
	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	//Start_SSD();
	DIO_u8WritePinVal(latch,0);

	rows(rowg_A);
	cols(colg_A);
	DIO_u8WritePinVal(latch,1);
//	DELAY(0.001);
	//Start_SSD();
	DIO_u8WritePinVal(latch,0);

	rows(rowh_A);
		cols(colh_A);
		DIO_u8WritePinVal(latch,1);
		//DELAY(0.001);
		//Start_SSD();
		DIO_u8WritePinVal(latch,0);

	x-- ;
	}
}


void Write_D(void)
{
	  Start_SSD();
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

		Start_SSD();
		rows(rowa_D);
		cols(cola_D);

	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	rows(rowb_D);
	cols(colb_D);

	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	rows(rowc_D);
	cols(colc_D);

    DIO_u8WritePinVal(latch,1);
    //DELAY(0.001);
    DIO_u8WritePinVal(latch,0);

    rows(rowd_D);
    cols(cold_D);

	DIO_u8WritePinVal(latch,1);
	//DELAY(0.001);
	DIO_u8WritePinVal(latch,0);

	rows(rowe_D);
	cols(cole_D);

    DIO_u8WritePinVal(latch,1);
    //DELAY(0.001);
    DIO_u8WritePinVal(latch,0);
     x-- ;
	}


}

void Write_O(void)
{
	  Start_SSD();
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
			Start_SSD();
			rows(rowa_O);
			cols(cola_O);

		DIO_u8WritePinVal(latch,1);
		//DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		rows(rowb_O);
		cols(colb_O);

		DIO_u8WritePinVal(latch,1);
		//DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		rows(rowc_O);
		cols(colc_O);

		DIO_u8WritePinVal(latch,1);
		//DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		rows(rowd_O);
		cols(cold_O);

		DIO_u8WritePinVal(latch,1);
		//DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		rows(rowe_O);
		cols(cole_O);

		DIO_u8WritePinVal(latch,1);
		//DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		rows(rowf_O);
		cols(colf_O);

		DIO_u8WritePinVal(latch,1);
		//DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		rows(rowg_O);
		cols(colg_O);

		DIO_u8WritePinVal(latch,1);
//		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		x--;
		}
}

void Write_H(void)
{
	  Start_SSD();
	u8 cola_H[]={1,0,0,0,0,0,0,0};
	u8 rowa_H[]={1,1,1,1,1,1,1,0};
	u8 colb_H[]={1,1,1,1,1,1,1,1};
	u8 rowb_H[]={0,0,0,1,0,0,0,0};
	u8 colc_H[]={0,0,0,0,0,0,0,1};
	u8 rowc_H[]={1,1,1,1,1,1,1,0};


	u8 x = 30 ;
			while(x)
			{
				Start_SSD();
				rows(rowa_H);
				cols(cola_H);

DIO_u8WritePinVal(latch,1);
//DELAY(1);
DIO_u8WritePinVal(latch,0);

rows(rowb_H);
cols(colb_H);

DIO_u8WritePinVal(latch,1);
//DELAY(1);
DIO_u8WritePinVal(latch,0);

rows(rowc_H);
cols(colc_H);

DIO_u8WritePinVal(latch,1);
//DELAY(1);
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
void Write_R(void)
{
	u8 cola_R[]={1,0,0,0,0,0,0,0};
	u8 rowa_R[]={1,1,1,1,1,1,0,0};
	u8 colb_R[]={0,1,0,0,0,0,0,0};
    u8 rowb_R[]={1,0,1,0,0,0,0,0};
    u8 colc_R[]={0,0,1,0,0,0,0,0};
    u8 rowc_R[]={1,0,1,0,1,0,0,0};
    u8 cold_R[]={0,0,0,1,0,0,0,0};
    u8 rowd_R[]={1,1,1,0,0,1,0,0};

    u8 x =20 ;
    while(x)
    {
    cols(cola_R);
    rows(rowa_R);
    DIO_u8WritePinVal(latch,1);
    DELAY(0.1);
    DIO_u8WritePinVal(latch,0);
    cols(colb_R);
   	rows(rowb_R);
    DIO_u8WritePinVal(latch,1);
    DELAY(0.1);
    DIO_u8WritePinVal(latch,0);
    cols(colc_R);
   	rows(rowc_R);
    DIO_u8WritePinVal(latch,1);
    DELAY(0.1);
    		    		    		DIO_u8WritePinVal(latch,0);
    		    		    		 cols(cold_R);
    		    		    		   	rows(rowd_R);
    		    		    		    DIO_u8WritePinVal(latch,1);
    		    		    		    DELAY(0.1);
    		    		    		    DIO_u8WritePinVal(latch,0);

      				    		    		    		  x--;
    }		    		    		    		    		    		    		    		    		DIO_u8WritePinVal(latch,0);
}

void Write_I(void)
{
	u8 cola_I[]={1,1,1,1,1,1,1,1};
	u8 rowa_I[]={0,0,0,0,0,0,0,1};
	u8 colb_I[]={0,0,0,1,1,0,0,0};
    u8 rowb_I[]={1,1,1,1,1,1,1,1};
    u8 colc_I[]={1,1,1,1,1,1,1,1};
    u8 rowc_I[]={1,0,0,0,0,0,0,0};
    u8 x = 20 ;
    while(x)
    {

    cols(cola_I);
    		rows(rowa_I);
    		DIO_u8WritePinVal(latch,1);
    		DELAY(0.001);
    		DIO_u8WritePinVal(latch,0);


    		cols(colb_I);
    		    		rows(rowb_I);
    		    		DIO_u8WritePinVal(latch,1);
    		    		DELAY(0.001);
    		    		DIO_u8WritePinVal(latch,0);
    		    		cols(colc_I);
    		    		    		rows(rowc_I);
    		    		    		DIO_u8WritePinVal(latch,1);
    		    		    		DELAY(0.001);
    		    		    		DIO_u8WritePinVal(latch,0);
x--;
    }
}
void Write_N(void)
{
	u8 cola_N[]={1,0,0,0,0,0,0,0};
	u8 rowa_N[]={1,1,1,1,1,1,1,1};
	u8 colb_N[]={0,1,0,0,0,0,0,0};
	u8 rowb_N[]={0,1,0,0,0,0,0,0};
	u8 colc_N[]={0,0,1,0,0,0,0,0};
	u8 rowc_N[]={0,0,1,0,0,0,0,0};
	u8 cold_N[]={0,0,0,1,0,0,0,0};
	u8 rowd_N[]={0,0,0,1,0,0,0,0};
	u8 cole_N[]={0,0,0,0,1,0,0,0};
	u8 rowe_N[]={0,0,0,0,1,0,0,0};
	u8 colf_N[]={0,0,0,0,0,1,0,0};
	u8 rowf_N[]={0,0,0,0,0,1,0,0};
	u8 colg_N[]={0,0,0,0,0,0,1,0};
	u8 rowg_N[]={0,0,0,0,0,0,1,0};
	u8 colh_N[]={0,0,0,0,0,0,0,1};
	u8 rowh_N[]={1,1,1,1,1,1,1,1};

	 cols(cola_N);
	 rows(rowa_N);
	 DIO_u8WritePinVal(latch,1);
	 DELAY(0.001);
	 DIO_u8WritePinVal(latch,0);

	 cols(colb_N);
	 rows(rowb_N);
	 DIO_u8WritePinVal(latch,1);
	 DELAY(0.001);
	 DIO_u8WritePinVal(latch,0);

	 cols(colc_N);
	 	 rows(rowc_N);
	 	 DIO_u8WritePinVal(latch,1);
	 	 DELAY(0.001);
	 	 DIO_u8WritePinVal(latch,0);

	 	cols(cold_N);
	 		 rows(rowd_N);
	 		 DIO_u8WritePinVal(latch,1);
	 		 DELAY(0.001);
	 		 DIO_u8WritePinVal(latch,0);

	 		cols(cole_N);
	 			 rows(rowe_N);
	 			 DIO_u8WritePinVal(latch,1);
	 			 DELAY(0.001);
	 			 DIO_u8WritePinVal(latch,0);
	 			cols(colf_N);
	 				 rows(rowf_N);
	 				 DIO_u8WritePinVal(latch,1);
	 				 DELAY(0.001);
	 				 DIO_u8WritePinVal(latch,0);
	 				cols(colg_N);
	 					 rows(rowg_N);
	 					 DIO_u8WritePinVal(latch,1);
	 					 DELAY(0.001);
	 					 DIO_u8WritePinVal(latch,0);

	 					cols(colh_N);
	 						 rows(rowh_N);
	 						 DIO_u8WritePinVal(latch,1);
	 						 DELAY(0.001);
	 						 DIO_u8WritePinVal(latch,0);
}
void Write_U(void)
{
	    u8 cola_U[]={0,0,0,0,0,0,1,0};
		u8 rowa_U[]={1,1,1,1,1,1,1,1};
		u8 colb_U[]={1,1,1,1,1,1,1,1};
		u8 rowb_U[]={0,0,0,0,0,0,0,1};
		u8 colc_U[]={0,0,0,0,0,0,0,1};
		u8 rowc_U[]={1,1,1,1,1,1,1,1};

		rows(rowa_U);
		cols(cola_U);

		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);


		rows(rowb_U);
		cols(colb_U);

		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

		rows(rowc_U);
		cols(colc_U);

		DIO_u8WritePinVal(latch,1);
		DELAY(0.001);
		DIO_u8WritePinVal(latch,0);

}
