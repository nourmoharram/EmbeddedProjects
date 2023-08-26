################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/CONFIG/ADC_Lcfg.c \
../src/CONFIG/Dio_Lcfg.c \
../src/CONFIG/EXTI_INT_Lcfg.c \
../src/CONFIG/LCD_Lcfg.c \
../src/CONFIG/LDR_Lcfg.c \
../src/CONFIG/LED_Lcfg.c \
../src/CONFIG/LM35_Lcfg.c \
../src/CONFIG/Motor_Lcfg.c \
../src/CONFIG/Port_Lcfg.c \
../src/CONFIG/TIMER0_Lcfg.c \
../src/CONFIG/UART_Lcfg.c 

OBJS += \
./src/CONFIG/ADC_Lcfg.o \
./src/CONFIG/Dio_Lcfg.o \
./src/CONFIG/EXTI_INT_Lcfg.o \
./src/CONFIG/LCD_Lcfg.o \
./src/CONFIG/LDR_Lcfg.o \
./src/CONFIG/LED_Lcfg.o \
./src/CONFIG/LM35_Lcfg.o \
./src/CONFIG/Motor_Lcfg.o \
./src/CONFIG/Port_Lcfg.o \
./src/CONFIG/TIMER0_Lcfg.o \
./src/CONFIG/UART_Lcfg.o 

C_DEPS += \
./src/CONFIG/ADC_Lcfg.d \
./src/CONFIG/Dio_Lcfg.d \
./src/CONFIG/EXTI_INT_Lcfg.d \
./src/CONFIG/LCD_Lcfg.d \
./src/CONFIG/LDR_Lcfg.d \
./src/CONFIG/LED_Lcfg.d \
./src/CONFIG/LM35_Lcfg.d \
./src/CONFIG/Motor_Lcfg.d \
./src/CONFIG/Port_Lcfg.d \
./src/CONFIG/TIMER0_Lcfg.d \
./src/CONFIG/UART_Lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
src/CONFIG/%.o: ../src/CONFIG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\APP" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\ADC" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\DC_MOTOR_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LCD_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LDR" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\LM35" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\HAL\WIFI_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\DIO_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\EXTI_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\Global_Interrupt_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\PORT_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\TIME0_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\Timer1" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL\UART_AHMED" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\CONFIG" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\LIB" -I"D:\embedded_programming\DEY\4-month\Technical\Interfacing\my cont\Smart_Home_ECU2\src\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


