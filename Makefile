# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall 

# Source files
SRCS = kopier.c SFinfo.c main.c

# Target executable
TARGET = solver.out

# Default target
all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean up
clean:
	rm -f $(TARGET)