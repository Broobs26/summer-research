################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/signal/tensorflow_core/ops/delay_op.cc \
../tensorflow/signal/tensorflow_core/ops/fft_ops.cc \
../tensorflow/signal/tensorflow_core/ops/window_op.cc 

CC_DEPS += \
./tensorflow/signal/tensorflow_core/ops/delay_op.d \
./tensorflow/signal/tensorflow_core/ops/fft_ops.d \
./tensorflow/signal/tensorflow_core/ops/window_op.d 

OBJS += \
./tensorflow/signal/tensorflow_core/ops/delay_op.o \
./tensorflow/signal/tensorflow_core/ops/fft_ops.o \
./tensorflow/signal/tensorflow_core/ops/window_op.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/signal/tensorflow_core/ops/%.o tensorflow/signal/tensorflow_core/ops/%.su tensorflow/signal/tensorflow_core/ops/%.cyclo: ../tensorflow/signal/tensorflow_core/ops/%.cc tensorflow/signal/tensorflow_core/ops/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-signal-2f-tensorflow_core-2f-ops

clean-tensorflow-2f-signal-2f-tensorflow_core-2f-ops:
	-$(RM) ./tensorflow/signal/tensorflow_core/ops/delay_op.cyclo ./tensorflow/signal/tensorflow_core/ops/delay_op.d ./tensorflow/signal/tensorflow_core/ops/delay_op.o ./tensorflow/signal/tensorflow_core/ops/delay_op.su ./tensorflow/signal/tensorflow_core/ops/fft_ops.cyclo ./tensorflow/signal/tensorflow_core/ops/fft_ops.d ./tensorflow/signal/tensorflow_core/ops/fft_ops.o ./tensorflow/signal/tensorflow_core/ops/fft_ops.su ./tensorflow/signal/tensorflow_core/ops/window_op.cyclo ./tensorflow/signal/tensorflow_core/ops/window_op.d ./tensorflow/signal/tensorflow_core/ops/window_op.o ./tensorflow/signal/tensorflow_core/ops/window_op.su

.PHONY: clean-tensorflow-2f-signal-2f-tensorflow_core-2f-ops

