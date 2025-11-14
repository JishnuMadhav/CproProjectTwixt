#include "structures.h"
#include "board.h"
#include<stdio.h>

void setboard(Board *board){
    for(int i = 0; i < 24; i ++){
        for(int j = 0; j < 24; j ++){
            board->grid[i][j].owner = 0;
        }
    }
}

void printboard(Board *board){
    printf("    ");
    for (int i = 0; i < 24; i++){
        printf("%2d  ",i+1);
    }
    printf("\n");
    printf("   +");
    for (int i = 0; i < 24; i++){
        printf("---+");
    }
    printf("\n");


    for (int i = 0; i < 24; i++){
        printf("%2d |",i+1);
        for (int j = 0; j < 24; j++){
            char sign;
            if(board->grid[i][j].owner == 0) sign = '.';
            else if(board->grid[i][j].owner == 1) sign = 'R';
            else sign = 'B';
            printf(" %c |",sign);
        }
        printf("\n");
        printf("   +");
        for (int j = 0; j < 24; j++){
            printf("---+");
        }
        printf("\n");
        
    }
}

int place(Board *board,int row,int col, int p){
    if(board->grid[row][col].owner != 0) return 0;

    board->grid[row][col].owner = p;
    return 1;
}