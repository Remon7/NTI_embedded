################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM.c \
../HAL/LCD.c \
../HAL/keypad.c \
../HAL/segment7_driver.c 

OBJS += \
./HAL/EEPROM.o \
./HAL/LCD.o \
./HAL/keypad.o \
./HAL/segment7_driver.o 

C_DEPS += \
./HAL/EEPROM.d \
./HAL/LCD.d \
./HAL/keypad.d \
./HAL/segment7_driver.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


