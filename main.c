#include "board.h"
#include<stdio.h>

int main(){
    Board b;
    setboard(&b);
     
    int turn = 1;
    int row, col;
    while (1){
        printboard(&b);
        printf("%s's turn enter row and column:",(turn == 1 ? "Red":"Black"));
        scanf("%d %d", &row, &col);
        row = row-1;
        col = col-1;

        if (row < 0 || row >= 24 || col < 0 || col >= 24) {
            printf("Please enter values between 1 and 24.\n");
            continue;
        }

        if(place(&b,row,col,turn)){
            if(turn == 1){
                turn =2;
            }
            else{
                turn = 1;
            }
        }
        else{
            printf("Cell Already Occupied\n");
        }
    } 
}