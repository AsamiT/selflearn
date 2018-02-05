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

#define ARRAY_DIM 8

void block() {
    printf("= = = = = = = =\n");
}

char **createMapBoard(void) {
    //char **board = (char **)calloc(ARRAY_DIM * ARRAY_DIM, sizeof(char));
    char **board[ARRAY_DIM];
    for (int i=0; i < ARRAY_DIM; i++) {
        board[i] = (char **)malloc(ARRAY_DIM * sizeof(char));
    }
    
    if (*board == NULL) { //hey maybe check to see if this works
        printf("malloc failed!\n");
        exit(1);
    }
    /* The original line of code requested by the professor was
     strncpy(&board[0], "FF", 8);
     This code runs amok with memory management, and triggers a segfault.
     Therefore, it has been substituted with something else.
     */
    
    for (int i=0; i < ARRAY_DIM; i++) {
        for (int k=0; k < ARRAY_DIM; k++) {
            strncpy(board[0], "0", 8); //copy "F" into every space of the board.
        }
    }
    
    return *board;
}

void printMapBoard(char **board) {
    block();
    for (int i=0; i < ARRAY_DIM; i++) {
        for (int k=0; k < ARRAY_DIM; k++) {
            printf("%s ", &board[i*k]);
            if (k==7) {
                printf("\n");
            }
        }
    }
    block();
}
