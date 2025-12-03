#include "board.h"
#include "link.h"
#include <stdio.h>


int main(){
    int board[24][24];
    setboard(board);
    int turn=1,row,col;

    while(1){
        printboard(board);

        if(turn==1)printf("Red's turn enter row and column:");
        else printf("Blue's turn enter row and column:");

        scanf("%d %d",&row,&col);
        row=row-1;
        col=col-1;

        if(row<0||row>=24||col<0||col>=24){
            printf("Please enter values between 1 and 24.\n");
            continue;
        }

        if((row==0&&col==0)||(row==0&&col==23)||(row==23&&col==0)||(row==23&&col==23)){
            printf("Cannot place pin in the corners\n");
            continue;
        }

        if((row==0||row==23)&&turn!=1){
            printf("Only Red can place on the top or bottom rows\n");
            continue;
        }
        if((col==0||col==23)&&turn!=2){
            printf("Only Blue can place on the left or right columns\n");
            continue;
        }

        int res=place(board,row,col,turn);

        if(res==0){
            printf("Point is Occupied, Place somewhere else\n");
            continue;
        }

        int checkwin = isitwin(board,turn);
        if(checkwin == 1){
            printboard(board);
            if(turn == 1){
                printf("\n\033[1;31mRED WINS!\033[0m\n");
            }
            else{
                printf("\n\033[1;34mBLUE WINS!\033[0m\n");
            }
            break;
        }
        if(turn==1)turn=2;
        else turn=1;
    }
}
