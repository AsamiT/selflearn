/*
  ascii.h
  'Generate an ASCII message in C++'
  (c) Robert Maloy
  October 31, 2017
*/

#include <iostream>
#include <fstream>
#include <string>
#define ASC

using namespace std;

string getFileContents(ifstream&u File)
{
  string Lines = "";

  if (File)
  {
    while (File.good())
    {
      string TempLine;
      getline (File, TempLine);
      TempLine += "\n";
      Lines += TempLine;
    }
    return Lines;
  }
  else
  {
    return "File DNE.";
  }
}
