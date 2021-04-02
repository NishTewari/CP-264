/*
-----------------------------------------------
Author: Nishant Tewari
ID:     190684430
Email:  tewa4430@mylaurier.ca
__updated__ = "2021-04-02"
-----------------------------------------------
*/ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "hash.h"

int hash(char* word) {
  unsigned int hash = 0, i;
  for (i = 0; word[i] != '\0'; i++) {
    hash = 31 * hash + word[i];
  }
  return hash % htsize;
}

HTNODE *new_hashnode(char *name, int value) {
// your implementation
  hashnode *nhn=(hashnode *)malloc(sizeof(hashnode));
  nhn->value = value;
  strcpy(nhn->name, name);
  nhn->next = NULL;
  return nhn;
}

HASHTABLE *new_hashtable(int size) {
// your implementation
}

HTNODE *search(HASHTABLE *ht, char *name) { 
// your implementation
}

int insert(HASHTABLE *ht, HTNODE *np) {
// your implementation
}

int delete(HASHTABLE *ht, char *name) {
// your implementation
}


// you can use this function in your program
void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HTNODE *sp = ht->hnp[0], *p, *temp;
  int i;
  for (i = 0; i < ht->size; i++) {
    p = ht->hnp[i];
    while (p) {
      temp = p;  
      p = p->next;
      free(temp);
    }
  ht->hnp[i] = NULL;
  }
  free(ht->hnp);
  ht->hnp = NULL;
  *htp = NULL;
}

// you can use this function in your program
void display_hashtable(HASHTABLE *ht, int option) {
  int i = 0;
  HTNODE *p;
  if (option == 0) {
  printf("size:  %d\n", ht->size);
  printf("count: %d\n", ht->count);
  printf("hash data:\nindex: list of the data elements");
  for (i = 0; i < ht->size; i++) {
    p = *(ht->hnp + i);
    if (p)
      printf("\n%2d: ", i);
    
    while (p) {
      printf("(%s, %d) ", p->name, p->value);
      p = p->next;
    }
  }
  printf("\n");
  }
  else {
      
  for (i = 0; i < ht->size; i++) {
    p = *(ht->hnp + i);
    while (p) {
      printf("%s=%d\n", p->name, p->value);
      p = p->next;
    }
  }
      
  }
  
}