// your code signature

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression_symbol.h"


QUEUE infix_to_postfix_symbol(char *infixstr,  HASHTABLE *ht) {
// your implementation
}


int evaluate_infix_symbol(char *infixstr,  HASHTABLE *ht) {
// your implementation
}


int evaluate_postfix(QUEUE queue) {
// code from A6Q3
}


// you can use this function in your program
int resolve_symbol(char* statement, HASHTABLE *ht) {
  char name[10] = { 0 };
  char *dest = strstr(statement, "=");
  if (dest) 
    *dest = '\0';
  else 
    dest = statement;
  strcpy(name, statement);
  
  if ( (name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z')) {
      
    int value = evaluate_infix_symbol(dest + 1, ht);

    if (value == 99999)  // escape value
      return 2;
    else {
      insert(ht, new_hashnode(name, value));
    }
    return 1;
  }
  return 0;
}