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

  int argnum = (argc-1);
  
  if (argnum % 2 != 0)
    {
      cout << "You did not enter an even number of variables. Try again.\n";
      return 0;
    }
  
  int size = argc;
  int *argArray = new int[argnum];

  /* cout << "........................" << endl;
  cout << "Arguments:" << endl;
  cout << "........................" << endl;
  for (int i=0; i < size; i++) {
    cout << i << ": " << argv[i] << endl;
  }
  cout << "........................" << endl;
  */

  for (int i=1; i < size; i++) {
    int var = atoi(argv[i]);
    argArray[i-1] = var;
   }

  int hV = argnum / 2;

  /* cout << "argc:" << argc << endl;
  cout << "argnum:" << argnum << endl;
  cout << "size:" << size << endl;
  cout << "hV:" << hV << endl;
  cout << "........................" << endl; */
  
  int *fArray = new int[hV];
  int *sArray = new int[hV];

  /* 
     cout << "Memory addresses for fArray and sArray:\n=========================" << endl;
     cout << "fArray: " << fArray << endl; //debug: you should see a memory address
     cout << "sArray: " << sArray << endl; //debug: you should see a memory address.
     cout << "=========================" << endl;
  */

  for (int i = 0; i < hV; i++) {
    fArray[i] = argArray[i];
    //cout << i << ": " << fArray[i] << endl;
  } 
  for (int i = 0; i < hV; i++) {
    sArray[i] = argArray[i+hV];
    //cout << i << ": " << sArray[i] << endl;
  }

  for (int i = 0; i < hV; i++) {
    int diff = fArray[i] - sArray[i];
    if (diff == 0) {
      cout << "No difference between " << fArray[i] << " and " << sArray[i] << endl;
    }
    else {
      cout << "( " << fArray[i] << " - " << sArray[i] << ") = " << diff << endl;
    }
  }
  
  return 0;
}
