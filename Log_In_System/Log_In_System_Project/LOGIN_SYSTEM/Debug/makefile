################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER1/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/EXTI_Header/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/ULTRA_SONIC/subdir.mk
-include HAL/SSD/subdir.mk
-include HAL/Push_Button/subdir.mk
-include HAL/LM_35_Sensor/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/KPD/subdir.mk
-include HAL/CLCD/subdir.mk
-include HAL/BUZZER/subdir.mk
-include CONFIG/subdir.mk
-include APPLICATION/subdir.mk
-include APP/subdir.mk
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
LOGIN_SYSTEM.lss \

FLASH_IMAGE += \
LOGIN_SYSTEM.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: LOGIN_SYSTEM.elf secondary-outputs

# Tool invocations
LOGIN_SYSTEM.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LOGIN_SYSTEM.map -mmcu=atmega32 -o "LOGIN_SYSTEM.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LOGIN_SYSTEM.lss: LOGIN_SYSTEM.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LOGIN_SYSTEM.elf  >"LOGIN_SYSTEM.lss"
	@echo 'Finished building: $@'
	@echo ' '

LOGIN_SYSTEM.hex: LOGIN_SYSTEM.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LOGIN_SYSTEM.elf  "LOGIN_SYSTEM.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LOGIN_SYSTEM.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LOGIN_SYSTEM.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LOGIN_SYSTEM.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
