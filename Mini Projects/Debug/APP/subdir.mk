################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/App.c 

OBJS += \
./APP/App.o 

C_DEPS += \
./APP/App.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\AVR\Nti_R7\HAL\inc" -I"D:\NTI\AVR\Nti_R7\APP" -I"D:\NTI\AVR\Nti_R7\UTILITIES\inc" -I"D:\NTI\AVR\Nti_R7\inc" -I"D:\NTI\AVR\Nti_R7\MCAL\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


