################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONFIG/CLCD_LCFG.c \
../CONFIG/DC_MOTOR_LCONFIG.c \
../CONFIG/Dio_Lcfg.c \
../CONFIG/EXTI_LCONFIG.c \
../CONFIG/GIE_LCONFIG.c \
../CONFIG/KPD_LCFG.c \
../CONFIG/LED_LCFG.c \
../CONFIG/Port_Lcfg.c \
../CONFIG/SSD_LCFG.c \
../CONFIG/TIMER_1_LCONFIG.c \
../CONFIG/TIMER_LCFG.c 

OBJS += \
./CONFIG/CLCD_LCFG.o \
./CONFIG/DC_MOTOR_LCONFIG.o \
./CONFIG/Dio_Lcfg.o \
./CONFIG/EXTI_LCONFIG.o \
./CONFIG/GIE_LCONFIG.o \
./CONFIG/KPD_LCFG.o \
./CONFIG/LED_LCFG.o \
./CONFIG/Port_Lcfg.o \
./CONFIG/SSD_LCFG.o \
./CONFIG/TIMER_1_LCONFIG.o \
./CONFIG/TIMER_LCFG.o 

C_DEPS += \
./CONFIG/CLCD_LCFG.d \
./CONFIG/DC_MOTOR_LCONFIG.d \
./CONFIG/Dio_Lcfg.d \
./CONFIG/EXTI_LCONFIG.d \
./CONFIG/GIE_LCONFIG.d \
./CONFIG/KPD_LCFG.d \
./CONFIG/LED_LCFG.d \
./CONFIG/Port_Lcfg.d \
./CONFIG/SSD_LCFG.d \
./CONFIG/TIMER_1_LCONFIG.d \
./CONFIG/TIMER_LCFG.d 


# Each subdirectory must supply rules for building sources it contributes
CONFIG/%.o: ../CONFIG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\APPLICATION" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\HAL" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\LIB" -I"D:\NTI Scholar ship\WorkSpace\DC_Motor_Control\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


