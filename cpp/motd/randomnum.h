/*
  randomnum.h
  'Generate a random number in C++!'
  Robert Maloy
  6 November 2017
*/

/*
  On behalf of all Grand Strategists,
  all Paladins, Warlocks, Bards and Dungeon Masters,
  We ask, our lord whom doth decide the fate of our games,
  Unending blessings and patience to give us a natural 20.
  May all rolls be good rolls, amen.
*/

#include <iostream>
#include <string>
#define RNG

using namespace std;

int generateRandomNumber() {
  srand (time(NULL));
  int work = 0;
  int a = rand() % 10 + 1;
  int b = rand() % 10 + 1;
  cout << "Your random numbers are: " << a << " and " << b << endl;

  switch (a+b) {
    default:
      break;
    case 10:
      work = 1; cout << "Hey, they add up! You win!" << endl; break;
  }
  switch (a-b) {
    default:
      break;
    case 10:
      work = 1; cout << "Hey, they subtract out! You win!" << endl; break;
  }
  switch (b-a) {
    default:
      break;
    case 10:
      work = 1; cout << "Hey, they do subtract out! You win!" << endl; break;
  }
  switch (a/b) {
    default: break;
    case 10: work = 1; cout << "Hey, they do divide out! You win, I guess." << endl; break;
             break;
  }
  switch (b/a) {
    default: break;
    case 10: work = 1; cout << "Hey, they do divide out! You win, I guess." << endl; break;
  }
  switch (a*b) {
    default: break;
    case 10: work = 1; cout << "Hey, they do multiply together to get 10! You win!" << endl; break;
  }
  if (work == 0)
  {
    cout << "Nothing seemed to work. You lose." << endl;
  }

  return 0;
}
