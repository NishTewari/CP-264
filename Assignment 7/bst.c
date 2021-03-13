/*--------------------------------------------------
Project: CP264-a7q2
File:    bst.c
Description: 
Author:  Nish Tewari  
Version: 2021-03-12
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bst.h"

TNODE* search(TNODE *root, char *name) {
// your implementation
    while (root) {
        if (strcmp(root->data.name, name) == 0)
            return root;
        else if (strcmp(root->data.name, name) > 0)
            root = root->left;
        else root = root->right; 
    }
    return NULL;
}


void insert(TNODE **rootp, char *name, float score) {
    // your implementation
if (!*rootp)
    {
        RECORD data = {0};
        TNODE *nnode = (TNODE *) malloc(sizeof(TNODE));
        strncpy(data.name, name, 39);

        data.score = score;
        nnode->data = data;
        nnode->right = NULL;
        nnode->left = NULL;

        *rootp = nnode;
        return;
    }
    if (strcmp(name, (*rootp)->data.name) > 0)
        insert(&(*rootp)->right, name, score);
    else if (strcmp(name, (*rootp)->data.name) < 0)
        insert(&(*rootp)->left, name, score);
    else
        return;

}

void delete(TNODE **rootp, char *name) {
    // your implementation
if (!*rootp) return;
    TNODE *tmp = NULL;

    if (strcmp(name, (*rootp)->data.name) == 0)
    {
        if (!(*rootp)->left && !(*rootp)->right)
        {
            free(rootp);
            *rootp = NULL;
        }

        else if ((*rootp)->left && !(*rootp)->right)
        {
            tmp = (*rootp)->left;
            free(rootp);
            *rootp = tmp;
        }
        else if (!(*rootp)->left && (*rootp)->right)
        {
            tmp = (*rootp)->right;
            free(rootp);
            *rootp = tmp;
        }
        else if ((*rootp)->left && (*rootp)->right)
        {
            tmp = extract_smallest_node(&(*rootp)->right);
            tmp->left = (*rootp)->left;
            tmp->right = (*rootp)->right;
            free(rootp);
            *rootp = tmp;
        }
    } else if (strcmp(name, (*rootp)->data.name) < 0)
        delete(&(*rootp)->left, name);
    else   
        delete(&(*rootp)->right, name);
}


TNODE *extract_smallest_node(TNODE **rootp) {
// your implementation
 if (!*rootp) return NULL;
    if (!(*rootp)->left)
        return *rootp;
    else
        return extract_smallest_node(&(*rootp)->left);

}

void display_inorder(TNODE *root) {
    if (root) {
        if (root->left) display_inorder(root->left);
        printf("%-15s%3.1f\n", root->data.name, root->data.score);
        if (root->right) display_inorder(root->right);
    }
}

void clean_tree(TNODE **rootp) {
    TNODE *root = *rootp;
    if (root) {
        if (root->left)
            clean_tree(&root->left);
        if (root->right)
            clean_tree(&root->right);
        free(root);
    }
    *rootp = NULL;
}