/*
-----------------------------------------------
Author: Nishant Tewari
ID:     190684430
Email:  tewa4430@mylaurier.ca
__updated__ = "2021-04-02"
✔
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
  HTNODE *nhn=(HTNODE *)malloc(sizeof(HTNODE));
  nhn->value = value;
  strcpy(nhn->name, name);
  nhn->next = NULL;
  return nhn;
}

HASHTABLE *new_hashtable(int size) {
    // your implementation
    HASHTABLE *htable = (HASHTABLE *) malloc(sizeof(HASHTABLE));
    htable->size = size;
    htable->count = 0;
    htable->hnp = (HTNODE **) malloc(sizeof(HTNODE) * size);
    for (int i = 0; i < size; i++)
        htable->hnp[i] = NULL;
    return htable;
}

HTNODE *search(HASHTABLE *ht, char *name) { 
// your implementation
    int index = hash(name);
    if (ht->hnp[index])
    {
        HTNODE *tmp = ht->hnp[index];
        while (tmp)
        {
            if (strcmp(tmp->name, name) == 0)
                return tmp;
            tmp = tmp->next;
        }
    }
    return NULL;
}

int insert(HASHTABLE *ht, HTNODE *np) {
    // your implementation
    int index = hash(np->name);
    if (ht->hnp[index])
    {
        HTNODE *tmp = ht->hnp[index];
        while (tmp)
        {
            if (strcmp(tmp->name, np->name) == 0)
            {
                tmp->value = np->value;
                return 0;
            }
            tmp = tmp->next;
        }
        tmp = np;
        ht->count++;
        return 1;
    }
    ht->hnp[index] = np;
    ht->count++;
    return 1;
}

int delete(HASHTABLE *ht, char *name) {
// your implementation
int i = hash(name);
    HTNODE *current = *(ht->hnp + i);
    HTNODE *prev = NULL;
    if (current == NULL)
    {
        return 0;
    }
    else
    {
        while (current && strcmp(name,current->name)!= 0)
        {
            prev = current;
            current = current->next;
        }
        if (strcmp(name,current->name) == 0)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            else
            {
                *(ht->hnp + i) = NULL;
                ht->count--;
            }
        }
        return 0;
}
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