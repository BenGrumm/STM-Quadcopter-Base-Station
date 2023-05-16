# ==========================================
#   Unity Project - A Test Framework for C
#   Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
#   [Released under MIT License. Please refer to license.txt for details]
# ==========================================

#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

CC=gcc
ifeq ($(shell uname -s), Darwin)
CC=clang
endif

PROJECT_ROOT = ..
BUILD_DIR = ../build/test_build
UNITY_ROOT= ../tools/Unity

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wno-misleading-indentation

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)

SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  $(PROJECT_ROOT)/Src/average/average.c \
  TestAverage.c \
  test_runners/TestProductionCode_Runner.c \
  test_runners/all_tests.c

INC_DIRS=\
  -I$(PROJECT_ROOT)/Inc \
  -I$(PROJECT_ROOT)/Inc/average \
  -I$(UNITY_ROOT)/src \
  -I$(UNITY_ROOT)/extras/fixture/src \
  -I$(UNITY_ROOT)/extras/memory/src

CFLAGS += $(INC_DIRS)

SYMBOLS=-DUNITY_FIXTURE_NO_EXTRAS

# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(SRC_FILES1:.c=.o)))
vpath %.c $(sort $(dir $(SRC_FILES1)))

all: $(TARGET1) run

run:
	- ./$(TARGET1) -v

$(TARGET1): $(OBJECTS)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BUILD_DIR):
	mkdir $@

clean:
	$(CLEANUP) $(TARGET1)
	-rm -rf $(BUILD_DIR)

ci: CFLAGS += -Werror
ci: default
