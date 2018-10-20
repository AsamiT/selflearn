/**
 *
 * 	@file: xv6_nullptr.c
 * 	@date: 19 October 2018
 * 	@author: Robert Maloy <rmaloy2612@floridapoly.edu>
 * 	@desc: A program intended to trigger a null pointer dereferencing
 * 		under the Linux operating system, as well as XV6.
 * 		
 **/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr; //pointer to an integer
	int deref; //dereferencer
	printf("code %p\n", main);
	printf("stack %p\n", &ptr);
	printf("heap %p\n", ptr);
	deref = 3;
	ptr = deref;
	*ptr = 0;
	return 0;
}
