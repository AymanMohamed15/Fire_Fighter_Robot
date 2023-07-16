/*******************************************************************************************/
/********************Auther: Andrew Ashraf      ********************************************/
/********************File : PROGRAM of Line Sensor     *************************************/
/********************Date : 20/2/2023            *******************************************/
/********************Version : First version    ********************************************/
/*******************************************************************************************/
#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include "../MCAL_DRIVER/DIO_interface.h"
#include "LineSensor_configure.h"
#include "LineSensor_interface.h"

/*
 * Description : Initialize Line Sensors to enable read values
 * Arguments   : void
 * return      : void
 */
void LINESENSOR_VidInit(void)
{
	DIO_VidsetpinDirection(LINESENSOR_PORT,RIGHT_LINESENSOR_PIN,LOW);
	DIO_VidsetpinDirection(LINESENSOR_PORT,LEFT_LINESENSOR_PIN,LOW);
}

/*
 * Description : Read input of right Line Sensor
 * Arguments   : Location of Line Sensor:Left or Right
 * return      : u8 the read
 * WHITE return zero
 * BLACK return one
 */
u8 LINESENSOR_VidRightRead()
{
	return DIO_U8GetPinValue(LINESENSOR_PORT,RIGHT_LINESENSOR_PIN);
}

/*
 * Description : Read input of left Line Sensor
 * Arguments   : Location of Line Sensor:Left or Right
 * return      : u8 the read
 * WHITE return zero
 * BLACK return one
 */
u8 LINESENSOR_VidLeftRead()
{
	return  DIO_U8GetPinValue(LINESENSOR_PORT,LEFT_LINESENSOR_PIN);
}
