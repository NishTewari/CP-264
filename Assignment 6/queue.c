/*
-------------------------------------
File:    queue.c
Project: CP264-a6
-------------------------------------
Author:  Nish Tewari 
ID:      190684430
Email:   tewa4430@mylaurier.ca
Version  2021-03-05
-------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
    // your implementation
    if (qp->front == NULL || qp->rear == NULL)
    {
        qp->front = np;
        qp->rear = np;
    }
    else    //Add to the rear 
    {
        qp->rear->next = np;
        qp->rear = np;
    }
}  

NODE *dequeue(QUEUE *qp) {
    // your implementation 
    if (qp->front == NULL || qp->rear == NULL) return NULL;
    NODE *np = qp->front;
    qp->front = qp->front->next;
    np->next = NULL;
    return np;
}


void clean_queue(QUEUE *qp) {
    // your implementation, call clean(NODE **)
    NODE *curr = qp->front;
    NODE *prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    qp = NULL;
}
                     
