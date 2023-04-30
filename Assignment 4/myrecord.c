/*
 ============================================================================
 Name        : Nish Tewari
 Author      : tewa4430
 Version     : 190684430
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

#define MAX_LINE 100

char letter_grade(float s) {
// your implementation
	char grade;
	if (s > 85) {
		grade = 'A';
	} else if (s > 70 & s <= 85) {
		grade = 'B';
	} else if (s > 60 & s <= 70) {
		grade = 'C';
	} else if (s > 50 & s <= 60) {
		grade = 'D';
	} else {
		grade = 'F';
	}
	return grade;
}

int import_data(RECORD dataset[], char *filename) {
	// your implementation
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	char delimiters[] = ",\n\r";
	char line[100];
	int i = 0; // record counter
	char *token = NULL;

	while (fgets(line, sizeof(line), fp) != NULL) {
		token = (char*) strtok(line, delimiters);
		strcpy(dataset[i].name, token); // copy string char array
		token = (char*) strtok(NULL, delimiters);
		dataset[i].score = atof(token); // convert string to float
		i++;
	}
	fclose(fp);
	return i;
}

REPORT report_data(RECORD dataset[], int n, char *filename) {
	REPORT report = { };
	if (n < 1)
		return report;
	FILE *f = fopen(filename, "w");
	int i;
	int count = n;
	float mean = 0;
	float stddev = 0;
	for (i = 0; i < n; i++) {
		fprintf(f, "%-10s%c\n", dataset[i].name,
				letter_grade(dataset[i].score));
		mean += dataset[i].score;
	}
	mean /= count;
	for (i = 0; i < n; i++)
		stddev += (dataset[i].score - mean) * (dataset[i].score - mean);
	stddev = sqrt(stddev / count);
	fprintf(f, "\n%-10s%d\n", "count:", report.count = count);
	fprintf(f, "%-10s%d\n", "mean:", report.mean = mean);
	fprintf(f, "%-10s%d\n", "stddev:", report.stddev = stddev);
	return report;

}

