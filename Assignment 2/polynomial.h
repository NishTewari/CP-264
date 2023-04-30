/*
 ============================================================================
 Name        : Nish Tewari
 Author      : tewa4430
 Version     : 190684430
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6

void display_polynomial(float p[], int n, float x) {
// your implementation
	for (int i = 0; i < n; i++) {
		printf("%.2f*%.2f^%d", p[i], x, (n - (1 + i)));
		if ((n - (1 + i)) != 0) {
			printf("+");
		}
	}
}

float horner(float p[], int n, float x) {

	int a = 0;
	int i;
	for (i = 0; i < n; i++) {
		a = a * x + p[i];
	}

	return a;
}

float bisection(float p[], int n, float a, float b) {

	float c = 0, xa, xc;
	while (fabs(b - a) >= EPSILON) {
		c = (a + b) / 2;
		xc = horner(p, n, c);
		xa = horner(p, n, a);
		if (fabs(xc) < EPSILON && c - a < EPSILON) {
			break;

		} else if (xc < 0 && xa < 0) {
			a = c;

		} else if (xc > 0 && xa > 0) {
			a = c;

		} else {
			b = c;
		}
	}
	return c;
}

