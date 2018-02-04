/*

 file: IrmaMoves.c
 date: 3 February 2018
 name: Robert Maloy
 desc: Basic commands for IrmaMoves (tasteless, dude. tasteless.)

  */

/* "In order to create a program in C, first you must reinvent the universe." */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a=8, b=8;

void block() {
    printf("= = = = = = = =\n");
}

char **createMapBoard(void) {
    char** board[a];
    for (int i=0; i < a; i++) {
        board[i] = (char **)malloc(b * sizeof(char));
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
    
    for (int i=0; i < a; i++) {
        for (int k=0; k < b; k++) {
            strncpy(board[i][k], "F ", 8); //copy "F" into every space of the board.
        }
    }
    
    return board;
}

void printMapBoard(char **board) {
    block();
    for (int i=0; i < a; i++) {
        for (int k=0; k < b; k++) {
            printf("%c ", board[i][k]);
            if (k==7) {
                printf("\n");
            }
        }
    }
    block();
}
