/*--------------------------------------------------
Project: CP264-a6q1
File:    queue.c
Description: implementation of queue.h
Author:  HBF  
Version: 2020-02-13
✔
---------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
  if (qp == NULL || np == NULL) return;
  if (qp->front == NULL) {
    qp->front = np;
    qp->rear = np;
  }
  else {
    qp->rear->next = np;
    qp->rear = np;  
  }
}  

NODE *dequeue(QUEUE *qp) {
  if (qp == NULL || qp->front == NULL) return NULL;
	
  NODE *ptr = qp->front;
  if (qp->front == qp->rear) {
    qp->front = NULL;
    qp->rear = NULL;
  } 
  else {
    qp->front = ptr->next;    
  }
  //free(ptr);  // don't free, as the node is returned. 
  return ptr; 
}

void clean_queue(QUEUE *qp) {
  clean(&(qp->front));
  qp->front = NULL;
  qp->rear = NULL;
}