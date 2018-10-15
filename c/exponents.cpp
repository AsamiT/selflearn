#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {

	unsigned long long int x;
	unsigned long long int f;
	cout << "Pick a number, any number: ";
	cin >> x;
	f=x;
	int a; //counter
	unsigned long long int result_sqr; //square
	unsigned long long int result_cube; //cube
	unsigned long long int result_2n; //two to the n power
	for (a = 0; a < f; a++) {
		result_sqr = pow(a, 2);
		result_cube = pow(a, 3);
		result_2n = pow(2, a);
		printf("a = %llu; ", a);
		printf("a^2 = %llu; ", result_sqr);
		printf("a^3 = %llu; ", result_cube);
		printf("2^n = %llu\n", result_2n);
	}
			

	return 0;
}


