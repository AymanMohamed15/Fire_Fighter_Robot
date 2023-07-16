/*
 * BlueTooth_prg.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */


#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include "../MCAL_DRIVER/UART_Interface.h"

void BluetoothInit(){
	UART_VidInit () ;
}
u32 Bluetooth_U32Getnumber(){
	return UART_VidRecieveData();
}
void Bluetooth_VidSendData(u8 Copy_U8Data){
	 UART_VidSendData(Copy_U8Data);
}

void BluetoothVidSendString (u8 Copy_U8String[]){
	UART_VidSendString(Copy_U8String);
}

void Bluetooth_SetCallBack(  void (*ptr)(void) ){
	SetCallBack(ptr);
}

