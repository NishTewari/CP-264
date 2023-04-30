/*
 --------------------------------------------------
 Project: CP264-a1q1
 File:    caseflip.c
 Author:  your name
 Version: 2020-01-??
 --------------------------------------------------
 */
#include <stdio.h>
#include <math.h>  // need this library for maths functions fabs() and sqrt()

#define EPSILON 0.000001
// or #define EPSILON 1e-6

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	float a, b, c, d, x1, x2;
	int inn;
	char temp;
	do {  // do-while for new input problem
		  // do-while loop to get correct input of three floating numbers,
		do {
			printf("Please enter the coefficients a,b,c\n");
			inn = scanf("%f,%f,%f", &a, &b, &c);

			if (inn != 3) {
				printf("input:Invalid input\n");
			} else
				break;

			do {  // flush the input buffer
				scanf("%c", &temp);
				if (temp == '\n')
					break;
			} while (1);

		} while (1);

		if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON) {
			printf("input:quit\n");
			break;
		} else if (fabs(a) < EPSILON) {
			printf("input:not a quadratic equation\n");
		} else {

			d = b * b - 4 * a * c; // compute the discriminant  (d = b^2 - 4*a*c)

			// My solution logic

			if (d > 0) { //if the discriminant is greater than 0, provide the user with two distinct real roots x1 and x2
				printf("The equation has two distinct real roots \n");
				x1 = (-b + sqrt(d)) / (2 * a);
				x2 = (-b - sqrt(d)) / (2 * a);
				printf("x1: %6f \n", x1);	// Print the values of x1 and x2
				printf("x2: %6f \n", x2);

			} else if (d == 0) { //if the discriminant is equal to 0, provide the user with two EQUAL real roots x1
				printf("The equation has two equal real roots \n");
				x1 = (-b + sqrt(d)) / (2 * a);
				printf("x: %6f\n", x1); // Print the value of x1
			} else {
				printf("The equation has two complex roots \n"); // If the discriminant is neither greater or equal to 0, then provide the user with two complex roots x1 and x2
				x1 = (-b) / (2 * a);
				x2 = (sqrt(fabs(d))) / (2 * a);
				printf("real: %6f \n", x1); // The two complex roots will be real and imaginary
				printf("imaginary: %6f \n", x2);
			}
		}
	} while (1);
	return 0;
}
