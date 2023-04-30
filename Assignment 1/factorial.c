/*
 --------------------------------------------------
 Project: CP264-a1q1
 File:    caseflip.c
 Author:  Nish
 Version: 2020-01-??
 --------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
	int i, n = 0, f = 1, last, is_overflow = 0;

	if (argc > 1) {
		n = atoi(args[1]);  // convert command line argument to an integer

		if (n >= 1) { // the conversion is successful
			i = 0;
			last = 1;
			printf("factorial %d", n);
			while (i < n && is_overflow == 0) {
				if (i % 4 == 0) {
					printf("\n");
				}
				i++;

				f = i * last;
				if (last != (f / i)) {
					is_overflow = 1;
					printf("\n");
					printf("overflow: %d!", i);
				} else {
					printf("%11d", f);
					last = f;
				}
			}
			if (is_overflow == 0) {
				printf("\n");
				printf("%d!:%d", n, f);
			}

		} else {

			printf("%s:invalid argument\n", args[1]);
		}

	} else {

		printf("no argument");
	}
	return 0;
}
