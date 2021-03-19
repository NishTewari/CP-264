/*
-----------------------------------------------
Author: Nish Tewari
ID:     190684430
Email:  tewa4430@mylaurier.ca
__updated__ = "2021-03-19"
-----------------------------------------------
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl.h"

// A utility functions
int max(int a, int b){
    return (a > b)? a : b;
}

int height(TNODE *np){
  // your implementation
  if(np == NULL)
  {
    return 0;
  }
  return np->height;

}

int balance_factor(TNODE* np) {

  // your implementation
  if (np == NULL)
  {
    return 0;
  }
  return height(np->left) - height(np->right);
}

int is_avl(TNODE *root) {
  // your implementation
  if(root == NULL) {
      return 1;
    }
    else if(is_avl(root->left) && is_avl(root->right) && (abs(height(root->left) - height(root->right)) <= 1)){
      return 1;
    }
    else{
      return 0;
  }
}
TNODE *rotate_right(TNODE *y){
  // your implementation
  TNODE *x = y->left;
  TNODE *T2 = x->right;

  // Perform rotation
  x->right = y;
  y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  // Return new root
  return x;
}

TNODE *rotate_left(TNODE *x){
  // your implementation
  TNODE *y = x->right;
  TNODE *T2 = y->left;

  // Perform rotation
  y->left = x;
  x->right = T2;

  //  Update heights
  x->height = max(height(x->left), height(x->right))+1;
  y->height = max(height(y->left), height(y->right))+1;

  // Return new root
  return y;
}

void insert(TNODE **rootp, char *name, float score)
{
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np == NULL) return;
  strcpy(np->data.name, name);
  np->data.score = score;
  np->height = 1;
  np->left = NULL;
  np->right = NULL;
  
  // 1. Perform the normal BST insertion
  if (*rootp == NULL) {
    *rootp = np;
    return;
  }
  
  TNODE *root = *rootp;
  if (strcmp(name, root->data.name) < 0 )
    insert(&root->left, name, score);
  else if (strcmp(name, root->data.name) > 0 )
    insert(&root->right, name, score);
  else return ;

  // 2. update height of this root node
  root->height = 1 + max(height(root->left), height(root->right));

  // 3. Get the balance factor of this ancestor node to check whether this node became unbalanced
  int bf = balance_factor(root);
  
  // 4. re-balance if not balanced
  if (bf == 2 && balance_factor(root->left) >= 0) {
    *(rootp) = rotate_right(root);
  }      
  if (bf == 2 && balance_factor(root->left) < 0){
    root->left = rotate_left(root->left);
    *(rootp) =  rotate_right(root);
  }
  if (bf == -2 && balance_factor(root->right) <= 0)
    *(rootp) =  rotate_left(root);

  if (bf == -2 && balance_factor(root->right) > 0){
    root->right = rotate_right(root->right);
    *(rootp) =  rotate_left(root);
  }
  
}

void delete(TNODE **rootp, char *name)
{
  TNODE *root = *rootp;
  TNODE* np;

  if (root == NULL) return;

  if (strcmp(name, root->data.name) == 0) {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      *rootp = NULL;
    } else if (root->left != NULL && root->right == NULL) {
      np = root->left;
      free(root);
      *rootp = np;
    } else if (root->left == NULL && root->right != NULL) {
      np = root->right;
      free(root);
      *rootp = np;
    } else if (root->left != NULL && root->right != NULL) {
      np = extract_smallest_node(&root->right);
      np->left = root->left;
      np->right = root->right;
      free(root);
      *rootp = np;
    }
  } else {
    if (strcmp(name, root->data.name) < 0) {
      delete(&root->left, name);
    } else {
      delete(&root->right, name);
    }
  }

    // If the tree had only one node then return
  if (*rootp == NULL) return;

  root = *rootp;
  
  // STEP 2: update the this root node's height
  root->height = 1 + max(height(root->left), height(root->right));

  // STEP 3: get the balance factor of this root node
    int bf = balance_factor(root);

  // STEP 4: re-balance if not balanced
    
  if (bf == 2 && balance_factor(root->left) >= 0) {
    *rootp = rotate_right(root);
  }
  if (bf == 2 && balance_factor(root->left) < 0){
    root->left =  rotate_left(root->left);
    *rootp = rotate_right(root);
  }
  if (bf== -2 && balance_factor(root->right) <= 0)
    *rootp = rotate_left(root);

  if (bf == -2 && balance_factor(root->right) > 0){
    root->right = rotate_right(root->right);
    *rootp = rotate_left(root);
  }
}


// following functions are from bst.c of a7
TNODE *extract_smallest_node(TNODE **rootp) {
  TNODE *tnp = *rootp;
  TNODE *parent = NULL;
  if (tnp == NULL) {
    return NULL;
  } else {
    while (tnp->left) {
      parent = tnp;
      tnp = tnp->left;
    }
    if (parent == NULL)
      *rootp = tnp->right;
    else
      parent->left = tnp->right;
    tnp->left = NULL;
    tnp->right = NULL;
    return tnp;
  }
}

TNODE *search(TNODE *root, char *name) {
  TNODE *tp = root;
  while (tp) {
    if (strcmp(name, tp->data.name) == 0) {
       return tp;
    } else if (strcmp(name, tp->data.name) < 0) 
      tp = tp->left;
     else 
      tp = tp->right;
  }    
  return NULL;
}

void clean_tree(TNODE **rootp) {
  if (*rootp) {
    TNODE *np = *rootp;
    if (np->left)
      clean_tree(&np->left);
    if (np->right)
      clean_tree(&np->right);
    free(np);
  }
  *rootp = NULL;
}

void display_inorder(TNODE *root) {
  if (root) {
    if (root->left) display_inorder(root->left);
    printf("(%s %3.1f) ", root->data.name, root->data.score);
    if (root->right) display_inorder(root->right);
  }
}

void display_inorder_lines(TNODE *root) {
  if (root) {
    if (root->left) display_inorder_lines(root->left);
    printf("%-15s%.1f\n", root->data.name, root->data.score);
    if (root->right) display_inorder_lines(root->right);
  }
}

void display_tree(TNODE *root, int prelen) {
  if (root) {
    int i;
    for (i = 0; i < prelen; i++)
      printf("%c", ' ');
    printf("%s", "|___");
    printf("%s %.1f %d\n", root->data.name, root->data.score, root->height);
    display_tree(root->right, prelen + 4);    
    display_tree(root->left, prelen + 4);
  }
}