/*

 file: IrmaMoves.c
 date: 3 February 2018
 name: Robert Maloy
 desc: Basic commands for IrmaMoves (tasteless, dude. tasteless.)

  */

/* Only a company as insidious and evil
 as AT&T would come up with a programming
 language as evil and horrible as C. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc/malloc.h> //macOS debug include. Does not work under Microsoft Windows or Linux.
#define ROW 8
#define COL 8

void block() {
    printf("= = = = = = = =\n");
}

char **createMapBoard(void) {
    
    static char *board[ROW]; //static cast because otherwise we can't return it to the original function/main.
    for (int i=0; i<ROW; i++) {
        board[i] = (char *)malloc(COL * sizeof(char));
    }
    
    if (*board == NULL)
    {
        printf("malloc failed!\n"); //fairly obvious.
        exit(1);
    }
    
    for (int a=0; a<ROW; a++) { //40 days and 40 nights of rainfall
        for (int b=0; b<COL; b++) {
            strcpy(&board[a][b], " ");
        }
    }
    
    for (int z=0; z<2; z++) { //copy F values onto board
        board[0][z] = 'F';
        if (z==1) {
            board[z][z] = 'F';
            board[z+1][z] = 'F';
            board[z+1][z+1] = 'F';
            board[z+2][z+1] = 'F';
        }
    }
    board[4][2] = 'K'; //here we copy the individual K and individual B ones
    board[5][3] = 'B';
    for (int z=0; z<=2; z++) { //this loop pushes C values to the array
        if(z==0) {
            board[5][z] = 'C';
        }
        if (z==1) {
            board[6][z] = 'C';
        }
        if (z==2) {
            board[6][z] = 'C';
            board[7][z] = 'C';
        }
    }
    
    for (int z=4; z<7; z++) { //establish the island of Dominica
        if (z==4) {
            board[6][z] = 'D';
        }
        if (z==5) {
            board[7][z] = 'D';
            board[7][z+1] = 'D';
        }
    }
    
    return board;
    
}

//char **destroyMapBoard(char **board) {
//    printf("memory allocated for board: %zu", malloc_size(board));
//    free(board);
//    printf("memory allocated for board: %zu", malloc_size(board));
//    return NULL;
//}

void printMapBoard(char **board) {
    block();
    for (int c=0; c < ROW; c++) {
        for (int d=0; d<COL; d++) {
            /* debug function intended to show us the coordinates of each item on the board
                 printf("coord=%d,%d - val:%c\n", c, d, board[c][d]);
             */
            printf("%c ", board[c][d]);
            if(d==7) {
                printf("\n");
            }
        }
    }
    block();
}
