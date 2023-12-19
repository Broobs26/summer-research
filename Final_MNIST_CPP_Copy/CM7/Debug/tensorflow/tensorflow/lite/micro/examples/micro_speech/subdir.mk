################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock_test.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_test.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder_test.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_mock_test.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_test.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/main.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/main_functions.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/micro_speech_test.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands.cc \
../tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands_test.cc 

CC_DEPS += \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock_test.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_test.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder_test.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_mock_test.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_test.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/main.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/main_functions.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/micro_speech_test.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands.d \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands_test.d 

OBJS += \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock_test.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_test.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder_test.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_mock_test.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_test.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/main.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/main_functions.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/micro_speech_test.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands.o \
./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands_test.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/micro/examples/micro_speech/%.o tensorflow/tensorflow/lite/micro/examples/micro_speech/%.su tensorflow/tensorflow/lite/micro/examples/micro_speech/%.cyclo: ../tensorflow/tensorflow/lite/micro/examples/micro_speech/%.cc tensorflow/tensorflow/lite/micro/examples/micro_speech/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-micro_speech

clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-micro_speech:
	-$(RM) ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_mock_test.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/audio_provider_test.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/command_responder_test.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_mock_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_mock_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_mock_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_mock_test.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/feature_provider_test.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main_functions.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main_functions.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main_functions.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/main_functions.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/micro_speech_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/micro_speech_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/micro_speech_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/micro_speech_test.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands.su ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands_test.cyclo ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands_test.d ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands_test.o ./tensorflow/tensorflow/lite/micro/examples/micro_speech/recognize_commands_test.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-examples-2f-micro_speech

