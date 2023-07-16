#ifndef  TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define 	ON 							1
#define 	OFF							0



/*USED Bits in each Register*/
/*First: WDTCR Register (8 bit )*/
#define 	WDTOE   				    4				/*Compare Match Output Mode*/
#define 	WDE 						3				/*TO CHOOSE TIMER TYPES*/
#define 	WDP2 						2				/*TO CHOOSE TIMER PRESCALLER TYPE*/
#define 	WDP1 						1			    /*TO CHOOSE TIMER PRESCALLER TYPE*/
#define 	WDP0 						0			    /*TO CHOOSE TIMER PRESCALLER TYPE*/
/* MCUCSR Register (8 bits )*/
#define 	WDRF						3				/*Timer/Counter0 Output Compare Match Interrupt Enable*/


/*TCCR1A*/
#define 		COM1A1									7
#define 		COM1A0									6
#define 		COM1B1									5
#define 		COM1B0									4
#define 		FOC1A									3
#define 		FOC1B									2
#define 		WGM11									1
#define 		WGM10									0

/*TCCR1B*/
#define 		ICNC1									7
#define 		ICES1									6
#define 		WGM13									4
#define 		WGM12									3
#define 		CS12									2
#define 		CS11									1
#define 		CS10									0

/*TIMSK BITS*/
#define 		TOCIE1									5
#define 		OCIE1A									4
#define 		OCIE1B									3
#define 		TOIE1									2

/*TIFR BITS*/
#define 		ICF1									5
#define 		OCF1A									4
#define 		OCF1B									3
#define 		TOV1									2  

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
#define MCUCSR						*((volatile u8*)0x54)
#define WDTCR 						*((volatile u8*)0x41)
#define 		TCCR1A			 						*((volatile u8*)0x4F)
#define 		TCCR1B			 						*((volatile u8*)0x4E)
#define 		TCNT1H			 						*((volatile u8*)0x4D)
#define 		TCNT1L			 						*((volatile u8*)0x4C)
#define 		OCR1AH 									*((volatile u8*)0x4B)
#define 		OCR1AL 									*((volatile u8*)0x4A)
#define 		OCR1BH 									*((volatile u8*)0x49)
#define 		OCR1BL 									*((volatile u8*)0x48)
#define 		ICR1H		 							*((volatile u8*)0x47)
#define 		ICR1L		 							*((volatile u8*)0x46)
#define TIMSK 						*((volatile u8*)0x59)
#define TIFR						*((volatile u8*)0x58)

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

/*ADC Interrupts Handlers respectively*/
void __vector_9(void)       		__attribute__((signal));			/*Private section*//*NORMAL(OVERFLOW)*/


#endif
