/**********************************************************************************************************************
/******************AUTHER:Ahmed elsayed         ***********************************************************************
********************File: interface of DIO      ***********************************************************************
/********************Date: 3/9/2022             ***************************************************************************
/********************ver:v1                     ****************************************************************************
/********************Desc:                      ***************************************************************************/

#include"../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include "TIMER_PRIVATE.h"
#include "TIMER_CFG.h"
#include "TIMER_INTERFACE.h"
#include <avr/delay.h>
//THIS COMMENTS IS TO UNDERSTAND THE CONCEPTS OF PRELOAD AND OVERFLLOW BUT IT DOESNOT RELATE TO THE CODE as func TIMER2_VidSetDesiredTime_ms solve all of this/*256(2^n)* 256(prescaller value) /8*10^6(frequency of the system)=0.008192*/
f32 TIMER0_OV=0; 

/*1/0.008192=122.070313->this is the number that counterflag should set to 1 to make the toggle bit excute after 1 sec*/
/*preload= (1-0.070313(the number after the decimal in the above number))*256(2^n) */
f32 TIMER0_PRELOAD=0;//for preload
u32 TIMER0_COUNTERFLAG=0;//number of overflow that should happen
u16  TIMER0_OVCounter=256; //2^n
u16 TIMER0_U16PRESCALER=0;//for prescaller

/*the value you want to put in the OCR0 in CTC or PWM*/
u32 TIMER0_CTC=128;
/*Global Pointer to function*/
void (*TIMER0CallBack)(void);


void TIMER0_VidInit(void) /*External Interrupts Initialization*/
{
	#if TIMER0_TYPE==0
		SET_BIT(TCCR0,FOC0);
		//choose Normal	(overflow)
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);

#if TIMER0INT_OVENABLE==1
		SET_BIT(TIMSK,TOIE0);
		#endif
	TCNT0=TIMER0_PRELOAD;//PUT THE TIME THAT YOU WANT TO START THE FIRST CLOCK WITH IT IN THE COUNTER REGISTER
	
	#elif TIMER0_TYPE==1//not complete
	CLR_BIT(TCCR0,FOC0);	
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
    TCNT0=TIMER0_PRELOAD;//PUT THE TIME THAT YOU WANT TO START THE FIRST CLOCK WITH IT IN THE COUNTER REGISTER

		
	#elif TIMER0_TYPE==2
	//CTC mode
	SET_BIT(TCCR0,FOC0);
//choose CTC	
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	TCNT0=TIMER0_PRELOAD;//PUT THE TIME THAT YOU WANT TO START THE FIRST CLOCK WITH IT IN THE COUNTER REGISTER
	OCR0=TIMER0_CTC;// value that counter should reach it to let an inttrupt happen n CTC mode
	SET_BIT(TIMSK,OCIE0);// set Timer/Counter0 Output Compare Match Interrupt Enable
	CLR_BIT(TIMSK,TOIE0);// reset overfllow timer enable
	
	#elif TIMER0_TYPE==3
	CLR_BIT(TCCR0,FOC0);
	//fast pwm open
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*choose non inverted (clear) or inverted (set)
	  this is non inverted */
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);

	#endif
	//No_clock_source (NO TIMER TO WORK)
#if TIMER0_Prescaler==0
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	//No_prescaling
#elif TIMER0_Prescaler==1
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	//DIVIDE 8
#elif TIMER0_Prescaler==2
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	//DIVIDE 64
#elif TIMER0_Prescaler==3
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	//DIVIDE 256
#elif TIMER0_Prescaler==4
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		//DIVIDE 1024
#elif TIMER0_Prescaler==5
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
//falling_edge
#elif TIMER0_Prescaler==6
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);

//rising_edge
#elif TIMER0_Prescaler==7
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
		#endif


}
void TIMER0_VidSetDesiredTime_ms(f32 Copy_F32DesiredTime)
{
	//GIVE THE TIME IN MSEC IN MAIN AND IF MAKE IT HERE
#if TIMER0_PRESCALER  ==2
TIMER0_U16PRESCALER=8;
#elif TIMER0_PRESCALER  ==3
TIMER0_U16PRESCALER=64;
#elif TIMER0_PRESCALER  ==4
TIMER0_U16PRESCALER=256;
#elif TIMER0_PRESCALER  ==5
TIMER0_U16PRESCALER=1024;
#endif
	Copy_F32DesiredTime/=1000;
#if TIMER0_TYPE  ==  OVERFLOW
	TIMER0_OV=((f32)TIMER0_U16PRESCALER/F_CPU)*(f32)TIMER0_OVCounter;
	TIMER0_COUNTERFLAG=(u32)(Copy_F32DesiredTime/TIMER0_OV)+1;
	TIMER0_PRELOAD=(1-(Copy_F32DesiredTime/TIMER0_OV-(u32)(Copy_F32DesiredTime/TIMER0_OV)))*TIMER0_OVCounter;
	TIMER0_SetPRELOADVALUE();
#elif TIMER0_TYPE  ==  CTC
	OCR0=Copy_F32DesiredTime/((f32)TIMER0_U16PRESCALER/F_CPU);
#endif
	//TIMER0_VidStart();
}


/*Call back function*/
void TIMER0SetCallBack(void (*ptr)(void))
{
	TIMER0CallBack=ptr;
}
void TIMER0_SetPRELOADVALUE (void)
{
	TCNT0=TIMER0_PRELOAD;
}

void TIMER0_SetOCROPWM (u8 prcentage)
{
	OCR0=((f32)prcentage/100)*256;
}
/*INT0 ISR Functions*/
void __vector_11(void)
{

	static u8 OV_COUNT=0;//THIS LINE IS READ ONR TIME ONLY
	OV_COUNT++;
	if (OV_COUNT==123)
	{
		TIMER0_SetPRELOADVALUE();
		OV_COUNT=0;
		TIMER0CallBack();//TOGGLE BIT FUNCTION
	}
}
void __vector_10(void)
{

	TIMER0CallBack();
}
