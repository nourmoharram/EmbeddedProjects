################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER/TIMER_Program.c 

OBJS += \
./MCAL/TIMER/TIMER_Program.o 

C_DEPS += \
./MCAL/TIMER/TIMER_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER/%.o: ../MCAL/TIMER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\LOGIN_SYSTEM\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\LOGIN_SYSTEM\APPLICATION" -I"D:\NTI Scholar ship\WorkSpace\LOGIN_SYSTEM\HAL" -I"D:\NTI Scholar ship\WorkSpace\LOGIN_SYSTEM\LIB" -I"D:\NTI Scholar ship\WorkSpace\LOGIN_SYSTEM\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


