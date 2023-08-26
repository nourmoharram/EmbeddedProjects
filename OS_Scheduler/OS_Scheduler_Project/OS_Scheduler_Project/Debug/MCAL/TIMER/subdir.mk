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
	avr-gcc -I"D:\NTI_Scholar_ship\FreeRTOS\APP" -I"D:\NTI_Scholar_ship\FreeRTOS\CONFIG" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Buzzer" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\CLCD" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\DC_MOTOR" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\LED" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\LM_35_Sensor" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Push_Button" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Relay" -I"D:\NTI_Scholar_ship\FreeRTOS\LIB" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\ADC" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\DIO" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\EXTI" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\GIE" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\PORT" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\TIMER" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\TIMER1" -I"D:\NTI_Scholar_ship\FreeRTOS\SERVICE" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


