/*
-------------------------------------
File:    stack.c
Project: CP264-a6
-------------------------------------
Author:  Nish Tewari 
ID:      190684430
Email:   tewa4430@mylaurier.ca
Version  2021-03-05
-------------------------------------
 */
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    // your implementation
    if (sp -> top == NULL){
        sp -> top = np; 
    }else{
        np->next = sp -> top;
        sp->top = np; 
    }
}

NODE *pop(STACK *sp) {
    // your implementation
    if(sp->top == NULL) return NULL; 
    
    NODE *np = sp -> top;
    sp->top = sp->top->next;
    np->next = NULL; 
    return np; 

}

void clean_stack(STACK *sp) {
    // your implementation,  use clean() function in common.h 
    NODE *curr = sp->top;
    NODE *prev = NULL; 

    while(curr != NULL){
        prev = curr;
        curr = curr ->next;
        free(prev); 
    }
    sp = NULL;
}
