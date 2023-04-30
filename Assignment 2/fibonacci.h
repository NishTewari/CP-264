/*
 ============================================================================
 Name        : Nish Tewari
 Author      : tewa4430
 Version     : 190684430
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
extern int *la;  // global pointer variable to get local variable address

int iterative_fibonacci(int n) {

	int x2 = 1, temp, x1 = 1;

	if (&n < la)
		la = &n;

	// your implementation
	if (n <= 2)
		return 1;
	else {
		for (int i = 3; i <= n; i++) {
			temp = x2;
			x2 = x1 + x2;
			x1 = temp;
		}
	}
	return x2;
}

int recursive_fibonacci(int n) {
	if (&n < la)
		la = &n;
	// your implementation

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2));
}
