Twixt (CLI Version)

A command-line implementation of the classic board game Twixt, written in C.

Project Structure

Source Files (main.c, board.c, link.c): Core logic and game loop.

Header Files (board.h, link.h): Function declarations and structures.

Makefile: Script to compile and run the project easily.

How to Play

Prerequisites

You need a C compiler (like gcc) and make installed.

Compilation & Running

Open your terminal in this folder.

To compile and run the game in one step:

make run


To clean up compiled files:

make clean


Rules

Red connects Top <-> Bottom.

Blue connects Left <-> Right.

Links are formed by Knight's moves (2 spaces one way, 1 space the other).

Links cannot cross each other.
