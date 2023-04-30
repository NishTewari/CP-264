/*
 ============================================================================
 Name        : Nish Tewari
 Author      : tewa4430
 Version     : 190684430
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "mysort.h"

BOOLEAN is_sorted(int *a, int left, int right) {
	int i;
	for (i = left; i + 1 <= right; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

void select_sort(int *a, int left, int right) {
	int i, j, k;
	for (i = left; i < right; i++) {
		k = i;
		for (j = i + 1; j <= right; j++) {
			if (a[k] > a[j])
				k = j;
		}
		if (k != i)
			swap(&a[k], &a[i]);
	}
}

void quick_sort(int *a, int left, int right) {
	int i, j, p;
	if (left < right) {
		p = left;
		i = left;
		j = right;

		while (i < j) {
			while (*(a + i) <= *(a + p) && i < right)
				i++;
			while (*(a + j) > *(a + p))
				j--;
			if (i < j)
				swap(a + i, a + j);

		}
		swap(a + j, a + p);
		quick_sort(a, left, j - 1);
		quick_sort(a, j + 1, right);

	}
}

void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}
