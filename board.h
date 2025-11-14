#ifndef BOARD_H
#define BOARD_H
#include "structures.h"

void setboard(Board *board);
void printboard(Board *board);
int place(Board *board,int row,int col, int p);

#endif