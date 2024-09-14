################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../epd-lib/e-Paper/EPD_2in13d.c \
../epd-lib/e-Paper/ImageData.c 

OBJS += \
./epd-lib/e-Paper/EPD_2in13d.o \
./epd-lib/e-Paper/ImageData.o 

C_DEPS += \
./epd-lib/e-Paper/EPD_2in13d.d \
./epd-lib/e-Paper/ImageData.d 


# Each subdirectory must supply rules for building sources it contributes
epd-lib/e-Paper/%.o epd-lib/e-Paper/%.su epd-lib/e-Paper/%.cyclo: ../epd-lib/e-Paper/%.c epd-lib/e-Paper/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-epd-2d-lib-2f-e-2d-Paper

clean-epd-2d-lib-2f-e-2d-Paper:
	-$(RM) ./epd-lib/e-Paper/EPD_2in13d.cyclo ./epd-lib/e-Paper/EPD_2in13d.d ./epd-lib/e-Paper/EPD_2in13d.o ./epd-lib/e-Paper/EPD_2in13d.su ./epd-lib/e-Paper/ImageData.cyclo ./epd-lib/e-Paper/ImageData.d ./epd-lib/e-Paper/ImageData.o ./epd-lib/e-Paper/ImageData.su

.PHONY: clean-epd-2d-lib-2f-e-2d-Paper

