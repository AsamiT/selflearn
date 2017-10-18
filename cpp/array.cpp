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

  if (argc%2 != 0)
    {
      cout << "You did not enter an even number of variables. Try again.\n";
      return 0;
    }
  
  int size = argc;
  int *argArray = new int[size];

  /* for (int i=0; i <= size; i++) {
    string var = argv[i];
    cout << var;
    } */
  //This doesn't work. I fucking hate pointers. This is why I'm not a C++ girl.
  return 0;
}
