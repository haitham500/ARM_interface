################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MAFIO_program.c \
../Src/MGPIO_program.c \
../Src/MNVIC_program.c \
../Src/MRCC_program.c \
../Src/MSCB_program.c \
../Src/MSTK_program.c \
../Src/MUSART_program.c \
../Src/main.c 

OBJS += \
./Src/MAFIO_program.o \
./Src/MGPIO_program.o \
./Src/MNVIC_program.o \
./Src/MRCC_program.o \
./Src/MSCB_program.o \
./Src/MSTK_program.o \
./Src/MUSART_program.o \
./Src/main.o 

C_DEPS += \
./Src/MAFIO_program.d \
./Src/MGPIO_program.d \
./Src/MNVIC_program.d \
./Src/MRCC_program.d \
./Src/MSCB_program.d \
./Src/MSTK_program.d \
./Src/MUSART_program.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/MAFIO_program.d ./Src/MAFIO_program.o ./Src/MAFIO_program.su ./Src/MGPIO_program.d ./Src/MGPIO_program.o ./Src/MGPIO_program.su ./Src/MNVIC_program.d ./Src/MNVIC_program.o ./Src/MNVIC_program.su ./Src/MRCC_program.d ./Src/MRCC_program.o ./Src/MRCC_program.su ./Src/MSCB_program.d ./Src/MSCB_program.o ./Src/MSCB_program.su ./Src/MSTK_program.d ./Src/MSTK_program.o ./Src/MSTK_program.su ./Src/MUSART_program.d ./Src/MUSART_program.o ./Src/MUSART_program.su ./Src/main.d ./Src/main.o ./Src/main.su

.PHONY: clean-Src

