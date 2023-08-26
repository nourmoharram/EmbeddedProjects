################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GIE/GIE_prog.c 

OBJS += \
./MCAL/GIE/GIE_prog.o 

C_DEPS += \
./MCAL/GIE/GIE_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GIE/%.o: ../MCAL/GIE/%.c MCAL/GIE/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\APP" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\Buzzer" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\CLCD" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\EEPROM_24C08" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\FINGERPRINT" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\KPD" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\Relay" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\RTC" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\LIB" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\DIO" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\GIE" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\PORT" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\TIMER0" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\TWI" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\USART" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\CONFIG" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\Buzzer" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\CLCD" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\EEPROM_24C08" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\KPD" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\Relay" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\HAL\RTC" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\LIB" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\DIO" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\GIE" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\PORT" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\TIMER0" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\TWI" -I"D:\JoKeR Folder\My Courses\NTI\AVR_WorkSpace\SmartHome_Project\MCAL\USART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


