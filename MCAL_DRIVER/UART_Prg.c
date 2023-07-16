/*
 * UART_Prg.c
*/

/*     Libraries    */
#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"

/* Lower Layer Interface Files*/
#include "UART_Private.h"
#include "avr/delay.h"
#include "DIO_interface.h"

static void (*UART_SetCallBack)(void) = NULL ;

void SetCallBack(  void (*ptr)(void) ){
	UART_SetCallBack = ptr ;
}

/* Own Driver Files*/

void UART_VidInit () {
	/* to define pins of TX RX */
	DIO_VidsetpinDirection(3,0,0);
	DIO_VidsetpinDirection(3,1,1);

	SET_BIT(UCSRB,RXCIE);
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	CLR_BIT(UCSRB,UCSZ2);

	u8 UCSRC_help = 0b10000000 ;
	CLR_BIT(UCSRC_help,UMSEL);
	CLR_BIT(UCSRC_help,UPM1);
	CLR_BIT(UCSRC_help,UPM0);
	CLR_BIT(UCSRC_help,USBS);
	SET_BIT(UCSRC_help,UCSZ1);
	SET_BIT(UCSRC_help,UCSZ0);
	CLR_BIT(UCSRC_help,UCPOL);
	UCSRC = UCSRC_help ;

	UBRRH = 0 ;
	UBRRL = 51 ;
}
void UART_VidSendData(u8 Copy_U8Data){
	while ( !GET_BIT(UCSRA,UDRE) );
	UDR = Copy_U8Data ;
}

u8 UART_VidRecieveData(){
	return UDR ;
}

void UART_VidSendString (u8 Copy_U8String[]){
	u8 i = 0 ;
	while (Copy_U8String[i] != '\0'){
		UART_VidSendData(Copy_U8String[i]);
		i++ ;
	}
}

void __vector_13(void){
	UART_SetCallBack();
}//end ISR FUNC
