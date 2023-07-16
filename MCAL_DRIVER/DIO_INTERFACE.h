/*******************************************************************************************************************
/****************************AUTHER:Ahmed elsayed *****************************************************************
********************File: interface of DIO  ***************************************************************************
/********************Date: 3/9/2022 ***************************************************************************
/********************ver:v1**********************************************************************************
/********************Desc: **********************************************************************************
*/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_VidsetpinDirection(u8 Copy_U8port,u8 Copy_Upin,u8 Copy_U8Dir);
void DIO_VidsetpinValue(u8 Copy_U8port,u8 Copy_Upin,u8 Copy_U8Value);
u8 DIO_U8GetPinValue(u8 Copy_U8port,u8 Copy_U8pin);
void DIO_VidsetportDirection(u8 Copy_U8port,u8 Copy_U8Dir);
void DIO_VidsetportValue(u8 Copy_U8port,u8 Copy_U8Value);
void DIO_VidTogglePinvalue(u8 Copy_U8port,u8 Copy_U8pin);


#endif