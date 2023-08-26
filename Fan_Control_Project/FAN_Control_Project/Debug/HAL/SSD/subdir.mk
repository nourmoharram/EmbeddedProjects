################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SSD/SSD_prg.c 

OBJS += \
./HAL/SSD/SSD_prg.o 

C_DEPS += \
./HAL/SSD/SSD_prg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SSD/%.o: ../HAL/SSD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\FAN_Control_Project\APPLICATION" -I"D:\NTI Scholar ship\WorkSpace\FAN_Control_Project\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\FAN_Control_Project\HAL" -I"D:\NTI Scholar ship\WorkSpace\FAN_Control_Project\LIB" -I"D:\NTI Scholar ship\WorkSpace\FAN_Control_Project\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


