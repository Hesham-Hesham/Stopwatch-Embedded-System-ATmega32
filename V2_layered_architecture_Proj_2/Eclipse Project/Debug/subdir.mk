################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../decoder_for_six_sevenSegments.c \
../external_interrupt.c \
../gpio.c \
../lcd.c \
../main.c \
../timer1.c 

OBJS += \
./decoder_for_six_sevenSegments.o \
./external_interrupt.o \
./gpio.o \
./lcd.o \
./main.o \
./timer1.o 

C_DEPS += \
./decoder_for_six_sevenSegments.d \
./external_interrupt.d \
./gpio.d \
./lcd.d \
./main.d \
./timer1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


