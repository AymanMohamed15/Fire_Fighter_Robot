/*
 * MULTIPAL_TASKS_CAR.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Asem technology
 */

#include "MULTIPAL_TASKS_CAR_PRIVATE.h"

void MultipleTasksCar_VidInit()
{
	BluetoothInit();
	GIE_VidEnable();
	LINESENSOR_VidInit();
	TIMER2_VidInit();
	DCMOTOR1_VidInit();
	DCMOTOR2_VidInit();
	TIMER1_VidInit();

}

void MultipleTasksIntialCar_VidInit()
{
	//for get the starting
	 Bluetooth_SetCallBack(MultipleTasksCar_UARTInterrupt);

	DIO_VidsetpinDirection(PORTD,OCRTWO_HBRIDGE,HIGH);//OCR2
	//for water pump
	DIO_VidsetpinDirection(PORTB,PIN_PUMP,HIGH);
	DIO_VidsetpinValue(PORTB,PIN_PUMP,HIGH);
	//for leds
	DIO_VidsetpinDirection(PORTB,PIN_LED_ONE,HIGH);
	DIO_VidsetpinValue(PORTB,PIN_LED_ONE,HIGH);

	//  pin input to tell us if there is a flame_RIGHT or not
	DIO_VidsetpinDirection(PORTC,PIN_FLAME_RIGHT,LOW);

	//  pin input to tell us if there is a flame_LIFT or not
	DIO_VidsetpinDirection(PORTC,PIN_FLAME_LIFT,LOW);
	//pin for buzzer
	DIO_VidsetpinDirection(PORTB,PIN_BUZZER, HIGH);
	DIO_VidsetpinValue(PORTB,PIN_BUZZER,HIGH);

	//pin for LED_TWO
	DIO_VidsetpinDirection(PORTD,PIN_LED_TWO,HIGH);

	//SERVO
	DIO_VidsetpinDirection(PORTD,OCR_ONE,1);//oc1 , pin that can take the pwm from it in timer 1
	TIMER1_SetSERVOANGLE(LOW);
}

void MultipleTasksCar_UARTInterrupt(){

	u8 direction = Bluetooth_U32Getnumber() ;

	switch (direction){
	 case 'a' :

		 DCMOTOR_CHOOSE(FORWARD);
		break ;
	case 'b' :
		DCMOTOR_CHOOSE(LEFT);//left

		break ;
	case 'c' :
		DCMOTOR_CHOOSE(RIGHT);//RIGHT

		break ;
	case 'd' :
		DCMOTOR_CHOOSE(STOP);

		break ;

    }//end switch


}

void MultipleTasksLineSensor_MoveCar()
{
	//for get the starting
	 Bluetooth_SetCallBack(MultipleTasksCar_UARTInterrupt);

	u8 Local_u8_ReadOne;
	u8 Local_u8_ReadTwo;
	Local_u8_ReadOne=LINESENSOR_VidRightRead();
	Local_u8_ReadTwo=LINESENSOR_VidLeftRead();
	if(Local_u8_ReadOne==LOW && Local_u8_ReadTwo==LOW)
	{
		DCMOTOR_CHOOSE(FORWARD);//forword;
		_delay_ms(500);
	}
	else if(Local_u8_ReadOne==LOW && Local_u8_ReadTwo==HIGH)
	{
		DCMOTOR_CHOOSE(LEFT);//left
	}
	else if(Local_u8_ReadOne==HIGH && Local_u8_ReadTwo==LOW)
	{
		DCMOTOR_CHOOSE(RIGHT);//right
	}
	else
	{
		DCMOTOR_CHOOSE(STOP);//stop
		_delay_ms(500);
	}

}

void MultipleTasksFlameSensor_MoveCar()
{
	u8 Local_u8_FlamOne;
	u8 Local_u8_FlamTwo;
	Local_u8_FlamOne=FLAMEDETECT_VID1();
	Local_u8_FlamTwo=FLAMEDETECT_VID2();
	if (Local_u8_FlamOne==1 || Local_u8_FlamTwo==1)
	{
		_delay_ms(300);
		DCMOTOR_CHOOSE(STOP);//stop
		DIO_VidsetpinValue(PORTB,PIN_PUMP,LOW);//water pump works
		for(u16 i=0;i<=180;i+=5)
		{
			TIMER1_SetSERVOANGLE(i);
			_delay_ms(100);
		}
		TIMER1_SetSERVOANGLE(0);
	}
	else
	{
		DIO_VidsetpinValue(PORTB,PIN_PUMP,HIGH);
	}

}
