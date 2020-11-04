SRC_DIR     = ./src
INC_DIR     = ./inc
TARGET_DIR  = ./bin
OBJ_DIR     = $(TARGET_DIR)/obj
TARGET      = textgen

CC          = g++
CFLAGS      = -Wall -std=c++11 -pedantic -I$(INC_DIR)

SRCS       := $(wildcard $(SRC_DIR)/*.cpp)
OBJ         = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
DEPS        = $(patsubst %,$(INC_DIR)/%.h, *)

.PHONY: all clean

# make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS) | $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $(TARGET_DIR)/$(TARGET) $^ $(CFLAGS)

clean:
	rm -frd $(OBJ_DIR) $(TARGET_DIR)/*

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
