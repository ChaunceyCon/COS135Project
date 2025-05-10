# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Executable name
EXEC = guess_country

# Source files
SRCS = main.c menu.c country.c
OBJS = $(SRCS:.c=.o)

# Header files
DEPS = menu.h country.h colors.h

# Build target
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Compile .c files into .o
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -f $(EXEC) *.o