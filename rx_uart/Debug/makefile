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
rx_uart.lss \

FLASH_IMAGE += \
rx_uart.hex \

EEPROM_IMAGE += \
rx_uart.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: rx_uart.elf secondary-outputs

# Tool invocations
rx_uart.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,rx_uart.map -mmcu=atmega16 -o "rx_uart.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

rx_uart.lss: rx_uart.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S rx_uart.elf  >"rx_uart.lss"
	@echo 'Finished building: $@'
	@echo ' '

rx_uart.hex: rx_uart.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex rx_uart.elf  "rx_uart.hex"
	@echo 'Finished building: $@'
	@echo ' '

rx_uart.eep: rx_uart.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex rx_uart.elf  "rx_uart.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: rx_uart.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 rx_uart.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) rx_uart.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
