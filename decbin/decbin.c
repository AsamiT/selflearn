/*

  decbin.c
  "In a village in Old Siam, Sir"
  30 January 2018

*/

#include "includes.h"

int main()
{
  int dec, num_bin_dig;
  printf("Please enter a decimal value to convert to binary: ");
  scanf("%d", &dec);

  char** binout;
  binout = malloc((num_bin_dig)*sizeof(char*));

  if (binout == NULL) {
    printf("ERROR: No bits!\n");
    return 0;
  }

  for (i = 0; dec != 0; i++) {
    num_bin_dig += 1;
    dec = dec/2;
  }

}
