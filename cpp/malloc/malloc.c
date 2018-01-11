/*

  malloc testing

  file: malloc.c

  Robert Maloy
  9 January 2018
  COP4415

*/

#include <stdio.h>
#include <stdlib.h> //where you can find malloc
#include <string.h>

int main()
{
  char *str;
  
  /* initial memory alloc */
  str = (char *) malloc(10);
  strcpy(str, "0123456789");
  printf("String = %s, Address = %u\n", str, str);

  /* reallocation */
  str = (char *) realloc(str, 2048);
  strcat(str, " and now we start over.");
  printf("String = %s, Address = %u\n", str, str);

  free(str);
  
  return 0;

}
