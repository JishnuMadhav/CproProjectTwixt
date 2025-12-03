#include "link.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isinsideboard(Point p) {
    int z = 0;
    if(p.r >= 0 && p.r < 24 && p.c >= 0 && p.c < 24){
        z = 1;
    }
    if(z == 1){
        return 1;
    }
    else return 0;  
}

void initvisited(int limit,int visited[][limit]){
    for (int i = 0; i < limit; i++){
        for (int j = 0; j < limit; j++){
            visited[i][j] = 0;
        }
    }
}

static int moves[8][2] = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {1, -2},  {1, 2},  {2, -1},  {2, 1}
};

int isthereblock(int board[24][24], Point start, Point end, int player) {
    int enemy = (player == 1) ? 2 : 1;
    
    if(board[start.r][end.c] == enemy && board[end.r][start.c] == enemy) {
        return 1;
    }
    return 0;
}

int recursivecheck(int board[24][24], int visited[24][24], Point curr, int player) {
    if((player == 1 && curr.r == 23) || (player == 2 && curr.c == 23)) {
        return 1;
    }
    visited[curr.r][curr.c] = 1;
    for (int k = 0; k < 8; k++) {
        Point next;
        next.r = curr.r + moves[k][0];
        next.c = curr.c + moves[k][1];

        if(isinsideboard(next)) {
            if(board[next.r][next.c] == player && !visited[next.r][next.c]) {
                if(!isthereblock(board, curr, next, player)) {
                    if(recursivecheck(board, visited, next, player)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int isitwin(int board[24][24], int p) {
    int visited[24][24];
    initvisited(24,visited);
    int limit = 23; 
    
    for(int i = 1; i < limit; i++) {
        Point start;
        if(p == 1) {
            start.r = 0;
            start.c = i;
        }
        else {
            start.r = i;
            start.c = 0;
        }
        if(board[start.r][start.c] == p) {
            if(recursivecheck(board, visited, start, p)) {
                return 1;
            }
        }
    }
    return 0;
}