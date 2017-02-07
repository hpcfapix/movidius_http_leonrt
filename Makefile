# ------------------------------[ App ]--------------------------------------------#
# Default application name is the same as the folder it is in.
# This can be overridden here if something different is required
#APPNAME ?= $(notdir $(shell pwd))

# Verbose or not, common out for more verbosity
ECHO ?= @

# ------------------------------[ Build overrides ]--------------------------------#
# overrides that need to be set before including generic.mk
#ShaveSymObject   = $(DirAppObjDir)/$(APPNAME).sym.o

MV_SOC_PLATFORM ?= myriad2
MV_SOC_REV      ?= ma2150
EVM_BOARD_USED  ?= MV0182
LEON_RT_BUILD   ?= yes

# Ensure that the we are using the correct rtems libs etc
MV_SOC_OS = rtems
RTEMS_BUILD_NAME = b-prebuilt

#Component lists:
ComponentList_LOS += PipePrint
ComponentList_LRT += PipePrint Board182

# ------------------------------[ Tools ]------------------------------------------#
# Hardcode tool version here if needed, otherwise defaults to Latest
#MV_TOOLS_VERSION ?=

# Set MV_COMMON_BASE relative to mdk directory location (but allow user to override in environment)
MV_COMMON_BASE  ?= ../../../common

# Include the generic Makefile
include $(MV_COMMON_BASE)/generic.mk

# Specific Linker 
LinkerScript    =  ./scripts/ld/custom.ldscript

# -------------------------------- [ Build Options ] ------------------------------ #
# App related build options
CCOPT     += -D$(EVM_BOARD_USED)
CCOPT_LRT += -D$(EVM_BOARD_USED) 
CCOPT_LRT += -I$(MV_TOOLS_DIR)/00.50.79.2/common/rtems/prebuilt/ma2x5x/lib/include

# Extra app related options

# Testing related options
TEST_TYPE        := AUTO
TEST_TAGS        := "MA2150,TCL_MA2150, MA2450"