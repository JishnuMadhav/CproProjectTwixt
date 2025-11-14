#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct{
    int row;
    int col;
}Point;

typedef struct{
    int owner;
}Cell;

typedef struct{
    Cell grid[24][24];
}Board;

#endif



