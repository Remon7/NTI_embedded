################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Button.c \
../HAL/Dc_motor.c \
../HAL/FingerPrint_Interface.c \
../HAL/Keypad.c \
../HAL/LED_INTERFACING.c \
../HAL/LM35_INTERACE.c \
../HAL/Lcd.c \
../HAL/RTC_INTERFACE.c \
../HAL/Seven_Segment_INTERFACE.c \
../HAL/Ultrasonic.c \
../HAL/eeprom_INTERFACE.c 

OBJS += \
./HAL/Button.o \
./HAL/Dc_motor.o \
./HAL/FingerPrint_Interface.o \
./HAL/Keypad.o \
./HAL/LED_INTERFACING.o \
./HAL/LM35_INTERACE.o \
./HAL/Lcd.o \
./HAL/RTC_INTERFACE.o \
./HAL/Seven_Segment_INTERFACE.o \
./HAL/Ultrasonic.o \
./HAL/eeprom_INTERFACE.o 

C_DEPS += \
./HAL/Button.d \
./HAL/Dc_motor.d \
./HAL/FingerPrint_Interface.d \
./HAL/Keypad.d \
./HAL/LED_INTERFACING.d \
./HAL/LM35_INTERACE.d \
./HAL/Lcd.d \
./HAL/RTC_INTERFACE.d \
./HAL/Seven_Segment_INTERFACE.d \
./HAL/Ultrasonic.d \
./HAL/eeprom_INTERFACE.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\3u\C++\Mini Projects\Nti_R7\HAL\inc" -I"D:\3u\C++\Mini Projects\Nti_R7\UTILITIES\inc" -I"D:\3u\C++\Mini Projects\Nti_R7\inc" -I"D:\3u\C++\Mini Projects\Nti_R7\MCAL\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


