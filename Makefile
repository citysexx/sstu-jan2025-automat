CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g -lm

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
EXEC_DIR = $(BUILD_DIR)/exec

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

TARGET = $(EXEC_DIR)/GiveMeAutomat

all: $(TARGET)

$(BUILD_DIR) $(EXEC_DIR):
	mkdir -p $@

$(TARGET): $(SRC_FILES) | $(EXEC_DIR)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
