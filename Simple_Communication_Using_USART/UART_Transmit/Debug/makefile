################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART/subdir.mk
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
-include HAL/DC_MOTOR/subdir.mk
-include HAL/CLCD/subdir.mk
-include HAL/BUZZER/subdir.mk
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
UART_Transmit.lss \

FLASH_IMAGE += \
UART_Transmit.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: UART_Transmit.elf secondary-outputs

# Tool invocations
UART_Transmit.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UART_Transmit.map -mmcu=atmega32 -o "UART_Transmit.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UART_Transmit.lss: UART_Transmit.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UART_Transmit.elf  >"UART_Transmit.lss"
	@echo 'Finished building: $@'
	@echo ' '

UART_Transmit.hex: UART_Transmit.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UART_Transmit.elf  "UART_Transmit.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UART_Transmit.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 UART_Transmit.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UART_Transmit.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
