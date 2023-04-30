/*
--------------------------------------------------
Project: CP264 A5
File: dllist.c
Author: Nish Tewari 
Student ID: 190684430
Email: tewa4430@mylaurier.ca
Version: 2021-02-26
--------------------------------------------------
*/

#include "dllist.h"

NODE *new_node(char data) {
// your implementation
    struct node *np = (struct node *) malloc(sizeof(struct node));
	np->data = data;
	np->next = NULL;
	np->prev = NULL;
	return np;

}

void display_forward(NODE *np) {
// your implementation
    struct node *p = np;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->next;
	}
}

void display_backward(NODE *np) {
// your implementation
    struct node *p = np;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->prev;
	}
}

void insert_start(NODE **startp, NODE **endp, NODE *new_np) {
// your implementation
    if (*startp == NULL) {  
		new_np->prev = NULL;
		new_np->next = NULL;
		*startp = new_np;
		*endp = new_np;
	} else {
		new_np->prev = NULL;
		new_np->next = *startp;
		(*startp)->prev = new_np;
		*startp = new_np;
	}
}

void insert_end(NODE **startp, NODE **endp, NODE *new_np) {
// your implementation
    if (*startp == NULL) { 
		new_np->prev = NULL;
		new_np->next = NULL;
		*startp = new_np;
		*endp = new_np;
		return;
	} else {
		NODE *p = *endp;
		new_np->prev = p;
		p->next = new_np;

		*endp = new_np;
	}
}

void delete_start(NODE **startp, NODE **endp) {
// your implementation
    NODE *p = *startp;
	if (p != NULL) {
		if (p == *endp) {  
			*startp = NULL;   
			*endp = NULL;  
		} else {
			*startp = p->next;   
			(*startp)->prev = NULL;
		}
		free(p);    
	}
}

void delete_end(NODE **startp, NODE **endp) {
// your implementation
struct node *p = *endp;

	if (p == *startp) {  
		*startp = NULL;   
		*endp = NULL;
	}   
	else {
		p->prev->next = p->next;
	}

	free(p);
}

void clean(NODE **startp, NODE **endp) {
// your implementation
    struct node *temp, *np = *startp;
	while (np != NULL) {
		temp = np;
		np = np->next;
		free(temp);
	}
	*startp = NULL;
	*endp = NULL;
}

