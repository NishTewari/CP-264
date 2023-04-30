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
#include "matrix.h"

void display_matrix(int *m, int n) {
	int *p = m, i, j;
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%4d", *p++);
	}
	printf("\n");
}

int sum(int *m, int n) {

	int *p = m, i, j, sum = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum += *p++;
		}
	}
	return sum;
}
int is_magic_square(int *m, int n) {
	int sum = 0, magic;
	int *p = m;

	for (int i = 0; i < n; i++)
		sum += *p++;

	for (int i = 1; i < n; i++) {
		magic = 0;
		for (int j = 0; j < n; j++)
			magic += *p++;
		if (sum != magic)
			return 0;
	}

	p = m;
	for (int i = 0; i < n; i++) {
		magic = 0;
		for (int j = 0; j < n; j++)
			magic += *(p + j * n + i);
		if (sum != magic)
			return 0;
	}

	magic = 0;
	for (int i = 0; i < n; i++)
		magic += *(p + i * n + (n - i - 1));
	if (sum != magic)
		return 0;

	magic = 0;
	for (int i = 0; i < n; i++)
		magic += *(p + i * n + i);
	if (sum != magic)
		return 0;
	return 1;
}

void transpose_matrix(int *m1, int *m2, int n) {
	//Transpose
	int *p = m2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*p = *(m1 + i + (j * n));
			p++;
		}
	}
}

void multiply_matrix(int *m1, int *m2, int *m3, int n) {

	//Matrix Multiplication
	int *p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p = m3 + (i * n) + j;
			*p = 0;
			for (int l = 0; l < n; l++) {
				*p += *(m1 + (i * n) + l) * *(m2 + j + (l * n));
			}

		}
	}
}

