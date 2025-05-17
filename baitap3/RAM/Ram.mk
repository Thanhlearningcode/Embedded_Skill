# Ram.mk
# Compiler và flags
CC = g++
CFLAGS = -Wall -g -I../Common

# Target "library"
TARGET = Ram.a

# Source và object files
SOURCES = Ram.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Tạo file giả lập (không thực sự là thư viện tĩnh)
$(TARGET): $(OBJECTS)
	touch $@

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean