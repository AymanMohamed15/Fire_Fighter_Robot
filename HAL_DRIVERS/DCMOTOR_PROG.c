#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include <avr/delay.h>
#include "../MCAL_DRIVER/DIO_INTERFACE.h"
#include "DCMOTOR_INTERFACE.h"
#include "DCMOTOR_PRIVATE.h"
#include "../MCAL_DRIVER/TIMER_INTERFACE.h"
#include "../MCAL_DRIVER/TIMER2_INTERFACE.h"


void DCMOTOR1_VidInit(void)
{
	/*set the direction of the two input pins of the dc motor to be output pins */
		DIO_VidsetpinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN1 , HIGH);
		DIO_VidsetpinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);

		/*initialize the dc motor to be stop at the beginning*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);

}
void DCMOTOR2_VidInit(void)
{
	/*set the direction of the two input pins of the dc motor to be output pins */
		DIO_VidsetpinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN3 , HIGH);
		DIO_VidsetpinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN4 , HIGH);

		/*initialize the dc motor to be stop at the beginning*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);

}

void DCMOTOR_CHOOSE(u8 target)
{
	//stop
			if (target==8)
			{
				DCMOTOR1_VidRotate(STOP,STOP);
				//_delay_ms(5000);
			}

			//move forward
			else if (target==2)
			{
				DCMOTOR1_VidRotate(CLK_WISE,CLK_WISE);
				//_delay_ms(3000);
				//DCMOTOR_VidRotatestop();
				//_delay_ms(5000);

			}

			/*move backward
			else if (target==7)
			{
				DCMOTOR_VidRotatebackward();
				//_delay_ms(3000);
				DCMOTOR_VidRotatestop();
				_delay_ms(5000);
			}*/
			//rotate right then return forward
			else if (target==1)
			{
				DCMOTOR_VidRotateright();

			}
			//rotate left then return forward
			else if (target==4)
			{
				DCMOTOR_VidRotateleft();

			}
			/*rotate 180 then return forward
			else if (target==0)
			{
				DCMOTOR_VidRotate180();
				_delay_ms(3000);
				DCMOTOR_VidRotatestop();
		    	_delay_ms(5000);

			}*/
}
void DCMOTOR1_VidRotate(u8 direction,u8 direction2)
{

//	 TIMER2_SetOCROPWM(100);
{switch(direction){
	case STOP:
		/*make the dc motor stop*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
		break;
	case CLK_WISE:
		/*make the dc motor start in CLOCK_WISE direction*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);

		break;
	case ANTI_CLK_WISE:
		/*make the dc motor start in ANTI_CLOCK_WISE  direction*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , HIGH);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);

		break;
	}
switch(direction2){

	case STOP:
		/*make the dc motor stop*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
		break;
	case CLK_WISE:
		/*make the dc motor start in CLOCK_WISE direction*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , HIGH);
		break;
	case ANTI_CLK_WISE:
		/*make the dc motor start in ANTI_CLOCK_WISE  direction*/
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , HIGH);
		DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
		break;
	}
}
TIMER2_SetOCROPWM(65);

}




void DCMOTOR_VidRotateright(void)
{

	TIMER2_SetOCROPWM(60);

	//left wheel clk wise
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);

	//right wheel clk wise
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);



}
void DCMOTOR_VidRotateleft(void)
{

	TIMER2_SetOCROPWM(60);
	//left wheel clk wise
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);

	//right wheel clk wise
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
	DIO_VidsetpinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , HIGH);




}
void DCMOTOR_VidRotatestop(void)
{
	 DCMOTOR1_VidRotate(STOP,STOP);

}
void DCMOTOR_VidRotateforward(void)
{
	 DCMOTOR1_VidRotate(CLK_WISE,CLK_WISE);

}
void DCMOTOR_VidRotatebackward(void)
{
	 DCMOTOR1_VidRotate(ANTI_CLK_WISE,ANTI_CLK_WISE);
}
void DCMOTOR_VidRotate180(void)
{
	 DCMOTOR1_VidRotate(CLK_WISE,ANTI_CLK_WISE);
}
