
#include"APP_DRIVER/MULTIPAL_TASKS_CAR_PRIVATE.h"
#include"APP_DRIVER/MULTIPAL_TASKS_INTERFACE.h"


void main(void)
{
	MultipleTasksCar_VidInit();
	MultipleTasksIntialCar_VidInit();

	while (1)

	{
		MultipleTasksLineSensor_MoveCar();
		MultipleTasksFlameSensor_MoveCar();


		DIO_VidTogglePinvalue(1,0);
		DIO_VidTogglePinvalue(3,1);
		DIO_VidTogglePinvalue(3,2);

	}

}

