/*
 --------------------------------------------------
 Project: CP264 A5
 File: dllist.h
 Author: Nish Tewari
 Student ID: 190684430
 Email: tewa4430@mylaurier.ca
 Version: 2021-02-26
 --------------------------------------------------
 */
#ifndef DLLIST
#define DLLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *prev;
	struct node *next;
} NODE;

NODE* new_node(char data);
void display_forward(NODE *start);
void display_backward(NODE *end);
void insert_start(NODE **startp, NODE **endp, NODE *new_np);
void insert_end(NODE **startp, NODE **endp, NODE *new_np);
void delete_start(NODE **startp, NODE **endp);
void delete_end(NODE **startp, NODE **endp);
void clean(NODE **startp, NODE **endp);

#endif

