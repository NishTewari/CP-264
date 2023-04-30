/*
--------------------------------------------------
Project: CP264 A5
File: dllist_main.c
Author: Nish Tewari 
Student ID: 190684430
Email: tewa4430@mylaurier.ca
Version: 2021-02-26
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

int main(int argc, char* args[]) {
  NODE *start = NULL, *end = NULL;
  int i=0;
  for (i = 0; i<10; i++) {
    insert_start(&start, &end, new_node('0'+i));
  }
  printf("output0:");
  display_forward(start);
  printf('\n');
  printf("output1:");
  display_backward(end);
  printf("\n");
  delete_start(&start, &end);
  delete_end(&start, &end);
  printf("output2:");
  display_forward(start);
  printf("\n");  
  clean(&start, &end); 
  
  for (i = 0; i<10; i++) {
    insert_end(&start, &end, new_node('a'+i));
  }
  printf("output3:");
  display_forward(start);
  printf("\n");  
  clean(&start, &end); 
  return 0;
}
