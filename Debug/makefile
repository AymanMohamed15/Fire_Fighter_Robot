################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL_DRIVER/subdir.mk
-include HAL_DRIVERS/subdir.mk
-include APP_DRIVER/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TheImtFinalCar.lss \

FLASH_IMAGE += \
TheImtFinalCar.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TheImtFinalCar.elf secondary-outputs

# Tool invocations
TheImtFinalCar.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TheImtFinalCar.map -mmcu=atmega32 -o "TheImtFinalCar.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TheImtFinalCar.lss: TheImtFinalCar.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TheImtFinalCar.elf  >"TheImtFinalCar.lss"
	@echo 'Finished building: $@'
	@echo ' '

TheImtFinalCar.hex: TheImtFinalCar.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TheImtFinalCar.elf  "TheImtFinalCar.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TheImtFinalCar.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TheImtFinalCar.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TheImtFinalCar.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
