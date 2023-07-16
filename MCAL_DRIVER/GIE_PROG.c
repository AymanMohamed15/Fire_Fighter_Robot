#include"../LIBARARIES_DRIVER/STD_TYPES.h"
#include "../LIBARARIES_DRIVER/BIT_MATH.h"
#include "GIE_PRIVATE.h"


void GIE_VidEnable(void)
{
/*General Interrupt Enable*/
/*For more info check ATMEGA DS- Status Register Section*/
SET_BIT(SREG,GIE);
	
}
void GIE_VidDisable(void)
{
/*General Interrupt Disable*/
CLR_BIT(SREG,GIE);
	
}
