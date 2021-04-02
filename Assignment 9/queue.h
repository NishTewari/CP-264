/*--------------------------------------------------
Project: CP264-a6
File:    queue.h
Description: header of queue data structure, using linked list common.h
Author:  HBF  
Version: 2021-02-24
--------------------------------------------------
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