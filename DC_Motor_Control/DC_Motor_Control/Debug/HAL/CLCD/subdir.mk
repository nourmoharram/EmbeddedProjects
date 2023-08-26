################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/CLCD/CLCD_Program.c 

OBJS += \
./HAL/CLCD/CLCD_Program.o 

C_DEPS += \
./HAL/CLCD/CLCD_Program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/CLCD/%.o: ../HAL/CLCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\APPLICATION" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\HAL" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\LIB" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


