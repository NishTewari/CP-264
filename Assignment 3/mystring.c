#include "mystring.h"
#define NULL 0

int str_length(char *s) {
// your implementation

	if (s == NULL)
		return -1;
	int count = 0;
	while (*s) {
		count++;
		s++;
	}

	return count;
}

int word_count(char *s) {
// your implementation
	if (s == NULL || *s == '\0')
		return 0;
	int count = 0;
	char *p = s;
	while (*p) {
		if (*p != ' ' && (p == s || *(p - 1) == ' ')) {
			count++;
		}
		p++;
	}
	return count;
}

void lower_case(char *s) {
// your implementation
	if (s == NULL)
		return;
	while (*s) {
		if (*s >= 'A' && *s <= 'Z')
			*s += 32;
		s++;
	}
}

void trim(char *s) {
// your implementation
	if (s == NULL || *s == '\0')
		return;
	char *p = s, *dp = s;
	while (*p) {
		if (*p != ' ' || (p > s && *(p - 1) != ' ')) {
			*dp = *p;
			dp++;
		}
		p++;
	}
	if (*(p - 1) == ' ')
		*(dp - 1) = '\0';
	else
		*dp = '\0';
}
