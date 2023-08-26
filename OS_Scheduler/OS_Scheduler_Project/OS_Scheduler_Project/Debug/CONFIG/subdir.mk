################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONFIG/ADC_LCONFIG.c \
../CONFIG/DC_MOTOR_LCONFIG.c \
../CONFIG/Dio_Lcfg.c \
../CONFIG/EXTI_LCONFIG.c \
../CONFIG/GIE_LCONFIG.c \
../CONFIG/LED_LCFG.c \
../CONFIG/OS_LCONFIG.c \
../CONFIG/Port_Lcfg.c \
../CONFIG/TIMER_1_LCONFIG.c \
../CONFIG/TIMER_LCFG.c 

OBJS += \
./CONFIG/ADC_LCONFIG.o \
./CONFIG/DC_MOTOR_LCONFIG.o \
./CONFIG/Dio_Lcfg.o \
./CONFIG/EXTI_LCONFIG.o \
./CONFIG/GIE_LCONFIG.o \
./CONFIG/LED_LCFG.o \
./CONFIG/OS_LCONFIG.o \
./CONFIG/Port_Lcfg.o \
./CONFIG/TIMER_1_LCONFIG.o \
./CONFIG/TIMER_LCFG.o 

C_DEPS += \
./CONFIG/ADC_LCONFIG.d \
./CONFIG/DC_MOTOR_LCONFIG.d \
./CONFIG/Dio_Lcfg.d \
./CONFIG/EXTI_LCONFIG.d \
./CONFIG/GIE_LCONFIG.d \
./CONFIG/LED_LCFG.d \
./CONFIG/OS_LCONFIG.d \
./CONFIG/Port_Lcfg.d \
./CONFIG/TIMER_1_LCONFIG.d \
./CONFIG/TIMER_LCFG.d 


# Each subdirectory must supply rules for building sources it contributes
CONFIG/%.o: ../CONFIG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI_Scholar_ship\FreeRTOS\APP" -I"D:\NTI_Scholar_ship\FreeRTOS\CONFIG" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Buzzer" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\CLCD" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\DC_MOTOR" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\LED" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\LM_35_Sensor" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Push_Button" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Relay" -I"D:\NTI_Scholar_ship\FreeRTOS\LIB" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\ADC" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\DIO" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\EXTI" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\GIE" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\PORT" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\TIMER" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\TIMER1" -I"D:\NTI_Scholar_ship\FreeRTOS\SERVICE" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


