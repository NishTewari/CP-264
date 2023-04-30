/*
--------------------------------------------------
Project: CP264 A5
File: bigint.h
Author: Nish Tewari 
Student ID: 190684430
Email: tewa4430@mylaurier.ca
Version: 2021-02-26
--------------------------------------------------
*/
#ifndef BIGINT_H
#define BIGINT_H

#include "dllist.h"

typedef struct bigint {
  NODE *start;
  NODE *end;
} BIGINT;

BIGINT bigint(char *bignumberstr);
void display_bigint(BIGINT bignumber);
void clean_bigint(BIGINT *bignumberp);

BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

#endif