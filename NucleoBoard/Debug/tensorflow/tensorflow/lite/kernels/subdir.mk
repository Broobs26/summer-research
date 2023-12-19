################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/tensorflow/lite/kernels/kernel_util.cc 

CC_DEPS += \
./tensorflow/tensorflow/lite/kernels/kernel_util.d 

OBJS += \
./tensorflow/tensorflow/lite/kernels/kernel_util.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/kernels/%.o tensorflow/tensorflow/lite/kernels/%.su tensorflow/tensorflow/lite/kernels/%.cyclo: ../tensorflow/tensorflow/lite/kernels/%.cc tensorflow/tensorflow/lite/kernels/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DCORE_CM4 -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../tensorflow -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -I../Hardware/ArduCAM -I../Hardware/I2C -I../Hardware/SPI -I../System/delay -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-kernels

clean-tensorflow-2f-tensorflow-2f-lite-2f-kernels:
	-$(RM) ./tensorflow/tensorflow/lite/kernels/kernel_util.cyclo ./tensorflow/tensorflow/lite/kernels/kernel_util.d ./tensorflow/tensorflow/lite/kernels/kernel_util.o ./tensorflow/tensorflow/lite/kernels/kernel_util.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-kernels

