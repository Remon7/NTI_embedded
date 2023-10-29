################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/ADC_PBcfg.c \
../MCAL/Dio.c \
../MCAL/timer0.c \
../MCAL/timer0_PBcfg.c \
../MCAL/timer1.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/ADC_PBcfg.o \
./MCAL/Dio.o \
./MCAL/timer0.o \
./MCAL/timer0_PBcfg.o \
./MCAL/timer1.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/ADC_PBcfg.d \
./MCAL/Dio.d \
./MCAL/timer0.d \
./MCAL/timer0_PBcfg.d \
./MCAL/timer1.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


