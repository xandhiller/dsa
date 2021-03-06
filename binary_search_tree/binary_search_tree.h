// Author:  Alex Hiller
// Year:    2020


/* Defines & Enumerations */
/* Switch the dynamic array to be an array of pointers. */
#ifndef DA_DATA_TYPE 
#define DA_DATA_TYPE   void*
#endif


/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "../dsa_settings.h"
#include "../arrays/dynamic_arrays.h"
#include "../queues/queue.h"


/* Structures */
struct bst_node {
    BST_DATA_TYPE val;
    struct bst_node* parent;
    struct bst_node* left_child;
    struct bst_node* right_child;
};
typedef struct bst_node bst_node_t;


/******************************************************************************/
/* NOTE ON DESIGN: 
 * Left: A value that precedes the current node wrt the order relation.
 * Right: A value that suceeds the current node wrt the order relation.
 * Uniqueness: Only unique values will be stored in the BST. */
/******************************************************************************/


/* Intialises the root and sets the root value. */
void bst_init(bst_node_t* root, BST_DATA_TYPE root_val);


/* Used to determine precedence of the elements in the binary tree. */
int8_t bst_order_rel(BST_DATA_TYPE a, BST_DATA_TYPE b);


/* Only adds unique values. */
bst_node_t* bst_insert(BST_DATA_TYPE val, bst_node_t* root);


/* Given some possible value stored in the binary search tree, return its address
 * or return NULL ptr. */
bst_node_t* bst_find(BST_DATA_TYPE val, bst_node_t* root);


/* Display binary tree for debugging purposes */
void bst_display(bst_node_t* root);


/* Returns the biggest value in a given bs-tree or bs-sub-tree. */
bst_node_t* bst_biggest_val(bst_node_t* root);


/* Returns the smallest value in a given bs-tree or bs-sub-tree. */
bst_node_t* bst_smallest_val(bst_node_t* root);


/* Return whether the given node is the left or right child of the parent. */
uint8_t bst_which_child(bst_node_t* current);

/* Describes which of the 4 cases of deletion the node to_delete is 
 * categorised under. */
uint8_t bst_deletion_case(bst_node_t* to_delete);


/* Takes in an address of a node to delete, and the root of the bst. Deletes
 * "to_delete" from the bst. */
void bst_delete(BST_DATA_TYPE to_delete, bst_node_t* root);



