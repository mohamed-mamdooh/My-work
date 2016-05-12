/*
/*
 * DIO_prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: Nour
 */

/*comment!: Read Pin Value */
#include "types.h"
#include "utils.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"
static u8* const DIO_u8ArrToPortsAddress[DIO_u8PORTSNUM]={&DIO_u8PORTA,&DIO_u8PORTB,&DIO_u8PORTC,&DIO_u8PORTD} ;
static u8* const DIO_u8ArrToPinsAddress[DIO_u8PORTSNUM]={&DIO_u8PINA,&DIO_u8PINB,&DIO_u8PINC,&DIO_u8PIND} ;
static u8* const DIO_u8ArrToDdrsAddress[DIO_u8PORTSNUM]={&DIO_u8DDRA,&DIO_u8DDRB,&DIO_u8DDRC,&DIO_u8DDRD} ;

u8 DIO_u8ReadPinVal(u8 copy_u8PinIdx,u8* copy_u8PtrToVal)
{	u8 Local_u8ReturnedVal;
	u8 Local_u8PortNumber=(u8)(copy_u8PinIdx/DIO_u8PORTSIZE);
	u8 Local_u8PinNumber=(u8)(copy_u8PinIdx %DIO_u8PORTSIZE);
	if ((copy_u8PinIdx < DIO_u8PINSNUM) && (getbit(*DIO_u8ArrToDdrsAddress[Local_u8PortNumber],Local_u8PinNumber)==DIO_u8INPUT))
	{Local_u8ReturnedVal=u8OK;
	*copy_u8PtrToVal=getbit(*DIO_u8ArrToPinsAddress[Local_u8PortNumber],Local_u8PinNumber);
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}

	return Local_u8ReturnedVal;
}

/*comment!: Write Pin Value */
u8 DIO_u8WritePinVal(u8 copy_u8PinIdx,u8 copy_u8PinVal)
{	u8 Local_u8ReturnedVal;
	u8 Local_u8PortNumber=(u8)(copy_u8PinIdx/DIO_u8PORTSIZE);
	u8 Local_u8PinNumber=(u8)(copy_u8PinIdx %DIO_u8PORTSIZE);
	if ((copy_u8PinIdx < DIO_u8PINSNUM) && (getbit(*DIO_u8ArrToDdrsAddress[Local_u8PortNumber],Local_u8PinNumber)==DIO_u8OUTPUT))
	{Local_u8ReturnedVal=u8OK;
	assignbit(*DIO_u8ArrToPortsAddress[Local_u8PortNumber],Local_u8PinNumber,copy_u8PinVal);
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}

	return Local_u8ReturnedVal;
}



/*comment!: Read PORT Value */
u8 DIO_u8ReadPortVal(u8 copy_u8PortIdx,u8* copy_u8PtrToVal)
{	u8 Local_u8ReturnedVal;
	if ((copy_u8PortIdx < DIO_u8PORTSNUM) && (*DIO_u8ArrToDdrsAddress[copy_u8PortIdx]==DIO_u8ALLPORTINPUT) )
	{Local_u8ReturnedVal=u8OK;
	*copy_u8PtrToVal=*DIO_u8ArrToPinsAddress[copy_u8PortIdx];
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}
	return Local_u8ReturnedVal;
}

/*comment!: Write Port Value */
u8 DIO_u8WritePortVal(u8 copy_u8PortIdx,u8 copy_u8PortVal)
{	u8 Local_u8ReturnedVal;
	if ((copy_u8PortIdx < DIO_u8PORTSNUM) && (*DIO_u8ArrToDdrsAddress[copy_u8PortIdx]==DIO_u8ALLPORTOUTPUT))
	{Local_u8ReturnedVal=u8OK;
	assignreg(*DIO_u8ArrToPortsAddress[copy_u8PortIdx],copy_u8PortVal);
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}

	return Local_u8ReturnedVal;
}


/*comment!: Write Pin direction */
u8 DIO_u8WritePinDir(u8 copy_u8PinIdx,u8 copy_u8PinDir)
{	u8 Local_u8ReturnedVal;
	u8 Local_u8PortNumber=(u8)(copy_u8PinIdx/DIO_u8PORTSIZE);
	u8 Local_u8PinNumber=(u8)(copy_u8PinIdx %DIO_u8PORTSIZE);
	if ((copy_u8PinIdx < DIO_u8PINSNUM))
	{Local_u8ReturnedVal=u8OK;
	assignbit(*DIO_u8ArrToDdrsAddress[Local_u8PortNumber],Local_u8PinNumber,copy_u8PinDir);
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}

	return Local_u8ReturnedVal;
}

/*comment!: Write Port direction */
u8 DIO_u8WritePortDir(u8 copy_u8PortIdx,u8 copy_u8PortDir)
{	u8 Local_u8ReturnedVal;
	if ((copy_u8PortIdx < DIO_u8PORTSNUM))
	{Local_u8ReturnedVal=u8OK;
	assignreg(*DIO_u8ArrToDdrsAddress[copy_u8PortIdx],copy_u8PortDir);
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}

	return Local_u8ReturnedVal;
}


/*comment!: Read Pin direction */
u8 DIO_u8ReadPinDir(u8 copy_u8PinIdx,u8* copy_u8PtrToDir)
{	u8 Local_u8ReturnedVal;
	u8 Local_u8PortNumber=(u8)(copy_u8PinIdx/DIO_u8PORTSIZE);
	u8 Local_u8PinNumber=(u8)(copy_u8PinIdx %DIO_u8PORTSIZE);
	if ((copy_u8PinIdx < DIO_u8PINSNUM))
	{Local_u8ReturnedVal=u8OK;
	*copy_u8PtrToDir=getbit(*DIO_u8ArrToDdrsAddress[Local_u8PortNumber],Local_u8PinNumber);
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}

	return Local_u8ReturnedVal;
}

/*comment!: Read PORT Direction */
u8 DIO_u8ReadPortDir(u8 copy_u8PortIdx,u8* copy_u8PtrToDir)
{	u8 Local_u8ReturnedVal;
	if ((copy_u8PortIdx < DIO_u8PORTSNUM))
	{Local_u8ReturnedVal=u8OK;
	*copy_u8PtrToDir=*DIO_u8ArrToDdrsAddress[copy_u8PortIdx];
	}
	else{
	Local_u8ReturnedVal=u8ERROR;
	}
	return Local_u8ReturnedVal;
}

/*comment!: Initilization function */
extern void DIO_voidInit(void)
	{	DIO_u8DDRA=(u8)(DIO_u8PORTADIR);
		DIO_u8DDRB=(u8)(DIO_u8PORTBDIR);
		DIO_u8DDRC=(u8)(DIO_u8PORTCDIR);
		DIO_u8DDRD=(u8)(DIO_u8PORTDDIR);
		DIO_u8PORTA=(DIO_u8PORTADIR & DIO_u8PORTAVAL)|((~DIO_u8PORTADIR) & DIO_u8PORTA);
		DIO_u8PORTB=(DIO_u8PORTBDIR & DIO_u8PORTBVAL)|((~DIO_u8PORTBDIR) & DIO_u8PORTB);
		DIO_u8PORTC=(DIO_u8PORTCDIR & DIO_u8PORTCVAL)|((~DIO_u8PORTCDIR) & DIO_u8PORTC);
		DIO_u8PORTD=(DIO_u8PORTDDIR & DIO_u8PORTDVAL)|((~DIO_u8PORTDDIR) & DIO_u8PORTD);

	}

