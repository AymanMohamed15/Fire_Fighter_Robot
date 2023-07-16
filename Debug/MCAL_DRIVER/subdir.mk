################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_DRIVER/DIO_PROG.c \
../MCAL_DRIVER/GIE_PROG.c \
../MCAL_DRIVER/TIMER1_PROG.c \
../MCAL_DRIVER/TIMER2_PROG.c \
../MCAL_DRIVER/TIMER_PROG.c \
../MCAL_DRIVER/UART_Prg.c 

OBJS += \
./MCAL_DRIVER/DIO_PROG.o \
./MCAL_DRIVER/GIE_PROG.o \
./MCAL_DRIVER/TIMER1_PROG.o \
./MCAL_DRIVER/TIMER2_PROG.o \
./MCAL_DRIVER/TIMER_PROG.o \
./MCAL_DRIVER/UART_Prg.o 

C_DEPS += \
./MCAL_DRIVER/DIO_PROG.d \
./MCAL_DRIVER/GIE_PROG.d \
./MCAL_DRIVER/TIMER1_PROG.d \
./MCAL_DRIVER/TIMER2_PROG.d \
./MCAL_DRIVER/TIMER_PROG.d \
./MCAL_DRIVER/UART_Prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_DRIVER/%.o: ../MCAL_DRIVER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


