/*--------------------------------------------------
Project: CP264-a10q1
File:    edgelist.c
Description: 
Author:  Nish Tewari  
Version: 2021-04-09
---------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h"

EDGELIST *new_edgelist() {
  // your implementation
  EDGELIST* edge = (EDGELIST*) malloc(sizeof(EDGELIST));
	edge->start = NULL;
	edge->end = NULL;
	edge->size = 0;
	return edge;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
  // your implementation
  EDGE* new_node = (EDGE*) malloc(sizeof(EDGE));
	new_node->from = from;
	new_node->to = to;
	new_node->weight = weight;
	new_node->next = NULL;

	if (g->start == NULL) {
		g->start = g->end = new_node;
	} else {
		g->end->next = new_node;
		g->end = new_node;
	}
	g->size++;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
  // your implementation
  EDGE* new_node = (EDGE*) malloc(sizeof(EDGE));
	new_node->from = from;
	new_node->to = to;
	new_node->weight = weight;
	new_node->next = NULL;

	if (g->start == NULL) {
		g->end = g->start = new_node;
	} else {
		new_node->next = g->start;

		g->start = new_node;
	}
	g->size++;
}

int weight_edgelist(EDGELIST *g) {
  // your implementation
  EDGE* ptr = g->start;
	int counter = 0;
	while (ptr != NULL) {
		counter = counter + ptr->weight;
		ptr = ptr->next;
	}
	return counter;
}

void clean_edgelist(EDGELIST **gp) {
  EDGELIST *g = *gp;
  EDGE *temp, *p = g->start;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  free(g);
  *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
  if (g == NULL) return;
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;
  while (p) {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}