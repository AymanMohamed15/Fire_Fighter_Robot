#ifndef  TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define 	ON 							1
#define 	OFF							0



/*USED Bits in each Register*/
/*First: TCCR2 Register (8 bit )*/
#define 	FOC2 						7				/*Force Output Compare*/
#define 	WGM20 						6				/*TO CHOOSE TIMER TYPES*/
#define 	COM21 						5				/*Compare Match Output Mode */
#define 	COM20   				    4				/*Compare Match Output Mode*/
#define 	WGM21 						3				/*TO CHOOSE TIMER TYPES*/
#define 	CS22 						2				/*TO CHOOSE TIMER PRESCALLER TYPE*/
#define 	CS21 						1			    /*TO CHOOSE TIMER PRESCALLER TYPE*/
#define 	CS20 						0			    /*TO CHOOSE TIMER PRESCALLER TYPE*/
/* TIMSK Register (8 bits )*/
#define 	OCIE2						7				/*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define 	TOIE2						6				/*Timer/Counter0 Overflow Interrupt Enable*/

/*TIFR Bits*/
#define 	TOV2 					0				/*Timer/Counter0 Overflow Flag*/
#define 	OCF2 					1				/*Output Compare Flag 0*/


/*TCNT2 Bits*/
/*#define 	TCNT2 					0-7				FOR WRITING IN THE COUNTER THE INTIAL VALUE*/  

/*TIMER TYPES*/
#define OVERFLOW 0
#define PWM_PhaseCorrect    1
#define CTC    2
#define Fast_PWM    3

/*TIMER PRESCALLER TYPE */	
#define No_clock_source 0
#define No_prescaling    1
#define clk/8    2
#define clk/32    3
#define clk/64    4
#define clk/128    5
#define clk/256     6
#define clk/1024     7

/*Memory Location of used Registers*/
/*Volatile Feature not mandatory*/
#define TCCR2						*((volatile u8*)0x45)
#define TIMSK 						*((volatile u8*)0x59)
#define TIFR						*((volatile u8*)0x58)
#define TCNT2						*((volatile u8*)0x44)
#define OCR2						*((volatile u8*)0x43)

/*ADC Interrupts Handlers respectively*/
void __vector_5(void)       		__attribute__((signal));			/*Private section*//*NORMAL(OVERFLOW)*/
void __vector_4(void)       		__attribute__((signal));			/*Private section*//*CTC*/


#endif
