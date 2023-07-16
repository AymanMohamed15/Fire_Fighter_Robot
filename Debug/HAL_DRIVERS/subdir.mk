################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_DRIVERS/BlueTooth_prg.c \
../HAL_DRIVERS/DCMOTOR_PROG.c \
../HAL_DRIVERS/FLAMESENSOR\ PROG.c \
../HAL_DRIVERS/LineSensor_prog.c 

OBJS += \
./HAL_DRIVERS/BlueTooth_prg.o \
./HAL_DRIVERS/DCMOTOR_PROG.o \
./HAL_DRIVERS/FLAMESENSOR\ PROG.o \
./HAL_DRIVERS/LineSensor_prog.o 

C_DEPS += \
./HAL_DRIVERS/BlueTooth_prg.d \
./HAL_DRIVERS/DCMOTOR_PROG.d \
./HAL_DRIVERS/FLAMESENSOR\ PROG.d \
./HAL_DRIVERS/LineSensor_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_DRIVERS/%.o: ../HAL_DRIVERS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL_DRIVERS/FLAMESENSOR\ PROG.o: ../HAL_DRIVERS/FLAMESENSOR\ PROG.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"HAL_DRIVERS/FLAMESENSOR PROG.d" -MT"HAL_DRIVERS/FLAMESENSOR\ PROG.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


