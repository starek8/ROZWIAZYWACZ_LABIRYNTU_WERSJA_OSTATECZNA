# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall 

# Source files
SRCS = kopier.c SFinfo.c main.c flooder.c follower.c zapisz_w_bin.c bin_to_sf.c sf_to_bin.c

# Target executable
TARGET = solver.out

# Default target
all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean up
clean:
	rm -f $(TARGET)