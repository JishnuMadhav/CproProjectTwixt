CC = gcc
# -I . tells gcc to look for header files (.h) in the current directory
CFLAGS = -I .
SOURCES = main.c board.c link.c
TARGET = twixt

# Default rule: Compiles the game
all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Run rule: Compiles (if needed) and then runs the game immediately
run: all
	./$(TARGET)

# Clean rule: Deletes the compiled executable
clean:
	rm -f $(TARGET)