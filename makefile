CC = g++
CFLAGS = -std=c++11 -Wall

BUILD_DIR = build
BIN_DIR = bin

# List of source files
SRCS = graph.cpp main.cpp
# Generate a list of corresponding object files
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# The target executable
TARGET = $(BIN_DIR)/my_program

all: $(TARGET)

# Rule to link the object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile each source file into an object file
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all run clean

bin/my_program: build/graph.o build/main.o
	mkdir -p bin
	g++ -std=c++11 -Wall $^ -o $@