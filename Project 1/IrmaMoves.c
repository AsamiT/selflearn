/*

  IrmaMoves.c
  3 February 2018
  Robert Maloy

  */

/* If I had to choose between
 spending the remaining days of my life
 programming in Intel 8086/88 assembly,
 or C; I'd probably take the former. */

  int a=8, b=8;

char **createMapBoard(void) {
  char *board = (char *)malloc(a*b*sizeof(char));
  strncpy(&board[0], "FF ", 8);
}

void printMapBoard(char **board) {
    printf("========\n");
    for (int i=0; i < a; i++) {
        for (int k=0; k < b; k++) {
            printf("%s", board[i, k]);
        }
    }
}
