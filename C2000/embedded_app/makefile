# SHELL = cmd.exe

# RM := DEL /F
# RMDIR := RMDIR /S/Q

CG_TOOL_ROOT := C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS
CG_TOOL := $(CG_TOOL_ROOT)/bin/cl2000

###############################################################################
# Linkerscript

LDSCRIPT = ./28004x_generic_flash_lnk.cmd

IN_OBJS :=
IN_OBJS += ./main.obj
IN_OBJS += ./drivers/device.obj

OBJS :=
OBJS += ./Debug/main.obj
OBJS += ./Debug/device.obj

C_DEPS :=
C_DEPS += ./Debug/main.d
C_DEPS += ./Debug/device.d

EXE_OUTPUTS :=
EXE_OUTPUTS += ./Debug/app.out

MAP_OUTPUTS :=
MAP_OUTPUTS += ./Debug/app.map

###############################################################################
# Includes

COMPILE_INCLUDES :=
COMPILE_INCLUDES += --include_path="C:/Users/ddominguezmoises/OneDrive - Tesla/Desktop/MastersApplication/EmbeddedLearning_C2000_OpenSource/app"
COMPILE_INCLUDES += --include_path="C:/Users/ddominguezmoises/OneDrive - Tesla/Desktop/MastersApplication/EmbeddedLearning_C2000_OpenSource/app/drivers"
COMPILE_INCLUDES += --include_path="C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include"

LDLIBS := -llibc.a

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# All Target
all: $(IN_OBJS) $(LDSCRIPT)
	@$(MAKE) --no-print-directory -Onone $(EXE_OUTPUTS)

%.obj: %.c
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	@$(CG_TOOL) -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 $(COMPILE_INCLUDES) -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="./Debug/$(basename $(<F)).d" --output_file="./Debug/$(basename $(<F)).obj" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

# Tool invocations
%.out: $(OBJS) $(LDSCRIPT)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	@$(CG_TOOL) -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi -z -m$(MAP_OUTPUTS) --stack_size=0x200 --warn_sections -i"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/lib" -i"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --rom_model -o $(EXE_OUTPUTS) $(OBJS) $(LDSCRIPT) $(LDLIBS)
	@echo 'Finished building target: "$@"'
	@echo ' '

clean:
	-@rm $(EXE_OUTPUTS)
	-@rm $(OBJS)
	-@rm $(C_DEPS)
	-@rm $(MAP_OUTPUTS)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:


