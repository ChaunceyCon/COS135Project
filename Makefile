CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRC = main.c menu.c game.c add_country.c colors.c

# Output binary
TARGET = guess_country

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up build artifacts
clean:
	rm -f $(TARGET) *.o

