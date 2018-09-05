/*
  scrambler.h
  'What do eggs and this program have in common?'
  Robert Maloy
  6 November 2017
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#define SCR

using namespace std;

int scrambleUp(const string inputFile) {
  string currentLine;
  ifstream in(inputFile);
  int lineCount;
  vector <string> lines;

  if(!in) {
    cout << "No input file specified.\n";
    return 1;
  }

  cout << "Can you guess this word? " << endl;

  while (getline(in, currentLine)) {
    ++lineCount;
    lines.push_back(currentLine);
  }

  srand (time(NULL));
  int line = rand() % lineCount + 1;

  string newLine = lines[line];
  sort(newLine.begin(), newLine.end());
  cout << newLine << endl;

return 0;
}
