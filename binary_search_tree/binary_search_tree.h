// Author:  Alex Hiller
// Year:    2020


/* Defines & Enumerations */
/* <++> */


/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../arrays/dynamic_arrays.h"
#include "../heap/heap.h"

/* Structures */
struct bst {
    dynamic_array_t* array;
};
typedef struct bst bst_t;


/******************************************************************************/
/* NOTE ON DESIGN: 
 * Left: A value that precedes the current node wrt the order relation.
 * Right: A value that suceeds the current node wrt the order relation.
 * Uniqueness: Only unique values will be stored in the BST. */
/******************************************************************************/


/* Intialises the array used to store the binary tree. */
void bst_init(bst_t* bst);


/* Used to determine precedence of the elements in the binary tree. */
uint8_t bst_order_rel(DATA_TYPE a, DATA_TYPE b);


uint64_t bst_get_left(void);
uint64_t bst_get_right(void);

/* Inserts a DATA_TYPE type value into the binary search tree  */
bool bst_insert(DATA_TYPE val, bst_t* bst);



void bst_find(void);
void bst_delete(void);
