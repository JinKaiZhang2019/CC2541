#######################################
# binaries
#######################################
CC = gcc

DOC = doc
BUILD_DIR = build
C_SOURCES  = \
./App/SimpleBLEPeripheral_Main.c \
./App/OSAL_SimpleBLEPeripheral.c \
./App/simpleBLEPeripheral.c \
./osal/common/OSAL.c \
./osal/common/OSAL_Memory.c \
./osal/common/OSAL_ClockBLE.c \
./osal/common/OSAL_Timers.c \


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
-I./App \
-I./osal/include \
-I./port \


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


