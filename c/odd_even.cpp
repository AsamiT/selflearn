#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int x;
	int f;
	cout << "Pick a number, any number: ";
	cin >> x;
	f=x;
	int a; //counter
	for (a = 0; a <= f; a++) {
		if (a % 2 == 0) {
			printf("x=%d; Even!\n", a);
		}
		else {
			printf("x=%d; Odd!\n", a);
		}
	}
			

	return 0;
}


