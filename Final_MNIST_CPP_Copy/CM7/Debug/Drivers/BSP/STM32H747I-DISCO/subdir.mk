################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.c \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.c \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.c \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.c \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.c \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.c \
../Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.c 

C_DEPS += \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.d \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.d \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.d \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.d \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.d \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.d \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.d 

OBJS += \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.o \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.o \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.o \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.o \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.o \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.o \
./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H747I-DISCO/%.o Drivers/BSP/STM32H747I-DISCO/%.su Drivers/BSP/STM32H747I-DISCO/%.cyclo: ../Drivers/BSP/STM32H747I-DISCO/%.c Drivers/BSP/STM32H747I-DISCO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H747I-2d-DISCO

clean-Drivers-2f-BSP-2f-STM32H747I-2d-DISCO:
	-$(RM) ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery.su ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_bus.su ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_camera.su ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_lcd.su ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_qspi.su ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sd.su ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.cyclo ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.d ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.o ./Drivers/BSP/STM32H747I-DISCO/stm32h747i_discovery_sdram.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H747I-2d-DISCO

