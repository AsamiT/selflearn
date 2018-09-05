/*
  asc.h
  'Generate an ASCII message in C++'
  (c) Robert Maloy
  October 31, 2017
*/

#include <iostream>
#include <fstream>
#include <string>
#define ASC

using namespace std;

int getFileContents(const string File)
{
  ifstream in(File);

  if (!in) {
    cout << "Cannot open the input file.\n";
    return 1;
  }

  string str;

  while (getline(in, str)) {
    cout << str << endl;
  }
return 0;  
}
