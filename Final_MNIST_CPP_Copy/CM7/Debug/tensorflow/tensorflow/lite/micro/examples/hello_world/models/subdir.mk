################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tensorflow/tensorflow/lite/micro/examples/hello_world/models/model.cpp 

OBJS += \
./tensorflow/tensorflow/lite/micro/examples/hello_world/models/model.o 

CPP_DEPS += \
./tensorflow/tensorflow/lite/micro/examples/hello_world/models/model.d 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/micro/examples/hello_world/models/%.o tensorflow/tensorflow/lite/micro/examples/hello_world/models/%.su tensorflow/tensorflow/lite/micro/examples/hello_world/models/%.cyclo: ../tensorflow/tensorflow/lite/micro/examples/hello_world/models/%.cpp tensorflow/tensorflow/lite/micro/examples/hello_world/models/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H747xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../tensorflow/third_party/ -I../tensorflow/third_party/gemmlowp -I../tensorflow/third_party/ruy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-hello_world-2f-models

clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-hello_world-2f-models:
	-$(RM) ./tensorflow/tensorflow/lite/micro/examples/hello_world/models/model.cyclo ./tensorflow/tensorflow/lite/micro/examples/hello_world/models/model.d ./tensorflow/tensorflow/lite/micro/examples/hello_world/models/model.o ./tensorflow/tensorflow/lite/micro/examples/hello_world/models/model.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-hello_world-2f-models

