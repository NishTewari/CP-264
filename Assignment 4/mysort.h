/*
 ============================================================================
 Name        : Nish Tewari
 Author      : tewa4430
 Version     : 190684430
 Date 	     : Friday February 12th 2021
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#ifndef MYSORT_H
#define MYSORT_H

// define enum type BOOLEAN
typedef enum BOOLEAN {
	false, true
} BOOLEAN;

void select_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);

#endif
