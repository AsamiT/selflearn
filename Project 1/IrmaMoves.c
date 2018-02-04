/*

 file: IrmaMoves.c
 date: 3 February 2018
 name: Robert Maloy
 desc: Basic commands for IrmaMoves (tasteless, dude. tasteless.)

  */

/* "C makes it easy to shoot yourself in the foot;
    C++ makes it harder, but when you do it blows your whole leg off."
     - Bjarne Stroustrup, 2007 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a=8, b=8;

char **createMapBoard(void) {
//    char *board = (char *)malloc(a * b * sizeof(char));
    char **board;
    board = (char **)malloc(sizeof(char *) * a);
    board[0] = (char *)malloc(sizeof(char) * a * b);
    if (board == NULL) { //hey maybe check to see if this works
        printf("malloc failed!\n");
        exit(1);
    }
    
    
    /* The original line of code requested by the professor was
     strncpy(&board[0], "FF", 8);
     This code runs amok with memory management, and triggers a segfault.
     Therefore, it has been substituted with something else.
     */
    
    strncpy(*board, "F", 8);
    for (int i=0; i < a; i++) {
        for (int c=0; c < b; c++) {
            printf("%s ", *board);
        }
    }
    
    //strncpy(board[0][2], "C", 8);
    
    /*
     printf("*board memory location: %d\n", *board);
     This is a line of code that
     exists as a debug checker
     to see where *board lays in memory.
     */
    
    return board;
}

void printMapBoard(char **board) {
        printf("========\n");
        for (int i=0; i < a; i++) {
            for (int k=0; k < b; k++) {
                printf("%c", board[i][k]);
            }
        }
    }
