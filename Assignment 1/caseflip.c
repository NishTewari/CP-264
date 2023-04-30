/*
 --------------------------------------------------
 Project: CP264-a1q1
 File:    caseflip.c
 Author:  your name
 Version: 2020-01-??
 --------------------------------------------------
 */

#include <stdio.h>
int main() {
	//the following two lines are for Eclipse console none-buffered output, in case you use Eclipse to do your assignment
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char let = 0, temp;

	do {
		printf("Please enter a character\n");
		scanf("%c", &let); //this is to get  character input from keyboard

		do { // this loop is to get rid of additional characters in stdin buffer
			scanf("%c", &temp);
			if (temp == '\n')
				break;
		} while (1);

		// implement your program logic here
		if (let == '*') {
			break;
		} else if (let >= 'a' && let <= 'z') { // This part will check for small characters
			printf("%c: %d, %c\n", let, let, let - 32);

		} else if (let >= 'A' && let <= 'Z') {
			printf("%c: %d, %c\n", let, let, let + 32); // This part will check for upper characters

		} else {
			printf("Invalid Input.\n"); // If the user inputs something else, Print INVALID INPUT
		}

	} while (1);
	printf("%c:quit\n", let); //Quit Message for when user stops
	return 0;
}
