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
C_OBJECTS  := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCES)) external/cjson/cJSON.o

all: external/concord/lib/libdiscord.a external/sqlite/build-output/lib/libsqlite3.a \
	$(C_OBJECTS)
	@echo -e "\033[1;36m[ LD ]\033[0m objects -> binary"
	@$(CC) $(C_OBJECTS) -Lexternal/concord/lib -Lexternal/sqlite/build-output/lib -lm -lsqlite3 -ldiscord -lcurl -pthread -lpthread -o $(TARGET_DIR)/justbot  
	@echo -e "\033[1;92mCompilation success!\033[0m"

submodules:
	@echo -e "\033[1;36m[ MOD ]\033[0m downloading submodules"
	@git submodule update --init --recursive

external/concord/lib/libdiscord.a: submodules
	@echo -e "\033[1;36m[ MOD ]\033[0m concord library"
	@make -C external/concord
	@mkdir -p external/include/concord 
	@cp external/concord/include/*.h external/concord/core/*.h external/concord/gencodecs/*.h external/include/concord

external/cjson/cJSON.o: submodules
	@echo -e "\033[1;36m[ MOD ]\033[0m cjson library"
	@make -C external/cjson

external/sqlite/build-output/lib/libsqlite3.a:
	@echo -e "\033[1;36m[ MOD ]\033[0m sqlite"
	@sh -c "cd external/sqlite && exec ./configure --prefix=./build-output --disable-shared --enable-static"
	@make -C external/sqlite
	@make -C external/sqlite install

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo -e "\033[1;36m[ CC ]\033[0m $< -> $@"
	@$(CC) -c $(CFLAGS) $< -o $@

run: all
	@echo -e "\033[1;36m[ RUN ]\033[0m $(TARGET_DIR)/justbot"
	@dotenv -f .env run $(TARGET_DIR)/justbot

-include $(C_OBJECTS:.o=.d)
