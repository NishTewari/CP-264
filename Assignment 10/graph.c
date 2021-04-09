/*--------------------------------------------------
Project: CP264-a10q2
File:    graph.c
Description: 
Author:  Nish Tewari  
Version: 2021-04-09
---------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h> 
#include "graph.h"


GRAPH *new_graph(int order) {
  // your implementation
  GRAPH *gp = (GRAPH*) malloc(sizeof(GRAPH));
	gp->order = order;
	gp->size = 0;
	gp->nodes = malloc(order * sizeof(GNODE));
	if (!gp)
		return NULL;
	int i;
	for (i = 0; i < order; i++){
		gp->nodes[i] = malloc(sizeof(GNODE));
		gp->nodes[i]->nid = i;
		gp->nodes[i]->neighbor = NULL;
	}
	return gp;
  
}

ADJNODE* new_node(int nid, int weight) {
    ADJNODE *np =(ADJNODE*) malloc(sizeof(ADJNODE));
    if (np) {
      np->nid = nid;
      np->weight = weight;
      np->next = NULL;
    }
    return np;

}

void add_edge(GRAPH *g, int from, int to, int weight) {
  // your implementation
  if (!g)
		return;
    ADJNODE *cn = g->nodes[from]->neighbor;
    ADJNODE *nn = new_node(to, weight);
    if (g->nodes[from]->neighbor == NULL){
        g->nodes[from]->neighbor = nn;
        nn->next = NULL;
    }
    else {
		while (cn->next != NULL ) {
			cn = cn->next;
		}
        cn->next = nn;
    }
    g->size++;
  
}


void bf_traverse(GRAPH *g, int nid) {
  // your implementation
  if (g == NULL)
		return;
	int n = g->order, visited[n],i;
	for (int i = 0; i<n;i++) visited[i]=0;
	QUEUE q = {0};
	GNODE *gn = NULL;
	ADJNODE *an = NULL;
	enqueue(&q, g->nodes[nid]);
	visited[nid] = 1;
	while(q.front){
		gn = (GNODE*)dequeue(&q);
		printf("%d ", gn->nid);
		an = gn->neighbor;
		while(an) {
			i = an->nid;
			if(visited[i] == 0){
				enqueue(&q,g->nodes[i]);
				visited[i] = 1;
			}
			an = an->next;
		}
	}
	clean_queue(&q);
}

//use auxiliary stack data structure for the algorithm 
void df_traverse(GRAPH *g, int nid) {
  // your implementation
if (g == NULL)
		return;
	int n = g->order, visited[n],i;
	for (int i = 0; i<n;i++) visited[i]=0;
	STACK s = {0};
	GNODE *gn = NULL;
	ADJNODE *an = NULL;
	push(&s, g->nodes[nid]);
	visited[nid] = 1;
	while(s.top){
		gn = (GNODE*)peek(&s);
		pop(&s);
		printf("%d ", gn->nid);
		an = gn->neighbor;
		while(an) {
			i = an->nid;
			if(visited[i] == 0){
				push(&s,g->nodes[i]);
				visited[i] = 1;
			}
			an = an->next;
		}
	}
	clean_stack(&s);
}

int get_weight(GRAPH *g, int from, int to) {
  ADJNODE *p = g->nodes[from]->neighbor;
  int result = INFINITY;
  while (p) {
    if (p->nid == to) {
        result = p->weight;
        break;
    }
    p = p->next;
  }
  return result;
}

void clean_graph(GRAPH **gp) {
  int i;
  GRAPH *g = *gp;
  ADJNODE *temp, *ptr;
  for (i = 0; i < g->order; i++) {
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      temp = ptr;
      ptr = ptr->next;
      free(temp);
    }
    free(g->nodes[i]);
  }
  free(g->nodes);
  free(g);
  *gp = NULL;
}

void display_graph(GRAPH *g) {
  if (g == NULL) return;
  printf("order:%d\n", g->order);
  printf("size:%d\n", g->size);
  printf("from:(to weight)");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d) ", ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
}


// queue functions adapted and modified from a7
void enqueue(QUEUE *qp, void *data) {
   QNODE *p = (QNODE*) malloc(sizeof(QNODE));
   if (p == NULL) return; 
   else { 
     p->data = data;
     p->next = NULL;
     
     if (qp->front == NULL) {
      qp->front = p;
      qp->rear = p;
     } else {
      (qp->rear)->next = p;
      qp->rear = p; 
    }
  }
}
void *dequeue(QUEUE *qp) {
  void *temp = NULL;
  if (qp->front) {
    QNODE *p = qp->front;
    temp = p->data;
    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;
    } else {
      qp->front = p->next;
    }
    free(p);
    return temp;
  }
  return NULL;
}
void clean_queue(QUEUE *qp) {
  QNODE *temp, *p = qp->front; 
  while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp);
  }
}

// stack functions adapted and modified from a6q3
void push(STACK *sp, void *data) {
  SNODE *p = (SNODE*) malloc(sizeof(SNODE));
  p->data = data;
  p->next = NULL;
  if (sp->top == NULL) {
    sp->top = p;
  } else {
    p->next = sp->top;
    sp->top = p  ;
  }
}
void pop(STACK *sp) {
  if (sp->top != NULL) {
    SNODE *p = sp->top;
    sp->top = p->next;
    free(p);
  }
}
void *peek(STACK *sp) {
  if (sp->top != NULL) {
     return sp->top->data;
  }
  return NULL;
}
void clean_stack(STACK *sp) {
  SNODE *temp, *p = sp->top;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  sp->top = NULL;
}