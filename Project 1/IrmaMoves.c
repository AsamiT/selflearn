/*

  IrmaMoves.c
  3 February 2018
  Robert Maloy

  */

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
