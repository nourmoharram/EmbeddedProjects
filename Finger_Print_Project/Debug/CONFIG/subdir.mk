################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONFIG/CLCD_LCFG.c \
../CONFIG/Dio_Lcfg.c \
../CONFIG/FINGER_PRINT_LCONFIG.c \
../CONFIG/GIE_LCONFIG.c \
../CONFIG/Port_Lcfg.c \
../CONFIG/USART_LCONFIG.c 

OBJS += \
./CONFIG/CLCD_LCFG.o \
./CONFIG/Dio_Lcfg.o \
./CONFIG/FINGER_PRINT_LCONFIG.o \
./CONFIG/GIE_LCONFIG.o \
./CONFIG/Port_Lcfg.o \
./CONFIG/USART_LCONFIG.o 

C_DEPS += \
./CONFIG/CLCD_LCFG.d \
./CONFIG/Dio_Lcfg.d \
./CONFIG/FINGER_PRINT_LCONFIG.d \
./CONFIG/GIE_LCONFIG.d \
./CONFIG/Port_Lcfg.d \
./CONFIG/USART_LCONFIG.d 


# Each subdirectory must supply rules for building sources it contributes
CONFIG/%.o: ../CONFIG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\CONFIG" -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\HAL" -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\LIB" -I"D:\NTI Scholar ship\WorkSpace\Finger_Print_Project\MCAL" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


