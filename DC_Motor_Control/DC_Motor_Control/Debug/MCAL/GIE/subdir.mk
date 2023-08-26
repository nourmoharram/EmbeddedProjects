################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GIE/GIE_Program.c 

OBJS += \
./MCAL/GIE/GIE_Program.o 

C_DEPS += \
./MCAL/GIE/GIE_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GIE/%.o: ../MCAL/GIE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\APPLICATION" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\HAL" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\LIB" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


