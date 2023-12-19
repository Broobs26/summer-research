################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_test.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_util.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_test.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_test.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_test.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_test.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_test.cc \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_test.cc 

C_SRCS += \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_io.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_io.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_util.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_io.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_main.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_generator.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_main.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_util.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_lut.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_io.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_util.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_io.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/window.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_io.c \
../tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_util.c 

C_DEPS += \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_io.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_io.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_util.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_io.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_main.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_generator.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_main.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_util.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_lut.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_io.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_util.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_io.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_io.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_util.d 

CC_DEPS += \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_test.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_util.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_test.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_test.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_test.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_test.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_test.d \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_test.d 

OBJS += \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_io.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_test.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_util.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_io.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_test.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_util.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_io.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_main.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_generator.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_main.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_test.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_util.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_lut.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_io.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_test.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_util.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_io.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_test.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_test.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_io.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_test.o \
./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_util.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.o tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.su tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.cyclo: ../tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.cc tensorflow/tensorflow/lite/experimental/microfrontend/lib/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.o tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.su tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.cyclo: ../tensorflow/tensorflow/lite/experimental/microfrontend/lib/%.c tensorflow/tensorflow/lite/experimental/microfrontend/lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-experimental-2f-microfrontend-2f-lib

clean-tensorflow-2f-tensorflow-2f-lite-2f-experimental-2f-microfrontend-2f-lib:
	-$(RM) ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_io.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_io.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_io.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_io.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_test.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_test.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_test.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_test.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_util.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_util.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_util.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/fft_util.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_io.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_io.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_io.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_io.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_test.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_test.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_test.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_test.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_util.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_util.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_util.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/filterbank_util.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_io.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_io.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_io.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_io.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_main.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_main.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_main.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_main.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_generator.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_generator.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_generator.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_generator.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_main.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_main.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_main.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_memmap_main.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_test.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_test.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_test.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_test.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_util.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_util.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_util.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/frontend_util.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/kiss_fft_int16.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_lut.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_lut.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_lut.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_lut.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_io.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_io.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_io.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_io.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_test.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_test.d
	-$(RM) ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_test.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_test.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_util.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_util.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_util.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/log_scale_util.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_io.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_io.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_io.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_io.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_test.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_test.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_test.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_test.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/noise_reduction_util.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_test.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_test.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_test.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_test.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/pcan_gain_control_util.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_io.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_io.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_io.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_io.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_test.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_test.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_test.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_test.su ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_util.cyclo ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_util.d ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_util.o ./tensorflow/tensorflow/lite/experimental/microfrontend/lib/window_util.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-experimental-2f-microfrontend-2f-lib

