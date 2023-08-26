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
-include HAL/KPD/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
-include HAL/CLCD/subdir.mk
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
DC_Motor_Control.lss \

FLASH_IMAGE += \
DC_Motor_Control.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DC_Motor_Control.elf secondary-outputs

# Tool invocations
DC_Motor_Control.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DC_Motor_Control.map -mmcu=atmega32 -o "DC_Motor_Control.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DC_Motor_Control.lss: DC_Motor_Control.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DC_Motor_Control.elf  >"DC_Motor_Control.lss"
	@echo 'Finished building: $@'
	@echo ' '

DC_Motor_Control.hex: DC_Motor_Control.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DC_Motor_Control.elf  "DC_Motor_Control.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DC_Motor_Control.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DC_Motor_Control.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DC_Motor_Control.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
