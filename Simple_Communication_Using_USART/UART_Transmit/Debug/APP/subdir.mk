################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/main_UART_Sender.c 

OBJS += \
./APP/main_UART_Sender.o 

C_DEPS += \
./APP/main_UART_Sender.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\UART_Transmit\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\UART_Transmit\HAL" -I"D:\NTI Scholar ship\WorkSpace\UART_Transmit\LIB" -I"D:\NTI Scholar ship\WorkSpace\UART_Transmit\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


