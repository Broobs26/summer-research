################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/tensorflow/lite/micro/kernels/ceva/ceva_common.cc \
../tensorflow/tensorflow/lite/micro/kernels/ceva/conv.cc \
../tensorflow/tensorflow/lite/micro/kernels/ceva/depthwise_conv.cc \
../tensorflow/tensorflow/lite/micro/kernels/ceva/fully_connected.cc \
../tensorflow/tensorflow/lite/micro/kernels/ceva/logistic.cc \
../tensorflow/tensorflow/lite/micro/kernels/ceva/quantize.cc \
../tensorflow/tensorflow/lite/micro/kernels/ceva/softmax.cc 

CC_DEPS += \
./tensorflow/tensorflow/lite/micro/kernels/ceva/ceva_common.d \
./tensorflow/tensorflow/lite/micro/kernels/ceva/conv.d \
./tensorflow/tensorflow/lite/micro/kernels/ceva/depthwise_conv.d \
./tensorflow/tensorflow/lite/micro/kernels/ceva/fully_connected.d \
./tensorflow/tensorflow/lite/micro/kernels/ceva/logistic.d \
./tensorflow/tensorflow/lite/micro/kernels/ceva/quantize.d \
./tensorflow/tensorflow/lite/micro/kernels/ceva/softmax.d 

OBJS += \
./tensorflow/tensorflow/lite/micro/kernels/ceva/ceva_common.o \
./tensorflow/tensorflow/lite/micro/kernels/ceva/conv.o \
./tensorflow/tensorflow/lite/micro/kernels/ceva/depthwise_conv.o \
./tensorflow/tensorflow/lite/micro/kernels/ceva/fully_connected.o \
./tensorflow/tensorflow/lite/micro/kernels/ceva/logistic.o \
./tensorflow/tensorflow/lite/micro/kernels/ceva/quantize.o \
./tensorflow/tensorflow/lite/micro/kernels/ceva/softmax.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/micro/kernels/ceva/%.o tensorflow/tensorflow/lite/micro/kernels/ceva/%.su tensorflow/tensorflow/lite/micro/kernels/ceva/%.cyclo: ../tensorflow/tensorflow/lite/micro/kernels/ceva/%.cc tensorflow/tensorflow/lite/micro/kernels/ceva/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-kernels-2f-ceva

clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-kernels-2f-ceva:
	-$(RM) ./tensorflow/tensorflow/lite/micro/kernels/ceva/ceva_common.cyclo ./tensorflow/tensorflow/lite/micro/kernels/ceva/ceva_common.d ./tensorflow/tensorflow/lite/micro/kernels/ceva/ceva_common.o ./tensorflow/tensorflow/lite/micro/kernels/ceva/ceva_common.su ./tensorflow/tensorflow/lite/micro/kernels/ceva/conv.cyclo ./tensorflow/tensorflow/lite/micro/kernels/ceva/conv.d ./tensorflow/tensorflow/lite/micro/kernels/ceva/conv.o ./tensorflow/tensorflow/lite/micro/kernels/ceva/conv.su ./tensorflow/tensorflow/lite/micro/kernels/ceva/depthwise_conv.cyclo ./tensorflow/tensorflow/lite/micro/kernels/ceva/depthwise_conv.d ./tensorflow/tensorflow/lite/micro/kernels/ceva/depthwise_conv.o ./tensorflow/tensorflow/lite/micro/kernels/ceva/depthwise_conv.su ./tensorflow/tensorflow/lite/micro/kernels/ceva/fully_connected.cyclo ./tensorflow/tensorflow/lite/micro/kernels/ceva/fully_connected.d ./tensorflow/tensorflow/lite/micro/kernels/ceva/fully_connected.o ./tensorflow/tensorflow/lite/micro/kernels/ceva/fully_connected.su ./tensorflow/tensorflow/lite/micro/kernels/ceva/logistic.cyclo ./tensorflow/tensorflow/lite/micro/kernels/ceva/logistic.d ./tensorflow/tensorflow/lite/micro/kernels/ceva/logistic.o ./tensorflow/tensorflow/lite/micro/kernels/ceva/logistic.su ./tensorflow/tensorflow/lite/micro/kernels/ceva/quantize.cyclo ./tensorflow/tensorflow/lite/micro/kernels/ceva/quantize.d ./tensorflow/tensorflow/lite/micro/kernels/ceva/quantize.o ./tensorflow/tensorflow/lite/micro/kernels/ceva/quantize.su ./tensorflow/tensorflow/lite/micro/kernels/ceva/softmax.cyclo ./tensorflow/tensorflow/lite/micro/kernels/ceva/softmax.d ./tensorflow/tensorflow/lite/micro/kernels/ceva/softmax.o ./tensorflow/tensorflow/lite/micro/kernels/ceva/softmax.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-kernels-2f-ceva

