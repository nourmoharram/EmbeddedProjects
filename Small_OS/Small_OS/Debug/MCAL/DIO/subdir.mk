################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/Dio_prg.c 

OBJS += \
./MCAL/DIO/Dio_prg.o 

C_DEPS += \
./MCAL/DIO/Dio_prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\Small_OS\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\OS" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\HAL" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\LIB" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


