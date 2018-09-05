/*
MOTD generator
(c) Robert Maloy
31 October 2017
*/

#include "asc.h"
#include "randomnum.h"
#include "scrambler.h"
using namespace std;

int main()
{
  ASC::getFileContents("ascii.txt"); //I Choose You, Pikachu!
  cout << "----------" << endl;
  SCR::scrambleUp("wordlist.txt"); //Die Gedanken sind frei, wer kann sie erratten?
  cout << "----------" << endl;
  RNG::generateRandomNumber(); //Generate a random ass number that OS X defines because... idk, UNIX?
  return 0;
}
