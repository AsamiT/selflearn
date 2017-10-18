/*

  array.cpp
  "Learn How To Do Arrays, With the Power of UNIX!"
  18 October 2017

  (c) Robert Maloy

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
  int size = argc;
  int *argArray = new int[size];

  for (int i=0; i <= size; i++) {
    int var = atoi(argv[i]);
    argArray[i] = var;
    cout << argArray[i];
  }
  return 0;
}
