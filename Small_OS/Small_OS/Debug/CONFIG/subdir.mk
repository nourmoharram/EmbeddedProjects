################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONFIG/Dio_Lcfg.c \
../CONFIG/EXTI_LCONFIG.c \
../CONFIG/GIE_LCONFIG.c \
../CONFIG/LED_LCFG.c \
../CONFIG/OS_LCONFIG.c \
../CONFIG/Port_Lcfg.c \
../CONFIG/TIMER_1_LCONFIG.c \
../CONFIG/TIMER_LCFG.c 

OBJS += \
./CONFIG/Dio_Lcfg.o \
./CONFIG/EXTI_LCONFIG.o \
./CONFIG/GIE_LCONFIG.o \
./CONFIG/LED_LCFG.o \
./CONFIG/OS_LCONFIG.o \
./CONFIG/Port_Lcfg.o \
./CONFIG/TIMER_1_LCONFIG.o \
./CONFIG/TIMER_LCFG.o 

C_DEPS += \
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
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\Small_OS\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\OS" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\HAL" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\LIB" -I"D:\NTI Scholar ship\WorkSpace\Small_OS\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


