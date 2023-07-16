/*
 * MULTIPAL_TASKS_CAR_PRIVATE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Asem technology
 */

#ifndef APP_DRIVER_MULTIPAL_TASKS_CAR_PRIVATE_H_
#define APP_DRIVER_MULTIPAL_TASKS_CAR_PRIVATE_H_

/*     Libraries    */

#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include <avr/delay.h>

/* Lower Layer Interface Files*/
#include "../MCAL_DRIVER/DIO_INTERFACE.h"
#include "../MCAL_DRIVER/TIMER_INTERFACE.h"
#include "../MCAL_DRIVER/TIMER2_INTERFACE.h"
#include "../MCAL_DRIVER/TIMER1_INTERFACE.h"
#include "../MCAL_DRIVER/GIE_INTERFACE.h"
#include "../MCAL_DRIVER/UART_Interface.h"

/* HALL Interface Files*/
#include "../HAL_DRIVERS/LineSensor_interface.h"
#include "../HAL_DRIVERS/DCMOTOR_INTERFACE.h"
#include "../HAL_DRIVERS/FLAMESENSOR_INTERFACE.h"
#include "../HAL_DRIVERS/Bluetooth_Interface.h"
//define wanted states
//#define STOP 0
#define CLK_WISE 1
#define ANTI_CLK_WISE 2
#define A 0
#define B 1
#define C 2
#define D 3

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define OCRTWO_HBRIDGE	7
#define OCR_ONE			5
#define PIN_PUMP		1
#define	PIN_LED_ONE		2
#define	PIN_LED_TWO		2
#define	PIN_FLAME_RIGHT	0
#define	PIN_FLAME_LIFT	0
#define	PIN_BUZZER		0
#define	FORWARD			2
#define	LEFT			4
#define	RIGHT			1
#define	STOP			8








#endif /* APP_DRIVER_MULTIPAL_TASKS_CAR_PRIVATE_H_ */
