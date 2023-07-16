/****************************AUTHER:Ahmed elsayed *****************************************************************
/********************File: interface of DIO  ***************************************************************************
/********************Date: 3/9/2022 ***************************************************************************
/********************ver:v1**********************************************************************************
/********************Desc: **********************************************************************************
*/

#ifndef  TIMER1_interface_H_
#define  TIMER1_interface_H_


void WDT_VIDEN(void);
void WDT_VIDDIS(void);
void TIMER1_VidInit(void); /*External Interrupts Initialization*/
void TIMER1_SetOCROPWM (u16 prcentage);
void TIMER1_SetSERVOANGLE (u16 angle);
void TIMER1SetCallBack(void (*ptr)(void));
void TIMER1_SetPRELOADVALUE (void);

#endif
