/*
 * main.c
 *
 *  Created on: May 29, 2016
 *      Author: m.mamdooh
 */

void icu(u32 *freq ,u32 *duty )
{
	u8 flag=0, old_val,*p ,time[2]={0}, timet , endflag=0;
	while(!endflag)
	{
	DIO_u8ReadPinVal(0,*p);
		if(flag==0)
		{
			old_val=*p;
			flag=1;
		}
		else if(*p!=old_val&&flag==1)
		{
			TimerEnable();
			old_val=*p;
			flag=2;
		}
		else if(*p!=old_val&&flag==2)
		{

			time[*p]=gettime();
			flag=3;
			old_val=*p;
		}
		else if(*p!=old_val&&flag==3)
		{
          timet=gettime();
          flag=4 ;
		}
	if(flag==4)
	{
		if(time[0]>0)
		time[1]=timet-time[0];
		else
		time[0]=timet-time[1];

		*freq=1/timet ;
		*duty=time[1]/timet;
		endflag=1;
	}
	}
}
u32 gettime()
{
	u32 time = getnumov() * ovtime + tcr0*pre/fcp;
}
u32 getnumov()
{
return count ;
}

void main (void)
{

}
