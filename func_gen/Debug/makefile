################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
func_gen.lss \

FLASH_IMAGE += \
func_gen.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: func_gen.elf secondary-outputs

# Tool invocations
func_gen.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,func_gen.map -mmcu=atmega16 -o "func_gen.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

func_gen.lss: func_gen.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S func_gen.elf  >"func_gen.lss"
	@echo 'Finished building: $@'
	@echo ' '

func_gen.hex: func_gen.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex func_gen.elf  "func_gen.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: func_gen.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 func_gen.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) func_gen.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
