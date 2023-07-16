/**********************************************************************************************************************
/******************AUTHER:Ahmed elsayed         ***********************************************************************
********************File: interface of DIO      ***********************************************************************
/********************Date: 3/9/2022             ***************************************************************************
/********************ver:v1                     ****************************************************************************
/********************Desc:                      ***************************************************************************/


#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"


void DIO_VidsetpinDirection(u8 Copy_U8port,u8 Copy_U8pin,u8 Copy_U8Dir)
{
	if (1==Copy_U8Dir)
	{
		switch(Copy_U8port)
		{
			case 0: SET_BIT(DDRA_REG,Copy_U8pin);  break;
			case 1: SET_BIT(DDRB_REG,Copy_U8pin);  break;
			case 2: SET_BIT(DDRC_REG,Copy_U8pin);  break;
			case 3: SET_BIT(DDRD_REG,Copy_U8pin);  break;
			
			
		}
	}
else if (0==Copy_U8Dir)
	{
		switch(Copy_U8port)
		{
			case 0: CLR_BIT(DDRA_REG,Copy_U8pin);  break;
			case 1: CLR_BIT(DDRB_REG,Copy_U8pin);  break;
			case 2: CLR_BIT(DDRC_REG,Copy_U8pin);  break;
			case 3: CLR_BIT(DDRD_REG,Copy_U8pin);  break;
			
			
		}
		}
	
}
void DIO_VidsetpinValue(u8 Copy_U8port,u8 Copy_U8pin,u8 Copy_U8Value)
{
	if (1==Copy_U8Value)
	{
		switch(Copy_U8port)
		{
			case 0: SET_BIT(PORTA_REG,Copy_U8pin);  break;
			case 1: SET_BIT(PORTB_REG,Copy_U8pin);  break;
			case 2: SET_BIT(PORTC_REG,Copy_U8pin);  break;
			case 3: SET_BIT(PORTD_REG,Copy_U8pin);  break;
			
			
		}
	}
else if (0==Copy_U8Value)
	{
		switch(Copy_U8port)
		{
			case 0: CLR_BIT(PORTA_REG,Copy_U8pin);  break;
			case 1: CLR_BIT(PORTB_REG,Copy_U8pin);  break;
			case 2: CLR_BIT(PORTC_REG,Copy_U8pin);  break;
			case 3: CLR_BIT(PORTD_REG,Copy_U8pin);  break;
			
			
		}
		}
}
u8 DIO_U8GetPinValue(u8 Copy_U8port,u8 Copy_U8pin)
{
	u8 LOC_u8x;
		switch(Copy_U8port)
		{
			case 0: LOC_u8x=GET_BIT(PINA_REG,Copy_U8pin);  break;
			case 1: LOC_u8x=GET_BIT(PINB_REG,Copy_U8pin);  break;
			case 2: LOC_u8x=GET_BIT(PINC_REG,Copy_U8pin);  break;
			case 3: LOC_u8x=GET_BIT(PIND_REG,Copy_U8pin);  break;
			
			
		}

	return LOC_u8x;
}
void DIO_VidsetportDirection(u8 Copy_U8port,u8 Copy_U8Dir)
{
	switch(Copy_U8port)
		{
			case 0:  DDRA_REG=Copy_U8Dir;  break;
			case 1:  DDRB_REG=Copy_U8Dir;  break;
			case 2:  DDRC_REG=Copy_U8Dir;  break;
			case 3:  DDRD_REG=Copy_U8Dir;  break;
			
			
			
		}
	
}
void DIO_VidsetportValue(u8 Copy_U8port,u8 Copy_U8Value)
{
switch(Copy_U8port)
		{
			case 0:  PORTA_REG=Copy_U8Value;  break;
			case 1:  PORTB_REG=Copy_U8Value;  break;
			case 2:  PORTC_REG=Copy_U8Value;  break;
			case 3:  PORTD_REG=Copy_U8Value;  break;
			
			
			
		}
	
}
void DIO_VidTogglePinvalue(u8 Copy_U8port,u8 Copy_U8pin)
{
	switch(Copy_U8port)
		{
			case 0:  TOGGLE_BIT(PORTA_REG,Copy_U8pin);  break;
			case 1:  TOGGLE_BIT(PORTB_REG,Copy_U8pin);  break;
			case 2:  TOGGLE_BIT(PORTC_REG,Copy_U8pin);  break;
			case 3:  TOGGLE_BIT(PORTD_REG,Copy_U8pin);  break;
			         
			
			
		}
}

