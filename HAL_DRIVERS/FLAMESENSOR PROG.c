#include "../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include <avr/delay.h>
#include "../MCAL_DRIVER/DIO_INTERFACE.h"


#define A 0
#define B 1
#define C 2
#define D 3

u8 detect1;
u8 detect2;


u8 FLAMEDETECT_VID1 ()
{
//check if there is a flame or not
detect1=DIO_U8GetPinValue(2,0);


//buzzer works then move to the flame and stop then end the flame by water

	return detect1;



}

u8 FLAMEDETECT_VID2 ()
{
//check if there is a flame or not
detect2=DIO_U8GetPinValue(2,2);


//buzzer works then move to the flame and stop then end the flame by water

return detect2;


}
