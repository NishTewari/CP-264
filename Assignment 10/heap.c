/*
------------------------------------------------
Author: Nishant Tewari
ID:     190684430
Email:  tewa4430@mylaurier.ca
__updated__ = "2021-04-02"
-------------------------------------------------
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"
#include <math.h>

HEAP *new_heap(int capacity) {
	HEAP *nheap = (HEAP *) malloc(sizeof(HEAP));
	nheap->capacity = capacity;
	nheap->size = 0;
	nheap->hnap = (HNODE *) malloc(sizeof(HNODE) * capacity);
	return nheap;
}

void insert(HEAP *heap, HNODE new_node) {
	if (!heap)
		return;
	if (heap->size == heap->capacity) {
		HNODE *temp;
		heap->capacity *= 2;  // Double the current capacity
		temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
		if (temp) {  // Reallocation successful
			heap->hnap = temp;
		} else {  // Unable to reallocate
			temp = malloc(sizeof(HNODE) * heap->capacity);
			if (temp) {  // Copy previous contents to new memory space
				memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
				free(heap->hnap);
				heap->hnap = temp;
			} else
				printf("Array resize failed!\n");
		}
	}
	heap->hnap[heap->size] = new_node;
	heap->size++;
	int curr_index = heap->size - 1;
	int parent_index = (curr_index - 1) / 2;
	while (cmp(heap->hnap[curr_index].key, heap->hnap[parent_index].key) == -1) {
		HNODE temp = heap->hnap[curr_index];
		heap->hnap[curr_index] = heap->hnap[parent_index];
		heap->hnap[parent_index] = temp;
		curr_index = parent_index;
		parent_index = (curr_index - 1) / 2;
	}
}

HNODE extract_min(HEAP *heap) {
	HNODE min = heap->hnap[0];
	heap->hnap[0] = heap->hnap[heap->size - 1];
	heap->size--;
	int curr_index = 0;
	int child_index =
			2 * curr_index + 2 < heap->size ?
					cmp(heap->hnap[2 * curr_index + 1].key,
							heap->hnap[2 * curr_index + 2].key) == -1 ?
							2 * curr_index + 1 : 2 * curr_index + 2
			:
			2 * curr_index + 1 < heap->size ? 2 * curr_index + 1 : curr_index;
	while (cmp(heap->hnap[curr_index].key, heap->hnap[child_index].key) == 1) {
		// Swap the current node and its child node
		HNODE temp = heap->hnap[curr_index];
		heap->hnap[curr_index] = heap->hnap[child_index];
		heap->hnap[child_index] = temp;
		curr_index = child_index;
		child_index =
				2 * curr_index + 2 < heap->size ?
						cmp(heap->hnap[2 * curr_index + 1].key,
								heap->hnap[2 * curr_index + 2].key) == -1 ?
								2 * curr_index + 1 : 2 * curr_index + 2
				:
				2 * curr_index + 1 < heap->size ?
						2 * curr_index + 1 : curr_index;
	}
	if (heap->size < heap->capacity / 2) {
		HNODE *temp;
		heap->capacity /= 2;
		temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
		if (temp) {
			heap->hnap = temp;
		} else
			temp = malloc(sizeof(HNODE) * heap->capacity);
		if (temp) {
			memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
			heap->hnap = temp;
		} else
			printf("Array resize failed\n");
	}
	return min;
}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value) {
	int p;
	HNODE t;
	if (heap->hnap[node_index].key > key_value) {
		heap->hnap[node_index].key = key_value;
		t = heap->hnap[node_index];
		p = (node_index - 1) >> 1;
		while (node_index > 0 && cmp(heap->hnap[p].key, key_value) > 0) {
			heap->hnap[node_index] = heap->hnap[p];
			node_index = p;
			p = (node_index - 1) >> 1;
		}
		heap->hnap[node_index] = t;
	}
}

int find_index(HEAP *heap, DATA value) {
	if (!heap)
		return -1;
	int index = 0;
	HNODE *curr = &(heap->hnap[index]);
	while (curr && index < heap->size) {
		if (curr->data == value)
			return index;
		index++;
		curr = &(heap->hnap[index]);
	}
	return -1;
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