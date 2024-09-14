################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../epd-lib/GUI/GUI_Paint_new.c 

OBJS += \
./epd-lib/GUI/GUI_Paint_new.o 

C_DEPS += \
./epd-lib/GUI/GUI_Paint_new.d 


# Each subdirectory must supply rules for building sources it contributes
epd-lib/GUI/%.o epd-lib/GUI/%.su epd-lib/GUI/%.cyclo: ../epd-lib/GUI/%.c epd-lib/GUI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-epd-2d-lib-2f-GUI

clean-epd-2d-lib-2f-GUI:
	-$(RM) ./epd-lib/GUI/GUI_Paint_new.cyclo ./epd-lib/GUI/GUI_Paint_new.d ./epd-lib/GUI/GUI_Paint_new.o ./epd-lib/GUI/GUI_Paint_new.su

.PHONY: clean-epd-2d-lib-2f-GUI

