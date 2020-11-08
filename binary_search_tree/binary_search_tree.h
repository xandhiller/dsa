// Author:  Alex Hiller
// Year:    2020


/* Defines & Enumerations */
/* <++> */


/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../arrays/dynamic_arrays.c"

/* Structures */
struct bst_node {
    DATA_TYPE* value;
    struct bst_node* parent;
    struct bst_node* left;
    struct bst_node* right;
};
typedef struct bst_node bst_node_t;


/******************************************************************************/
/* NOTE ON DESIGN: 
 * Left: A value that precedes the current node wrt the order relation.
 * Right: A value that suceeds the current node wrt the order relation.
 * Uniqueness: Only unique values will be stored in the BST. */
/******************************************************************************/


void bst_init(void);
void bst_insert(void);
void bst_delete(void);
void bst_find(void);

