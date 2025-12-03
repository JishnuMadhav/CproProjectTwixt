#include "board.h"
#include <stdio.h>

void setboard(int board[24][24]){
    for(int i=0;i<24;i++){
        for(int j=0;j<24;j++){
            board[i][j]=0;
        }
    }
}

void printboard(int board[24][24]){
    printf("\n    ");
    for(int i=0;i<24;i++){
        printf("\033[33m%2d  \033[0m",i+1);
    }
    printf("\n");
    printf("   \033[90m+");
    for(int i=0;i<23;i++) printf("---+");
    printf("---+\033[0m\n");
    for(int i=0;i<24;i++){
        printf("\033[33m%2d \033[90m|",i+1);
    
        for(int j=0;j<24;j++){
            if((i==0&&j==0)||(i==0&&j==23)||(i==23&&j==0)||(i==23&&j==23)){
                 printf("   \033[90m|");
                 continue;
            }
            if(board[i][j]==0){
                printf(" . \033[90m|");
            }
            else if(board[i][j]==1){
                printf(" \033[1;31m●\033[0m \033[90m|");
            }
            else{
                printf(" \033[1;34m●\033[0m \033[90m|");
            }
        }
        printf("\033[0m\n");

        if(i<23){
            printf("   \033[90m+");
            for(int k=0;k<23;k++) printf("---+");
            printf("---+\033[0m\n");
        }
    }
    printf("   \033[90m+");
    for(int i=0;i<23;i++) printf("---+");
    printf("---+\033[0m\n");
}

int place(int board[24][24],int row,int col,int p){
    if((row==0&&col==0)||(row==0&&col==23)||(row==23&&col==0)||(row==23&&col==23)) return -1;
    if(board[row][col]!=0) return 0;
    board[row][col]=p;
    return 1;
}