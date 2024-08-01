# SHELL = cmd.exe

# RM := DEL /F
# RMDIR := RMDIR /S/Q

###############################################################################
# Variables

CG_TOOL_ROOT := C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS

CG_TOOL := $(CG_TOOL_ROOT)/bin/cl2000

PROJECT_ROOT := C:/EmbeddedSignalLogger/C2000/embedded_app

###############################################################################
# Directories

SRC_DIR := .
DRIVERS_DIR := drivers
TI_DRIVERLIB_DIR := third_party/driverlib

OUTPUT_DIR := ./output

###############################################################################
# Source files

APP_SOURCES :=
APP_SOURCES += $(SRC_DIR)/main.c
APP_SOURCES += $(SRC_DIR)/$(DRIVERS_DIR)/device.c
APP_SOURCES += $(SRC_DIR)/$(DRIVERS_DIR)/gpio_driver.c
APP_SOURCES += $(SRC_DIR)/$(DRIVERS_DIR)/pinmux_driver.c
APP_SOURCES += $(SRC_DIR)/$(DRIVERS_DIR)/timer_driver.c
APP_SOURCES += $(SRC_DIR)/$(DRIVERS_DIR)/f28004x_codestartbranch.asm

TI_SOURCES :=
TI_SOURCES += $(SRC_DIR)/$(TI_DRIVERLIB_DIR)/sysctl.c
TI_SOURCES += $(SRC_DIR)/$(TI_DRIVERLIB_DIR)/flash.c
TI_SOURCES += $(SRC_DIR)/$(TI_DRIVERLIB_DIR)/gpio.c
TI_SOURCES += $(SRC_DIR)/$(TI_DRIVERLIB_DIR)/interrupt.c
TI_SOURCES += $(SRC_DIR)/$(TI_DRIVERLIB_DIR)/cputimer.c

ALL_SOURCES :=
ALL_SOURCES += $(APP_SOURCES)
ALL_SOURCES += $(TI_SOURCES)

###############################################################################
# Outputs

ALL_OBJS_TARGET := $(ALL_SOURCES:.c=.obj)
ALL_OBJS_TARGET := $(ALL_OBJS_TARGET:.asm=.obj)
# $(info $(ALL_OBJS_TARGET))

# The final objects are all placed in the output directory
OBJS := $(addprefix $(OUTPUT_DIR)/, $(notdir $(ALL_OBJS_TARGET)))

C_DEPS := $(OBJS:.obj=.d)

EXE_OUTPUTS :=
EXE_OUTPUTS += $(OUTPUT_DIR)/app.out

MAP_OUTPUTS :=
MAP_OUTPUTS += $(OUTPUT_DIR)/app.map

###############################################################################
# Compiler

COMPILE_INCLUDES :=
COMPILE_INCLUDES += --include_path=$(PROJECT_ROOT)
COMPILE_INCLUDES += --include_path=$(PROJECT_ROOT)/$(DRIVERS_DIR)
COMPILE_INCLUDES += --include_path=$(PROJECT_ROOT)/common
COMPILE_INCLUDES += --include_path=$(PROJECT_ROOT)/$(TI_DRIVERLIB_DIR)
COMPILE_INCLUDES += --include_path="C:/ti/c2000/C2000Ware_5_02_00_00"
COMPILE_INCLUDES += --include_path="C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include"

###############################################################################
# Defines
DEFS :=
DEFS += --define=DEBUG

###############################################################################
# Linker

# Lines to run from FLASH
LDSCRIPT = $(SRC_DIR)/28004x_generic_flash_lnk.cmd
DEFS += --define=_FLASH

# Lines to run from RAM
# LDSCRIPT = $(SRC_DIR)/28004x_generic_ram_lnk.cmd


LD_INCLUDES :=
LD_INCLUDES += -i"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/lib"
LD_INCLUDES += -i"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include"
LD_INCLUDES += -i"C:/ti/c2000/C2000Ware_5_02_00_00"

LDLIBS := -llibc.a

LDSTACK := --stack_size=0x3F8
LDHEAP := --heap_size=0x200

###############################################################################
# TARGETS

# All Target
all: $(ALL_OBJS_TARGET) $(LDSCRIPT)
	@$(MAKE) --no-print-directory -Onone $(EXE_OUTPUTS)


%.obj: %.asm
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	@$(CG_TOOL) -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff $(COMPILE_INCLUDES) $(DEFS) --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(OUTPUT_DIR)/$(basename $(<F)).d" --output_file="$(OUTPUT_DIR)/$(basename $(<F)).obj" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: %.c
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	@$(CG_TOOL) -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff $(COMPILE_INCLUDES) $(DEFS) --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(OUTPUT_DIR)/$(basename $(<F)).d" --output_file="$(OUTPUT_DIR)/$(basename $(<F)).obj" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

# Tool invocations
%.out: $(OBJS) $(LDSCRIPT)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	@$(CG_TOOL) -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff $(DEFS) --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m$(MAP_OUTPUTS) $(LDHEAP) $(LDSTACK) --warn_sections $(LD_INCLUDES) --reread_libs --define=_FLASH --diag_wrap=off --display_error_number --entry_point=code_start --rom_model -o $(EXE_OUTPUTS) $(OBJS) $(LDSCRIPT) $(LDLIBS)
	@echo 'Finished building target: "$@"'
	@echo ' '

clean:
	-@rm -f $(EXE_OUTPUTS)
	-@rm -f $(OBJS)
	-@rm -f $(C_DEPS)
	-@rm -f $(MAP_OUTPUTS)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:


ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif
