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
#define ROW 8
#define COL 8

void block() {
    printf("= = = = = = = =\n");
}

char **createMapBoard(void) {
    
    static char *board[ROW];
    for (int i=0; i<ROW; i++) {
        board[i] = (char *)malloc(COL * sizeof(char));
    }
    
    if (*board == NULL)
    {
        printf("malloc failed!\n");
        exit(1);
    }
    
    for (int a=0; a<ROW; a++) {
        for (int b=0; b<COL; b++) {
            strlcpy(&board[a][b], " ", 8);
        }
    }
    
    
    for (int z=0; z<2; z++) { copy F values onto board
    
        if (z==1) {
            strlcpy(&board[z][z], "F", 8);
            strlcpy(&board[z+1][z], "F", 8);
            strlcpy(&board[z+1][z+1], "F", 8);
            strlcpy(&board[z+2][z+1], "F", 8);
        }
    }
    strlcpy(&board[4][3], "K", 8); here we copy the individual K and individual B ones
    strlcpy(&board[5][4], "B", 8);
    for (int z=0; z<=2; z++) { this loop pushes C values to the array
        if(z==0) {
            strlcpy(&board[5][z], "C", 8);
        }
        if (z==1) {
            strlcpy(&board[6][z], "C", 8);
        }
        if (z==2) {
            strlcpy(&board[6][z], "C", 8);
            strlcpy(&board[7][z], "C", 8);
        }
    }
    
    for (int z=5; z<8; z++) {
        if (z==5) {
            strlcpy(&board[6][z], "D", 8);
        }
        if (z==6) {
            strlcpy(&board[7][z], "D", 8);
            strlcpy(&board[7][z+1], "D", 8);
        }
    }
    
    return board;
    
}

/*
char **destroyMapBoard(char **board) {
    printf("memory allocated for board: %d", malloc_size(board));
    free(board);
    printf("memory allocated for board: %d", malloc_size(board));
} */

void printMapBoard(char **board) {
    block();
    for (int c=0; c < ROW; c++) {
        for (int d=0; d<COL; d++) {
            printf("%s ", &board[c][d]);
            if(d==7) {
                printf("\n");
            }
        }
    }
    block();
}
