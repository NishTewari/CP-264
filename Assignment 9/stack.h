/*---------------------------------------------------
Project: CP264-a6
File:   stack.h
Description: header of stack data structure, using linked list common.h
Author:  HBF  
Version: 2021-02-24
✔
---------------------------------------------------
*/
#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct stack {
  NODE *top;
} STACK;
void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif