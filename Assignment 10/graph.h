/*--------------------------------------------------
Project: CP264-a10qq
File:    graph.h
Description: 
Author:  Nish Tewari  
Version: 2021-04-09
---------------------------------------------------
*/
#ifndef GRAPH_H
#define GRAPH_H

#define INFINITY 99999

// your code document
typedef struct adjnode  {
    int nid;
    int weight;
    struct adjnode *next;
} ADJNODE;

// your code document
typedef struct gnode  {
    int nid;            // graph node id 
    ADJNODE *neighbor;  // pointer to linked list of neighers
} GNODE;

// your code document
typedef struct graph {
    int order;         // number of nodes
    int size;          // number of edges   
    GNODE **nodes;     // pointer to an array of GNODE pointers
} GRAPH;

// your code document
GRAPH *new_graph(int n);

// your code document
void add_edge(GRAPH *g, int from, int to, int weight);

// your code document
void bf_traverse(GRAPH *g, int nid);

// your code document
void df_traverse(GRAPH *g, int nid); 


// The implementation of the following functions are provided 

int get_weight(GRAPH *g, int from, int to);
void display_graph(GRAPH *g);
void clean_graph(GRAPH **gp);

typedef struct queue_node {
  void *data;
  struct queue_node *next;
} QNODE;
typedef struct queue {
  QNODE *front, *rear;
} QUEUE;
void enqueue(QUEUE *qp, void *data);
void *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

typedef struct stack_node {
  void *data; // pointer data
  struct stack_node *next;
} SNODE;
typedef struct stack {
  SNODE *top;
} STACK;
void push(STACK *sp, void *data);
void pop(STACK *sp);
void *peek(STACK *sp);
void clean_stack(STACK *sp);

#endif