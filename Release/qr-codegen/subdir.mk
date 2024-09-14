################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../qr-codegen/qrcodegen.c 

OBJS += \
./qr-codegen/qrcodegen.o 

C_DEPS += \
./qr-codegen/qrcodegen.d 


# Each subdirectory must supply rules for building sources it contributes
qr-codegen/%.o qr-codegen/%.su qr-codegen/%.cyclo: ../qr-codegen/%.c qr-codegen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-qr-2d-codegen

clean-qr-2d-codegen:
	-$(RM) ./qr-codegen/qrcodegen.cyclo ./qr-codegen/qrcodegen.d ./qr-codegen/qrcodegen.o ./qr-codegen/qrcodegen.su

.PHONY: clean-qr-2d-codegen

