################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/FINGER_PRINT/Finger_Print_Program_v3.c 

OBJS += \
./HAL/FINGER_PRINT/Finger_Print_Program_v3.o 

C_DEPS += \
./HAL/FINGER_PRINT/Finger_Print_Program_v3.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/FINGER_PRINT/%.o: ../HAL/FINGER_PRINT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\HAL" -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\LIB" -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


