/*
 * Bluetooth_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP
 */

#ifndef HAL_DRIVERS_BLUETOOTH_INTERFACE_H_
#define HAL_DRIVERS_BLUETOOTH_INTERFACE_H_

/*     Libraries    */
#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"

void BluetoothInit();
u32  Bluetooth_U32Getnumber();
void Bluetooth_VidSendData(u8 Copy_U8Data);
void BluetoothVidSendString (u8 Copy_U8String[]);
void Bluetooth_SetCallBack(  void (*ptr)(void) );
void MultipleTasksCar_UARTInterrupt();

#endif /* HAL_DRIVERS_BLUETOOTH_INTERFACE_H_ */
