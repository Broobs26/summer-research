################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Models/mnistMulti.cpp \
../Models/mnistMulti_chunk1.cpp \
../Models/mnistMulti_chunk2.cpp \
../Models/mnistMulti_chunk3.cpp \
../Models/model.cpp \
../Models/model_all.cpp 

OBJS += \
./Models/mnistMulti.o \
./Models/mnistMulti_chunk1.o \
./Models/mnistMulti_chunk2.o \
./Models/mnistMulti_chunk3.o \
./Models/model.o \
./Models/model_all.o 

CPP_DEPS += \
./Models/mnistMulti.d \
./Models/mnistMulti_chunk1.d \
./Models/mnistMulti_chunk2.d \
./Models/mnistMulti_chunk3.d \
./Models/model.d \
./Models/model_all.d 


# Each subdirectory must supply rules for building sources it contributes
Models/%.o Models/%.su Models/%.cyclo: ../Models/%.cpp Models/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DCORE_CM4 -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../tensorflow -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Models

clean-Models:
	-$(RM) ./Models/mnistMulti.cyclo ./Models/mnistMulti.d ./Models/mnistMulti.o ./Models/mnistMulti.su ./Models/mnistMulti_chunk1.cyclo ./Models/mnistMulti_chunk1.d ./Models/mnistMulti_chunk1.o ./Models/mnistMulti_chunk1.su ./Models/mnistMulti_chunk2.cyclo ./Models/mnistMulti_chunk2.d ./Models/mnistMulti_chunk2.o ./Models/mnistMulti_chunk2.su ./Models/mnistMulti_chunk3.cyclo ./Models/mnistMulti_chunk3.d ./Models/mnistMulti_chunk3.o ./Models/mnistMulti_chunk3.su ./Models/model.cyclo ./Models/model.d ./Models/model.o ./Models/model.su ./Models/model_all.cyclo ./Models/model_all.d ./Models/model_all.o ./Models/model_all.su

.PHONY: clean-Models

