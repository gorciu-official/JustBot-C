CC         ?= cc

DEBUG      ?= false

CFLAGS     := $(shell tr '\n' ' ' < compile_flags.txt)

ifeq ($(DEBUG),true)
TARGET_DIR := target/debug
CFLAGS     += -g
else
TARGET_DIR := target/release
endif

SRC_DIR    := src
OBJ_DIR    := $(TARGET_DIR)/obj

C_SOURCES  := $(shell find $(SRC_DIR) -type f -name '*.c')
C_OBJECTS  := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCES))

all: concord $(C_OBJECTS)
	@echo -e "\033[1;36m[ LD ]\033[0m objects -> binary"
	@$(CC) $(C_OBJECTS) -Lexternal/concord/lib -ldiscord -lcurl -pthread -lpthread -o $(TARGET_DIR)/justbot  
	@echo -e "\033[1;92mCompilation success!\033[0m"

concord:
	@echo -e "\033[1;36m[ MOD ]\033[0m concord library"
	@git submodule update --init --recursive
	@make -C external/concord

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -e "\033[1;36m[ CC ]\033[0m $< -> $@"
	@$(CC) -c $(CFLAGS) $< -o $@

run: all
	@echo -e "\033[1;36m[ RUN ]\033[0m $(TARGET_DIR)/justbot"
	@dotenv -f .env run $(TARGET_DIR)/justbot

-include $(C_OBJECTS:.o=.d)
