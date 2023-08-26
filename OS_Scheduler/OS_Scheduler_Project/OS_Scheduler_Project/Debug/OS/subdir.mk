################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../OS/croutine.c \
../OS/heap_1.c \
../OS/list.c \
../OS/port.c \
../OS/queue.c \
../OS/tasks.c \
../OS/timers.c 

OBJS += \
./OS/croutine.o \
./OS/heap_1.o \
./OS/list.o \
./OS/port.o \
./OS/queue.o \
./OS/tasks.o \
./OS/timers.o 

C_DEPS += \
./OS/croutine.d \
./OS/heap_1.d \
./OS/list.d \
./OS/port.d \
./OS/queue.d \
./OS/tasks.d \
./OS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
OS/%.o: ../OS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI_Scholar_ship\FreeRTOS\APP" -I"D:\NTI_Scholar_ship\FreeRTOS\SERVICE" -I"D:\NTI_Scholar_ship\FreeRTOS\CONFIG" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Buzzer" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\CLCD" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\LED" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Push_Button" -I"D:\NTI_Scholar_ship\FreeRTOS\HAL\Relay" -I"D:\NTI_Scholar_ship\FreeRTOS\LIB" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\ADC" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\DIO" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\EXTI" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\GIE" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\PORT" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\TIMER" -I"D:\NTI_Scholar_ship\FreeRTOS\MCAL\TIMER1" -I"D:\NTI_Scholar_ship\FreeRTOS\OS" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


