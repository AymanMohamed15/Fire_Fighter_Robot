/**********************************************************************************************************************
/******************AUTHER:Ahmed elsayed         ***********************************************************************
********************File: interface of DIO      ***********************************************************************
/********************Date: 3/9/2022             ***************************************************************************
/********************ver:v1                     ****************************************************************************
/********************Desc:                      ***************************************************************************/

#include"../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include "TIMER2_PRIVATE.h"
#include "TIMER2_CFG.h"
#include "TIMER2_INTERFACE.h"
#include <avr/delay.h>
//THIS COMMENTS IS TO UNDERSTAND THE CONCEPTS OF PRELOAD AND OVERFLLOW BUT IT DOESNOT RELATE TO THE CODE as func TIMER2_VidSetDesiredTime_ms solve all of this
/*256(2^n)* 256(prescaller value) /8*10^6(frequency of the system)=0.008192*/
f32 TIMER2_OV=0; 

/*1/0.008192=122.070313->this is the number that counterflag should set to 1 to make the toggle bit excute after 1 sec*/
/*preload= (1-0.070313(the number after the decimal in the above number))*256(2^n) */
f32 TIMER2_PRELOAD=0;//for preload
u32 TIMER2_COUNTERFLAG=0;//number of overflow that should happen
u16  TIMER2_OVCounter=256; //2^n
u16 TIMER2_U16PRESCALER=0;//for prescaller


/*the value you want to put in the OCR0 in CTC or PWM*/
u32 TIMER2_CTC=128;
/*Global Pointer to function*/
void (*TIMER2CallBack)(void);


void TIMER2_VidInit(void) /*External Interrupts Initialization*/
{
	#if TIMER2_TYPE==0
		SET_BIT(TCCR2,FOC2);
		//choose Normal	(overflow)
		CLR_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);

#if TIMER2INT_OVENABLE==1
		SET_BIT(TIMSK,TOIE2);
		CLR_BIT(TIMSK,OCIE2);
		#endif
	TCNT2=TIMER2_PRELOAD;//PUT THE TIME THAT YOU WANT TO START THE FIRST CLOCK WITH IT IN THE COUNTER REGISTER
	
	#elif TIMER2_TYPE==1//not complete
	CLR_BIT(TCCR2,FOC2);	
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
    TCNT2=TIMER2_PRELOAD;//PUT THE TIME THAT YOU WANT TO START THE FIRST CLOCK WITH IT IN THE COUNTER REGISTER

		
	#elif TIMER2_TYPE==2
	//CTC mode
	SET_BIT(TCCR2,FOC2);
//choose CTC	
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	TCNT2=TIMER2_PRELOAD;//PUT THE TIME THAT YOU WANT TO START THE FIRST CLOCK WITH IT IN THE COUNTER REGISTER
	OCR2=TIMER2_CTC;// value that counter should reach it to let an inttrupt happen n CTC mode
	SET_BIT(TIMSK,OCIE2);// set Timer/Counter0 Output Compare Match Interrupt Enable
	CLR_BIT(TIMSK,TOIE2);// reset overfllow timer enable
	
	#elif TIMER2_TYPE==3
	CLR_BIT(TCCR2,FOC2);
	//fast pwm open
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	/*choose non inverted (clear) or inverted (set)
	  this is non inverted */
	SET_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);

	#endif
	//No_clock_source (NO TIMER TO WORK)
#if TIMER2_Prescaler==0
	CLR_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	//No_prescaling
#elif TIMER2_Prescaler==1
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	//DIVIDE 8
#elif TIMER2_Prescaler==2
	CLR_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	//DIVIDE 64
#elif TIMER2_Prescaler==3
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	CLR_BIT(TCCR2,CS22);
	//DIVIDE 256
#elif TIMER2_Prescaler==4
		CLR_BIT(TCCR2,CS20);
		CLR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		//DIVIDE 1024
#elif TIMER2_Prescaler==5
		SET_BIT(TCCR2,CS20);
		CLR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
//falling_edge
#elif TIMER2_Prescaler==6
		CLR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);

//rising_edge
#elif TIMER2_Prescaler==7
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		#endif


}


void TIMER2_VidSetDesiredTime_ms(f32 Copy_F32DesiredTime)
{
#if TIMER2_PRESCALER  ==2
TIMER2_U16PRESCALER=8;
#elif TIMER2_PRESCALER  ==3
TIMER2_U16PRESCALER=64;
#elif TIMER2_PRESCALER  ==4
TIMER2_U16PRESCALER=256;
#elif TIMER2_PRESCALER  ==5
TIMER2_U16PRESCALER=1024;
#endif
	Copy_F32DesiredTime/=1000;
#if TIMER2_TYPE  ==  OVERFLOW
	TIMER2_OV=((f32)TIMER2_U16PRESCALER/F_CPU)*(f32)TIMER2_OVCounter;
	TIMER2_COUNTERFLAG=(u32)(Copy_F32DesiredTime/TIMER2_OV)+1;
	TIMER2_PRELOAD=(1-(Copy_F32DesiredTime/TIMER2_OV-(u32)(Copy_F32DesiredTime/TIMER2_OV)))*TIMER2_OVCounter;
	TIMER2_SetPRELOADVALUE();
#elif TIMER2_TYPE  ==  CTC
	OCR2=Copy_F32DesiredTime/((f32)TIMER2_U16PRESCALER/F_CPU);
#endif
	//TIMER0_VidStart();
}


/*Call back function*/
void TIMER2SetCallBack(void (*ptr)(void))
{
	TIMER2CallBack=ptr;
}
void TIMER2_SetPRELOADVALUE (void)
{
	TCNT2=TIMER2_PRELOAD;
}

void TIMER2_SetOCROPWM (u8 prcentage)
{
//	OCR2=((f32)prcentage/100)*256;
	if(prcentage != 100)
			OCR2  = (u8) ( (prcentage * 256) / 100 );
		else
			OCR2 = 255;
}
/*INT2 ISR Functions*/
void __vector_5(void)
{

	static u8 OV_COUNT=0;//THIS LINE IS READ ONR TIME ONLY
	OV_COUNT++;
	if (OV_COUNT==123)
	{
		TIMER2_SetPRELOADVALUE();
		OV_COUNT=0;
		TIMER2CallBack();//TOGGLE BIT FUNCTION
	}
}
void __vector_4(void)
{

	TIMER2CallBack();
}
