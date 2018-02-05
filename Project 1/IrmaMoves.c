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
            strncpy(&board[a][b], "F", 8);
        }
    }
    
    return board;
    
}

void printMapBoard(char **board) {
    block();
    for (int c=0; c < ROW; c++) {
        for (int d=0; d<COL; d++) {
            printf("%c ", board[c][d]);
            if(d==7) {
                printf("\n");
            }
        }
    }
    block();
}
