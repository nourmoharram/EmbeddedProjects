################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MCAL/Timer1/TIMER_1_Program.c 

OBJS += \
./src/MCAL/Timer1/TIMER_1_Program.o 

C_DEPS += \
./src/MCAL/Timer1/TIMER_1_Program.d 


# Each subdirectory must supply rules for building sources it contributes
src/MCAL/Timer1/%.o: ../src/MCAL/Timer1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\APP" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\ADC" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\DC_MOTOR_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LCD_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LDR" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LM35" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\WIFI_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\DIO_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\EXTI_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\Global_Interrupt_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\PORT_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\TIME0_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\Timer1" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\UART_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\CONFIG" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\LIB" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


