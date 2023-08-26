################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER1/TIMER_1_Program.c 

OBJS += \
./MCAL/TIMER1/TIMER_1_Program.o 

C_DEPS += \
./MCAL/TIMER1/TIMER_1_Program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER1/%.o: ../MCAL/TIMER1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\UART_Recieve_Project\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\UART_Recieve_Project\HAL" -I"D:\NTI Scholar ship\WorkSpace\UART_Recieve_Project\LIB" -I"D:\NTI Scholar ship\WorkSpace\UART_Recieve_Project\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


