################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/model.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_power_spectrum_data.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_simple_features_data.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator_test.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_model_settings.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_power_spectrum_data.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_simple_features_data.cc 

CC_DEPS += \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/model.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_power_spectrum_data.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_simple_features_data.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator_test.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_model_settings.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_power_spectrum_data.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_simple_features_data.d 

OBJS += \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/model.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_power_spectrum_data.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_simple_features_data.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator_test.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_model_settings.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_power_spectrum_data.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_simple_features_data.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/%.o tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/%.su tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/%.cyclo: ../tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/%.cc tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-micro_speech-2f-simple_features

clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-micro_speech-2f-simple_features:
	-$(RM) ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/model.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/model.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/model.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/model.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_power_spectrum_data.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_power_spectrum_data.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_power_spectrum_data.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_power_spectrum_data.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_simple_features_data.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_simple_features_data.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_simple_features_data.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/no_simple_features_data.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_features_generator_test.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_model_settings.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_model_settings.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_model_settings.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/simple_model_settings.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_power_spectrum_data.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_power_spectrum_data.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_power_spectrum_data.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_power_spectrum_data.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_simple_features_data.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_simple_features_data.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_simple_features_data.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/simple_features/yes_simple_features_data.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-micro_speech-2f-simple_features

