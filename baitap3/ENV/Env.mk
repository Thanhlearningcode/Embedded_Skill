# Compiler và flags
CC = g++
CFLAGS = -Wall -g -I../Common -I../RAM

# Target executable
TARGET = sim.x

# Source và object files
SOURCES = environment.cpp memory.cpp
OBJECTS = $(SOURCES:.cpp=.o)
RAM_OBJECT = ../RAM/Ram.o

# Default target
all: $(TARGET)

# Liên kết trực tiếp với Ram.o
$(TARGET): $(OBJECTS) $(RAM_OBJECT)
	$(CC) $(OBJECTS) $(RAM_OBJECT) -o $@

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean