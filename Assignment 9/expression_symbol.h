/*
-----------------------------------------------
Author: Nishant Tewari
ID:     190684430
Email:  tewa4430@mylaurier.ca
__updated__ = "2021-04-02"
✔
-----------------------------------------------
*/  
#ifndef EXPRESSION_SYMBOL_H
#define EXPRESSION_SYMBOL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "hash.h"

// add your code documentation
QUEUE infix_to_postfix_symbol(char *infixstr, HASHTABLE *ht);

// add your code documentation
int evaluate_infix_symbol(char *infixstr, HASHTABLE *ht);

// A6Q3
int evaluate_postfix(QUEUE queue);

// provided for your reference
int resolve_symbol(char* statement, HASHTABLE *ht);

#endif