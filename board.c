#include "board.h"
#include <stdio.h>

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void setboard(int board[24][24]){
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            board[i][j]=0;
        }
    }
}

void printboard(int board[24][24]){
    printf("    ");
    for(int i=0;i<24;i++) printf("%2d  ",i+1);
    printf("\n   +");
    for(int i=0;i<24;i++) printf("---+");
    printf("\n");

    for(int i=0;i<24;i++){
        printf("%2d |",i+1);
        for(int j=0;j<24;j++){
            if((i==0&&j==0)||(i==0&&j==23)||(i==23&&j==0)||(i==23&&j==23)){
                printf(" X |");
                continue;
            }
            if(board[i][j]==0) printf(" . |");
            else if(board[i][j]==1) printf(" %sR%s |",RED,RESET);
            else printf(" %sB%s |",BLUE,RESET);
        }
        printf("\n   +");
        for(int j=0;j<24;j++) printf("---+");
        printf("\n");
    }
}

int place(int board[24][24],int row,int col,int p){
    if((row==0&&col==0)||(row==0&&col==23)||(row==23&&col==0)||(row==23&&col==23))return -1;
    if(board[row][col]!=0)return 0;
    board[row][col]=p;
    return 1;
}
