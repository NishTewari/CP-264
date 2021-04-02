/*
------------------------------------------------
Author: Nishant Tewari
ID:     190684430
Email:  tewa4430@mylaurier.ca
__updated__ = "2021-04-02"
✔
------------------------------------------------
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"

HEAP *new_heap(int capacity)
{
    // your implementation
  HEAP *new_heap=(HEAP *)malloc(sizeof(HEAP));
	new_heap->size=0;
	new_heap->capacity=capacity;
	new_heap->hnap=(HNODE *)malloc(sizeof(HNODE)*capacity);
	return (new_heap);

}

void insert(HEAP *heap, HNODE new_node)
{
  // your implementation
if (!heap) return;
  if (heap->size == heap->capacity)
  {
    HNODE *temp;

    heap->capacity *= 2; 
    temp = realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
    if (temp) 
    {
      heap->hnap = temp;
      display_heap(heap);
    } else  
    {
      temp = malloc(sizeof(HNODE) * heap->capacity);
      if (temp)
      {
        memcpy(temp, heap->hnap, sizeof(HNODE) * heap->size);
        free(heap->hnap);
        heap->hnap = temp;
      } else
      {
        printf("Array resize failed!\n");
      }
    }
  }
  heap->hnap[heap->size] = new_node;
  heap->size++;
  int curr_index = heap->size - 1;
  int parent_index = (curr_index - 1) / 2;
  while (cmp(heap->hnap[curr_index].key, heap->hnap[parent_index].key) == -1)
  {
    HNODE temp = heap->hnap[curr_index];
    heap->hnap[curr_index] = heap->hnap[parent_index];
    heap->hnap[parent_index] = temp;
    curr_index = parent_index;
    parent_index = (curr_index - 1) / 2;
  }
}

HNODE extract_min(HEAP *heap)
{
  //Your implementation 
HNODE *nh=(HNODE *)malloc(sizeof(HNODE));
	if(heap->size!=0){
		if((heap->capacity/heap->size)<=0.25){
			heap->hnap=realloc(heap->hnap,sizeof(HNODE)*((heap->capacity-heap->size)/2));
		}
		*(nh)=heap->hnap[0];
		int i;
		heap->size--;
    if (heap->size < sqrt(heap->capacity))
                heap->capacity = sqrt(heap->capacity);
		for(i=0;i<heap->size;i++){
			heap->hnap[i]=heap->hnap[i+1];
		}
  // Heapify Down
  int index = 0;
  int n = heap->size;
  HNODE val = heap->hnap[index];
  int ci = (index << 1) + 1; 
  while (ci <= n) { 
    if ((ci < n) && (heap->hnap[ci].data < heap->hnap[ci+1].data))
      ci++;  
    if (heap->hnap[ci].data < val.data)
      break;   
    else {
      heap->hnap[index] = heap->hnap[ci]; 
      index = ci;
      ci = (index << 1) + 1;
      }
    }
    heap->hnap[index] = val;
	}else{
		printf("\nNo data\n");
	}
	return (*nh);
}


void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value)
{
    // your implementation
    if(node_index>=0 && node_index<heap->size)
    {
        heap->hnap[node_index].key = key_value;
        int size = (heap->size);
        int parent;
        HNODE val = heap->hnap[node_index];
      while (size) {
        parent = (size-1) >> 1;  //equivalent to parent = (index-1)/ 2;
        if (heap->hnap[parent].key <= val.key) break;
        else {
          heap->hnap[node_index] = heap->hnap[parent];
          size = parent;
        }
      }
      heap->hnap[size] = val;
    }
    else
    {
        printf("\nIndex out of range\n");
    }
}


int find_index(HEAP *heap, DATA value) {
// your implementation
int index=0;
	while(index<heap->size && heap->hnap[index].data!=value){
		index++;
	}
	if(index==heap->size){
		printf("Data not found");
		return -1;
	}else{
		return index;
	}
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