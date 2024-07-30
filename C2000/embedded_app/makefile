# SHELL = cmd.exe

# RM := DEL /F
# RMDIR := RMDIR /S/Q

CG_TOOL_ROOT := C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS
CG_TOOL := $(CG_TOOL_ROOT)/bin/cl2000

###############################################################################
# Linkerscript

LDSCRIPT = ./28004x_generic_flash_lnk.cmd

CMD_SRCS :=
CMD_SRCS += $(LDSCRIPT)

C_SRCS :=
C_SRCS += ./main.c

C_SRCS__QUOTED :=
C_SRCS__QUOTED += "./main.c"

OBJS :=
OBJS += ./Debug/main.obj

C_DEPS :=
C_DEPS += ./Debug/main.d

EXE_OUTPUTS :=
EXE_OUTPUTS += ./Debug/app.out

###############################################################################
# Includes

COMPILE_INCLUDES :=
COMPILE_INCLUDES += --include_path="C:/Users/ddominguezmoises/OneDrive - Tesla/Desktop/MastersApplication/EmbeddedLearning_C2000_OpenSource/app"
COMPILE_INCLUDES += --include_path="C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include"

LDLIBS := -llibc.a

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# All Target
all: $(OBJS) $(CMD_SRCS)
	@$(MAKE) --no-print-directory -Onone "./Debug/app.out"

%.obj: ../%.c
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	@$(CG_TOOL) -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 $(COMPILE_INCLUDES) -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="./Debug/$(basename $(<F)).d" --output_file="./Debug/$(basename $(<F)).obj" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

# Tool invocations
./Debug/app.out: $(OBJS) $(CMD_SRCS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	@$(CG_TOOL) -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi -z -m"./Debug/app.map" --stack_size=0x200 --warn_sections -i"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/lib" -i"C:/ti/ccs1271/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --reread_libs --diag_wrap=off --display_error_number --xml_link_info="./Debug/app_linkInfo.xml" --rom_model -o "./Debug/app.out" $(OBJS) $(LDSCRIPT) $(LDLIBS)
	@echo 'Finished building target: "$@"'
	@echo ' '

clean:
	-@rm $(EXE_OUTPUTS)
	-@rm $(OBJS)
	-@rm $(C_DEPS)
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:


