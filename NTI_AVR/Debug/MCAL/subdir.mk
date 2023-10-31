################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/ADC_PBcfg.c \
../MCAL/Dio.c \
../MCAL/SPI.c \
../MCAL/SPI_PBcfg.c \
../MCAL/TWI.c \
../MCAL/TWI_PBcfg.c \
../MCAL/USART.c \
../MCAL/timer0.c \
../MCAL/timer1.c \
../MCAL/timer_PBcfg.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/ADC_PBcfg.o \
./MCAL/Dio.o \
./MCAL/SPI.o \
./MCAL/SPI_PBcfg.o \
./MCAL/TWI.o \
./MCAL/TWI_PBcfg.o \
./MCAL/USART.o \
./MCAL/timer0.o \
./MCAL/timer1.o \
./MCAL/timer_PBcfg.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/ADC_PBcfg.d \
./MCAL/Dio.d \
./MCAL/SPI.d \
./MCAL/SPI_PBcfg.d \
./MCAL/TWI.d \
./MCAL/TWI_PBcfg.d \
./MCAL/USART.d \
./MCAL/timer0.d \
./MCAL/timer1.d \
./MCAL/timer_PBcfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


