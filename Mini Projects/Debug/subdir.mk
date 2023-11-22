################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_PROJECT.c \
../Duty_Config.c \
../Login_System.c \
../OS.c 

OBJS += \
./ADC_PROJECT.o \
./Duty_Config.o \
./Login_System.o \
./OS.o 

C_DEPS += \
./ADC_PROJECT.d \
./Duty_Config.d \
./Login_System.d \
./OS.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\AVR\Nti_R7\HAL\inc" -I"D:\NTI\AVR\Nti_R7\UTILITIES\inc" -I"D:\NTI\AVR\Nti_R7\inc" -I"D:\NTI\AVR\Nti_R7\MCAL\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


