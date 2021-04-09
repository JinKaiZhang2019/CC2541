#######################################
# binaries
#######################################
CC = gcc

DOC = doc
BUILD_DIR = build
C_SOURCES  = \
./Projects/ble/SimpleBLEPeripheral/Source/SimpleBLEPeripheral_Main.c \
./Projects/ble/SimpleBLEPeripheral/Source/OSAL_SimpleBLEPeripheral.c \
./Projects/ble/SimpleBLEPeripheral/Source/simpleBLEPeripheral.c \
./Components/osal/common/OSAL.c \
./Components/osal/common/OSAL_ClockBLE.c \
./Components/osal/common/OSAL_Memory.c \
./Components/osal/common/OSAL_Timers.c \


TARGET = test

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -O2

# C defines
C_DEFS =  \
#-D \

# C includes
C_INCLUDES =  \
-I. \
-I./Projects/ble/SimpleBLEPeripheral/Source \
-I./Projects/ble/common/cc2540 \
-I./Components/hal/target/CC2540EB \
-I./Components/osal/include  \
-I./Components/osal/include \
-I./port \
#-I./Components/hal/include \


CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall 

ifeq ($(DEBUG), 1)
CFLAGS += -g3 -gdwarf-2
endif

# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"

# libraries
LIBS = 
LIBDIR = 
LDFLAGS = 

#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJECTS) Makefile 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR)
	$(CC) -c $(CFLAGS)  $< -o $@

$(BUILD_DIR):
	-mkdir $@

clean:
	-rm -rf $(BUILD_DIR) $(DOC)

.PHONY:doc

doc:
	doxygen


