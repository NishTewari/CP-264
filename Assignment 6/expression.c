/*
-------------------------------------
File:    expression.c
Project: CP264-a6
-------------------------------------
Author:  Nish Tewari 
ID:      190684430
Email:   tewa4430@mylaurier.ca
Version  2021-03-05
-------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function 
*/
int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}

/*
 * auxiliary function 
*/
int type(char c) {
  if (c >= '0' &&  c <= '9' )
     return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if ( c == ')')
    return 3;  
  else 
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
  // your implementation
  char *p = infixstr;
    QUEUE queue = { 0 }; 
    STACK stack = { 0 }; 
    int sign = 1, num = 0;

    while (*p) { 
        if (*p == '-' && (p == infixstr || *(p - 1) == '(')) { 
            sign = -1;
        } else if (*p >= '0' && *p <= '9') { 
            num = *p - '0';

            while ((*(p + 1) >= '0' && *(p + 1) <= '9')) {
                num = num * 10 + *(p + 1) - '0';
                p++;
            }
            enqueue(&queue, new_node(sign * num, 0));
            sign = 1;

        } else if (*p == '(') {
            push(&stack, new_node(*p, 2));

        } else if (*p == ')') {
            while (&stack) { 
                NODE *temp = pop(&stack);

                if (temp->data == '(') {
                    break;
                } else {
                    enqueue(&queue, temp);
                }
            }
        } else if (type(*p) == 1) { 

            push(&stack, new_node(*p, 1));
        } 
        p++; 
    }  
    while (stack.top) {
        enqueue(&queue, pop(&stack));
    }

    return queue;

  
}


int evaluate_postfix(QUEUE queue) {
  // your implementation
  NODE *p = queue.front;
	STACK stack = { 0 };  
	int type = 0;
	int temp;
	while (p) {
		type = p->type;
		if (type == 0) { 
			push(&stack, new_node(p->data, 0));
		} else if (type == 1) { 
			int right = pop(&stack)->data;
			int left = pop(&stack)->data;
			temp = 0;
			if (p->data == '+')
				temp = left + right;
			else if (p->data == '-')
				temp = left - right;
			else if (p->data == '*')
				temp = left * right;
			else if (p->data == '/')
				temp = left / right;
			push(&stack, new_node(temp, 0));
		}
		p = p->next;
	}
	int result = stack.top->data;
	clean_stack(&stack);
	clean_queue(&queue);
	return result;

}


int evaluate_prefix(char *infixstr) {
  // your implementation
  QUEUE qb = infix_to_postfix(infixstr);
	int result = evaluate_postfix(qb);
	clean_queue(&qb);
	return result;
}