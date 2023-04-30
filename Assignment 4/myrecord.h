/*
 ============================================================================
 Name        : Nish Tewari
 Author      : tewa4430
 Version     : 190684430
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#ifndef MYRECORD_H
#define MYRECORD_H

typedef struct {
// your design
	char name[20];
	float score;
} RECORD;

typedef struct {
// your design
	int count;
	float mean;
	float stddev;
} REPORT;

char letter_grade(float score);
int import_data(RECORD dataset[], char *filename);
REPORT report_data(RECORD dataset[], int n, char *filename);

#endif
