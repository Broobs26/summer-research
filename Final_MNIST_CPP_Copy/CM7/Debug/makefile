################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include tensorflow/tensorflow/lite/micro/testing/subdir.mk
-include tensorflow/tensorflow/lite/micro/memory_planner/subdir.mk
-include tensorflow/tensorflow/lite/micro/kernels/subdir.mk
-include tensorflow/tensorflow/lite/micro/subdir.mk
-include tensorflow/tensorflow/lite/kernels/internal/subdir.mk
-include tensorflow/tensorflow/lite/kernels/subdir.mk
-include tensorflow/tensorflow/lite/core/api/subdir.mk
-include tensorflow/tensorflow/lite/c/subdir.mk
-include Utilites/lcd/subdir.mk
-include Models/subdir.mk
-include Middlewares/ST/STM32_ImageProcessing_Library/Src/subdir.mk
-include Drivers/STM32H7xx_HAL_Driver/subdir.mk
-include Drivers/BSP/STM32H747I-DISCO/subdir.mk
-include Drivers/BSP/Components/ov9655/subdir.mk
-include Drivers/BSP/Components/ov5640/subdir.mk
-include Drivers/BSP/Components/otm8009a/subdir.mk
-include Drivers/BSP/Components/mt25tl01g/subdir.mk
-include Drivers/BSP/Components/is42s32800j/subdir.mk
-include Drivers/BSP/Components/adv7533/subdir.mk
-include Core/images/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/TF/subdir.mk
-include Core/Src/subdir.mk
-include Common/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := STM32H747I-DISCO_CPP_CM7
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32H747I-DISCO_CPP_CM7.elf \

MAP_FILES += \
STM32H747I-DISCO_CPP_CM7.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32H747I-DISCO_CPP_CM7.list \


# All Target
all: main-build

# Main-build Target
main-build: STM32H747I-DISCO_CPP_CM7.elf secondary-outputs

# Tool invocations
STM32H747I-DISCO_CPP_CM7.elf STM32H747I-DISCO_CPP_CM7.map: $(OBJS) $(USER_OBJS) C:\Pitt\ Classes\Summer\ 2023\Final_MNIST_CPP_Copy\CM7\STM32H747XIHX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-g++ -o "STM32H747I-DISCO_CPP_CM7.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Pitt Classes\Summer 2023\Final_MNIST_CPP_Copy\CM7\STM32H747XIHX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32H747I-DISCO_CPP_CM7.map" -Wl,--gc-sections -static -u _printf_float --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32H747I-DISCO_CPP_CM7.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32H747I-DISCO_CPP_CM7.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) STM32H747I-DISCO_CPP_CM7.elf STM32H747I-DISCO_CPP_CM7.list STM32H747I-DISCO_CPP_CM7.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
