################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include OS/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/EXTI_Header/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Push_Button/subdir.mk
-include HAL/LED/subdir.mk
-include CONFIG/subdir.mk
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
Small_OS.lss \

FLASH_IMAGE += \
Small_OS.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Small_OS.elf secondary-outputs

# Tool invocations
Small_OS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Small_OS.map -mmcu=atmega32 -o "Small_OS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Small_OS.lss: Small_OS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Small_OS.elf  >"Small_OS.lss"
	@echo 'Finished building: $@'
	@echo ' '

Small_OS.hex: Small_OS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Small_OS.elf  "Small_OS.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Small_OS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Small_OS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Small_OS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
