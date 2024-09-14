################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../epd-lib/Config/DEV_Config.c 

OBJS += \
./epd-lib/Config/DEV_Config.o 

C_DEPS += \
./epd-lib/Config/DEV_Config.d 


# Each subdirectory must supply rules for building sources it contributes
epd-lib/Config/%.o epd-lib/Config/%.su epd-lib/Config/%.cyclo: ../epd-lib/Config/%.c epd-lib/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-epd-2d-lib-2f-Config

clean-epd-2d-lib-2f-Config:
	-$(RM) ./epd-lib/Config/DEV_Config.cyclo ./epd-lib/Config/DEV_Config.d ./epd-lib/Config/DEV_Config.o ./epd-lib/Config/DEV_Config.su

.PHONY: clean-epd-2d-lib-2f-Config

