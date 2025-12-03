#ifndef LINK_H
#define LINK_H

typedef struct {
    int r;
    int c;
} Point;

int isinsideboard(Point p);
int isthereblock(int board[24][24], Point start, Point end, int player);
int recursivecheck(int board[24][24], int visited[24][24], Point curr, int player);
int isitwin(int board[24][24], int p);
void initvisited(int limit,int visited[][limit]);
#endif