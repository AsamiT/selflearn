/*

 file: IrmaMoves.c
 date: 3 February 2018
 name: Robert Maloy
 desc: Internal logic for IrmaMoves.

  */

/* Only a company as insidious and evil
 as AT&T would come up with a programming
 language as evil and horrible as C. */

#include "IrmaMoves.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* The following line is a macOS/UNIX debug include, and is not used outside of debugging. There is no code that calls it, but it is left in for diagnostics should I need to use malloc_size again. */
#include <malloc/malloc.h>
#define ROW 8 //define our ROW size
#define COL 8 //define our COLUMN size

void block() {
    printf("= = = = = = = =\n"); //so I don't have to keep doing this
}

char **createMapBoard(void) {
    
    static char *board[ROW];
    /* static cast because otherwise we can't return it to the original function/main. C is very picky about memory space. */
    for (int i=0; i<ROW; i++) {
        board[i] = (char *)malloc(COL * sizeof(char));
    }
    
    if (*board == NULL)
    {
        printf("malloc failed!\n"); //fairly obvious, an error.
        exit(1);
    }
    
    for (int a=0; a<ROW; a++) { //God's trying to fill the Atlantic. Hang on...
        for (int b=0; b<COL; b++) {
            board[a][b] = ' ';
        }
    }
    
    for (int z=0; z<2; z++) { //copy the Sunshine State down
        board[0][z] = 'F';
        if (z==1) {
            board[z][z] = 'F';
            board[z+1][z] = 'F';
            board[z+1][z+1] = 'F';
            board[z+2][z+1] = 'F';
        }
    }
    board[4][2] = 'K'; //The Florida Keys are initialized
    board[5][3] = 'B'; //Grand Bahama follows
    for (int z=0; z<=2; z++) { //Cuba, a nation hard-hit by Hurricane Irma
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

char **destroyMapBoard(char **board) {
    /* because of the method we used to declare the array, this is the proper method for deallocating the memory. */
    *board = NULL;
    return NULL;
}

void debugwind(Move *irmaMove, int i) {
    int a;
    printf("%d: (%d) %d, %d\n", a, i, irmaMove->irma.ws, irmaMove->irma.wg);
    a++;
}

char **predictIrmaChange (char* str, Move *irmaMove) {
    parseNotationString(str, irmaMove);
    int o_row = irmaMove->from_loc.row; //origin row
    int d_row = irmaMove->to_loc.row; //dest. row
    int o_col = (((int) irmaMove->from_loc.col)-97); //integer of origin col
    int d_col = (((int) irmaMove->to_loc.col)-97); //integer of dest col
    int sws = irmaMove->irma.ws;
    int swg = irmaMove->irma.wg;
    char **finalBoardState = createMapBoard(); //create map board
    char temp = finalBoardState[o_row][o_col]; //temporary holder for data
    finalBoardState[o_row][o_col] = 'I'; //set position to Irma
    printMapBoard(finalBoardState); //print board
    
    /* and now we're going to iterate across the columns */
    
    for (int i = o_col; i >= d_col; i--) {
        if(finalBoardState[o_row][i] != ' ') {
            if (finalBoardState[o_row][i] == 'I') {
                //null
            }
            else {
                sws -= 15;
                swg -= 10;
            }
//            printf("board[%d][%d]: %d (sws), %d (swg)\n", o_row, i, sws, swg);
        }
        if(finalBoardState[o_row][i] == ' ') {
            sws += 10;
            swg += 5;
//            printf("board[%d][%d]: %d (sws), %d (swg)\n", o_row, i, sws, swg);
        }
        finalBoardState[o_row][o_col] = ' ';
    }
    
    printf("\n");
    /* and now the rows */
    
    for (int i = o_row-1; i >= d_row; i--) {
        if(finalBoardState[i][d_col] != ' ') {
            if (finalBoardState[i][d_col] == 'I') {
                //null
            }
            else {
                sws -= 2;
                swg -= 1;
            }
//            printf("board[%d][%d]: %d (sws), %d (swg)\n", i, d_col, sws, swg);
        }
        if(finalBoardState[i][d_col] == ' ') {
            sws += 6;
            swg += 3;
//            printf("board[%d][%d]: %d (sws), %d (swg)\n", i, d_col, sws, swg);
        }
    }
    
    finalBoardState[d_row][d_col] = 'I';
    finalBoardState[o_row][o_col] = temp;
    printMapBoard(finalBoardState); //print final state
    irmaMove->irma.ws = sws; //put those speeds back to the original struct
    irmaMove->irma.wg = swg;
}

void parseNotationString(char *str, Move *Irma) {
    int cap = 0; //manual switch
    int origin_row = ((int) str[1]-48); //have to turn the rows into numbers
    char origin_col = str[0]; //i can leave these as strings, for now.
    int dest_row = ((int) str[12]-48);
    char dest_col = str[11];
    
    /* now comes everyone's favorite thing, pushing data to the structs */
    Irma->from_loc.col = origin_col;
    Irma->from_loc.row = origin_row;
    Irma->to_loc.col = dest_col;
    Irma->to_loc.row = dest_row;
    
    while (*str) //while the string exists
    {
        if (*str++ == ' ') {
            if (cap == 0) {
                int windSpeed = strtoul(str, &str, 10); //create an integer that defines windSpeed
                Irma->irma.ws = windSpeed; //push that to Irma
                cap++; //increment your switch to allow for wg
            }
            if (cap == 1) { //repeat process
                int windGust = strtoul(str, &str, 10);
                Irma->irma.wg = windGust;
                cap++;
            }
            else {
                /* Nothing goes here, this is just a redundancy. */
            }
        }
    }
}

double difficultyRating(void) {
    double diff = 5.0;
    /* Not that I had like, six projects all due on February 11...
     and had the flu... >_> */
}

double hoursSpent(void) {
    int hrs = 40;
    /* It's probably more than that but ultimately who cares this stuff will never be used anyway??? */
}

void printMapBoard(char **board) {
    block(); //invoking that silly print-line from earlier
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
    block(); //invoking that silly print-line from earlier
}
