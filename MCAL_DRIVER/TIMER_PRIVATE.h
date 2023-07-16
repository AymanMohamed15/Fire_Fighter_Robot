#ifndef  TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define 	ON 							1
#define 	OFF							0



/*USED Bits in each Register*/
/*First: TCCR0 Register (8 bit )*/
#define 	FOC0 						7				/*Force Output Compare*/
#define 	WGM00 						6				/*TO CHOOSE TIMER TYPES*/
#define 	COM01 						5				/*Compare Match Output Mode */
#define 	COM00   				    4				/*Compare Match Output Mode*/
#define 	WGM01 						3				/*TO CHOOSE TIMER TYPES*/
#define 	CS02 						2				/*TO CHOOSE TIMER PRESCALLER TYPE*/
#define 	CS01 						1			    /*TO CHOOSE TIMER PRESCALLER TYPE*/
#define 	CS00 						0			    /*TO CHOOSE TIMER PRESCALLER TYPE*/
/* TIMSK Register (8 bits )*/
#define 	OCIE0						1				/*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define 	TOIE0						0				/*Timer/Counter0 Overflow Interrupt Enable*/

/*TIFR Bits*/
#define 	TOV0 					0				/*Timer/Counter0 Overflow Flag*/
#define 	OCF0 					1				/*Output Compare Flag 0*/


/*TCNT0 Bits*/
/*#define 	TCNT0 					0-7				FOR WRITING IN THE COUNTER THE INTIAL VALUE*/  

/*TIMER TYPES*/
#define OVERFLOW 0
#define PWM_PhaseCorrect    1
#define CTC    2
#define Fast_PWM    3

/*TIMER PRESCALLER TYPE */	
#define No_clock_source 0
#define No_prescaling    1
#define clk/8    2
#define clk/64    3
#define clk/256    4
#define clk/1024    5
#define falling_edge     6
#define rising_edge     7

/*Memory Location of used Registers*/
/*Volatile Feature not mandatory*/
#define TCCR0						*((volatile u8*)0x53)
#define TIMSK 						*((volatile u8*)0x59)
#define TIFR						*((volatile u8*)0x58)
#define TCNT0						*((volatile u8*)0x52)
#define OCR0						*((volatile u8*)0x5C)

/*ADC Interrupts Handlers respectively*/
void __vector_11(void)       		__attribute__((signal));			/*Private section*//*NORMAL*/
void __vector_10(void)       		__attribute__((signal));			/*Private section*//*CTC*/


#endif
