/*
-------------------------------------
File:    queue.h
Project: CP264-a6
-------------------------------------
Author:  Nish Tewari 
ID:      190684430
Email:   tewa4430@mylaurier.ca
Version  2021-03-05
-------------------------------------
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "common.h"

typedef struct queue {
  NODE *front;
  NODE *rear;
} QUEUE;    

void enqueue(QUEUE *qp, NODE *np);
NODE *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

#endif