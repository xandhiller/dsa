// Author:  Alex Hiller
// Year:    2020


/* Defines & Enumerations */
/* <++> */

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
void bst_insert(BST_DATA_TYPE val, bst_node_t* root);


/* Given some possible value stored in the binary search tree, return its address
 * or return NULL ptr. */
bst_node_t* bst_find(BST_DATA_TYPE val, bst_node_t* root);


/* Takes in an address of a node to delete, and the root of the bst. Deletes
 * "to_delete" from the bst. */
void bst_delete(bst_node_t* to_delete, bst_node_t* root);


/* Display binary tree for debugging purposes */
void bst_display(bst_node_t* root);
