/**********************************************************************************************************************
/******************AUTHER:Ahmed elsayed         ***********************************************************************
********************File: interface of DIO      ***********************************************************************
/********************Date: 3/9/2022             ***************************************************************************
/********************ver:v1                     ****************************************************************************
/********************Desc:                      ***************************************************************************/

#include"../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include "TIMER1_PRIVATE.h"
#include "TIMER1_CFG.h"
#include "TIMER1_INTERFACE.h"
#include <avr/delay.h>
/*65536(2^n)* 8(prescaller value) /8*10^6(frequency of the system)=0.065536 this is the time that
 it will overflow after it (at default and at prescaller=8)*/

/*preload= (1-0.065536)(the number after the decimal in the above number))*65536(2^n) */
f32 TIMER1_PRELOAD=61241.03;//for preload

/*Global Pointer to function*/
void (*TIMER1CallBack)(void);

void TIMER1_VidInit(void) /*External Interrupts Initialization*/
{
#if TIMER1_TYPE ==0
	//OVERFLOW
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
//SHOULD BE OPEN IN OVERFLOW
	SET_BIT(TCCR1A,FOC1A);
	SET_BIT(TCCR1A,FOC1B);
	SET_BIT(TIMSK,TOIE1);
	//PUT PRELOAD VALUE TO MAKE IT OVERFLOW AFTER 1 SEC IN VECTOR 9
	TCNT1H=(u8)TIMER1_PRELOAD>>8;
	TCNT1L=(u8)TIMER1_PRELOAD;
#elif TIMER1_TYPE ==1//NOT COMPLETE
//PWM_PhaseCorrect ICR1
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif TIMER1_TYPE ==2//NOT COMPLETE
//CTC ICR1
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
#elif TIMER1_TYPE ==3
	//FAST PWM
	//THIS IS MADE FOR SERVO MOTOR BUT CAN BE CHANGED EASILY
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		//PRESCCALLER (8)
		CLR_BIT(TCCR1B,CS12);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS10);
		//NON INVERTING
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		// TO GET 50HZ BY PUTING THE PRESCALLER (8) AND 200000 IS (2^n) SO T=0.02 AND F=50HZ
		ICR1H=(u8)(20000>>8);
		ICR1L=(u8)20000;
#endif
#if TIMER1_Prescaler==0
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
#elif TIMER1_Prescaler==1
	SET_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);
 #elif TIMER1_Prescaler==2
	//PRESCCALLER 8
		CLR_BIT(TCCR1B,CS12);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS10);
#elif TIMER1_Prescaler==3
		SET_BIT(TCCR1B,CS12);
		SET_BIT(TCCR1B,CS11);
		CLR_BIT(TCCR1B,CS10);
#elif TIMER1_Prescaler==4
		CLR_BIT(TCCR1B,CS12);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS10);
#elif TIMER1_Prescaler==5
		SET_BIT(TCCR1B,CS12);
		CLR_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS10);
#elif TIMER1_Prescaler==6
		CLR_BIT(TCCR1B,CS12);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS10);
#elif TIMER1_Prescaler==7
		SET_BIT(TCCR1B,CS12);
		SET_BIT(TCCR1B,CS11);
		SET_BIT(TCCR1B,CS10);



#endif
}
void TIMER1_SetOCROPWM (u16 prcentage)
{
//FOR PUT ANGLE FOR SERVO MOTOR
	OCR1AH=(u8)(prcentage>>8);
	OCR1AL=(u8)prcentage;

}
//to give angle in the main from 0 to 180
void TIMER1_SetSERVOANGLE (u16 angle)
{
	u16 value;
	value=angle*(10.83)+450;//-> y=m*x+c 10.83 is your slope
	//FOR PUT ANGLE FOR SERVO MOTOR
		OCR1AH=(u8)(value>>8);
		OCR1AL=(u8)value;
}
void WDT_VIDEN(void)
{	
    SET_BIT(WDTCR,WDE);
	// make watchdog occur after 1 sec
	CLR_BIT(WDTCR,WDP0);
	SET_BIT(WDTCR,WDP1);
	SET_BIT(WDTCR,WDP2);

}
void WDT_VIDDIS(void)
{
	WDTCR=WDTCR | (0b00011000);
	WDTCR=0;

}
void TIMER1SetCallBack(void (*ptr)(void))
{
	TIMER1CallBack=ptr;
}
void TIMER1_SetPRELOADVALUE (void)
{
	TCNT1H=(u8)TIMER1_PRELOAD>>8;
	TCNT1L=(u8)TIMER1_PRELOAD;
}
void __vector_9(void)
{
	static u8 OV_COUNT=0;//THIS LINE IS READ ONR TIME ONLY
		OV_COUNT++;

		if (OV_COUNT==16)
		{
			TIMER1CallBack();
			OV_COUNT=0;
			TIMER1_SetPRELOADVALUE();
		}

}
