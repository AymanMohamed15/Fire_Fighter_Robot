/******************************************************************************************/
/********************Auther: Andrew Ashraf      *******************************************/
/********************File : INTERFACE of  Line Sensor     *********************************/
/********************Date : 20/2/2023            ******************************************/
/********************Version : First version    *******************************************/
/******************************************************************************************/



#ifndef LINESENSOR_INTERFACE_H_
#define LINESENSOR_INTERFACE_H_

/*
 * Description : Initialize Line Sensors to enable read values
 * Arguments   : void
 * return      : void
 */
void LINESENSOR_VidInit(void);

/*
 * Description : Read input of right Line Sensor
 * Arguments   : Location of Line Sensor:Left or Right
 * return      : u8 the read
 * WHITE return zero
 * BLACK return one
 */
u8 LINESENSOR_VidRightRead();

/*
 * Description : Read input of left Line Sensor
 * Arguments   : Location of Line Sensor:Left or Right
 * return      : u8 the read
 * WHITE return zero
 * BLACK return one
 */
u8 LINESENSOR_VidLeftRead();

#endif 
