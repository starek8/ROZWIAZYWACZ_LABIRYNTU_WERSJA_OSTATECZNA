# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall 

# Source files
SRCS = main.c

# Target executable
TARGET = solver

# Default target
all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean up
clean:
	rm -f $(TARGET)