################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../epd-lib/Fonts/font12.c \
../epd-lib/Fonts/font12CN.c \
../epd-lib/Fonts/font16.c \
../epd-lib/Fonts/font20.c \
../epd-lib/Fonts/font24.c \
../epd-lib/Fonts/font24CN.c \
../epd-lib/Fonts/font8.c 

OBJS += \
./epd-lib/Fonts/font12.o \
./epd-lib/Fonts/font12CN.o \
./epd-lib/Fonts/font16.o \
./epd-lib/Fonts/font20.o \
./epd-lib/Fonts/font24.o \
./epd-lib/Fonts/font24CN.o \
./epd-lib/Fonts/font8.o 

C_DEPS += \
./epd-lib/Fonts/font12.d \
./epd-lib/Fonts/font12CN.d \
./epd-lib/Fonts/font16.d \
./epd-lib/Fonts/font20.d \
./epd-lib/Fonts/font24.d \
./epd-lib/Fonts/font24CN.d \
./epd-lib/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
epd-lib/Fonts/%.o epd-lib/Fonts/%.su epd-lib/Fonts/%.cyclo: ../epd-lib/Fonts/%.c epd-lib/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-epd-2d-lib-2f-Fonts

clean-epd-2d-lib-2f-Fonts:
	-$(RM) ./epd-lib/Fonts/font12.cyclo ./epd-lib/Fonts/font12.d ./epd-lib/Fonts/font12.o ./epd-lib/Fonts/font12.su ./epd-lib/Fonts/font12CN.cyclo ./epd-lib/Fonts/font12CN.d ./epd-lib/Fonts/font12CN.o ./epd-lib/Fonts/font12CN.su ./epd-lib/Fonts/font16.cyclo ./epd-lib/Fonts/font16.d ./epd-lib/Fonts/font16.o ./epd-lib/Fonts/font16.su ./epd-lib/Fonts/font20.cyclo ./epd-lib/Fonts/font20.d ./epd-lib/Fonts/font20.o ./epd-lib/Fonts/font20.su ./epd-lib/Fonts/font24.cyclo ./epd-lib/Fonts/font24.d ./epd-lib/Fonts/font24.o ./epd-lib/Fonts/font24.su ./epd-lib/Fonts/font24CN.cyclo ./epd-lib/Fonts/font24CN.d ./epd-lib/Fonts/font24CN.o ./epd-lib/Fonts/font24CN.su ./epd-lib/Fonts/font8.cyclo ./epd-lib/Fonts/font8.d ./epd-lib/Fonts/font8.o ./epd-lib/Fonts/font8.su

.PHONY: clean-epd-2d-lib-2f-Fonts

