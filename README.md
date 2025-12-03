# Twixt (CLI Version)

A command-line implementation of the classic board game **Twixt**, written in C.

## Project Structure

* **`main.c`**: Contains the game loop, input handling, and turn logic.

* **`board.c`**: Handles board initialization and printing the grid.

* **`link.c`**: Contains the core game logic (Knight's moves, blocking rules, and DFS pathfinding).

* **`board.h`**: Header definitions for board operations.

* **`link.h`**: Header definitions for game logic and structures.

* **`Makefile`**: Script to compile and run the project easily.

## How to Play

### Prerequisites

You need a C compiler (like `gcc`) and `make` installed on your system.

### Compilation & Running

1. Open your terminal in the folder containing these files.

2. **To compile and start the game immediately:**

   ```bash
   make run
