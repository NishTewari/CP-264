/*
-----------------------------------------------
Author: Nishant Tewari
ID:     190684430
Email:  tewa4430@mylaurier.ca
__updated__ = "2021-04-02"
-----------------------------------------------
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"

HEAP *new_heap(int capacity)
{
    // your implementation
    HEAP *nh=(HEAP *)malloc(sizeof(HEAP));
	nh->size=0;
	nh->capacity=capacity;
	nh->hnap=(HNODE *)malloc(sizeof(HNODE)*capacity);
	return (nh);

}

void insert(HEAP *heap, HNODE new_node)
{
// your implementation
}

HNODE extract_min(HEAP *heap)
{
// your implementation
}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value)
{
// your implementation
}

int find_index(HEAP *heap, DATA value) {
// your implementation
}

void display_heap(HEAP *hp) {
  printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
  printf("(index, key, data): ");
  int i;
  for (i=0; i < hp->size; i++) {
    printf("(%d %d %d) ", i, hp->hnap[i].key, hp->hnap[i].data);
    if (i % 10 == 9) printf("\n");    
  }
  printf("\n");
}

int cmp(KEYTYPE a, KEYTYPE b) {
  if (a < b) 
     return -1;
  else if (a==b) 
     return 0;
  else 
     return 1;
}