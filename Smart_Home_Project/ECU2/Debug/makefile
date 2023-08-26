################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/MCAL/UART_AHMED/subdir.mk
-include src/MCAL/Timer1/subdir.mk
-include src/MCAL/TIME0_AHMED/subdir.mk
-include src/MCAL/PORT_AHMED/subdir.mk
-include src/MCAL/Global_Interrupt_AHMED/subdir.mk
-include src/MCAL/EXTI_AHMED/subdir.mk
-include src/MCAL/DIO_AHMED/subdir.mk
-include src/MCAL/ADC/subdir.mk
-include src/HAL/WIFI_AHMED/subdir.mk
-include src/HAL/LM35/subdir.mk
-include src/HAL/LED/subdir.mk
-include src/HAL/LDR/subdir.mk
-include src/HAL/LCD_AHMED/subdir.mk
-include src/HAL/DC_MOTOR_AHMED/subdir.mk
-include src/CONFIG/subdir.mk
-include src/APP/subdir.mk
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
smartHome_proj.lss \

FLASH_IMAGE += \
smartHome_proj.hex \

EEPROM_IMAGE += \
smartHome_proj.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: smartHome_proj.elf secondary-outputs

# Tool invocations
smartHome_proj.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,smartHome_proj.map -mmcu=atmega32 -o "smartHome_proj.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

smartHome_proj.lss: smartHome_proj.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S smartHome_proj.elf  >"smartHome_proj.lss"
	@echo 'Finished building: $@'
	@echo ' '

smartHome_proj.hex: smartHome_proj.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex smartHome_proj.elf  "smartHome_proj.hex"
	@echo 'Finished building: $@'
	@echo ' '

smartHome_proj.eep: smartHome_proj.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex smartHome_proj.elf  "smartHome_proj.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: smartHome_proj.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 smartHome_proj.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) smartHome_proj.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
