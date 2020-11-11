// Author:  Alex Hiller
// Year:    2020

#ifndef DSA_SETTINGS_H
#define DSA_SETTINGS_H

/* Simple booleans. */
#define TRUE            1
#define FALSE           0

/* For easily detailing whether something should be popped from the head or 
 * tail of a data structure. */
#define HEAD            -1
#define TAIL            -2

/* Order relation results. */
#define A_PRECEDES        1 
#define LEFT_PRECEDES     1
#define B_PRECEDES       -1
#define RIGHT_PRECEDES   -1
#define A_EQUAL_B         0

/* Heap node removal choices. */
#define CHOOSE_SMALLEST   1
#define SWAP_RIGHT        2
#define SWAP_LEFT         3
#define DO_NOTHING        4


/* For determining which type of deletion should be undertaken for a binary 
 * search tree removal. */
#define LEAF_NODE 1
#define LEFT_SUB_TREE 2
#define RIGHT_SUB_TREE 3
#define L_AND_R_SUB_TREE 4

/* For helper function used in bs-tree node deletion. */
#define IS_LEFT_CHILD 1
#define IS_RIGHT_CHILD 2
#define IS_ROOT 3


#include <stdbool.h>

/******************************************************************************/
/* DATA TYPES for various data structures. */
/******************************************************************************/
#ifndef DA_DATA_TYPE 
#define DA_DATA_TYPE    int
#endif

#ifndef Q_DATA_TYPE 
#define Q_DATA_TYPE     DA_DATA_TYPE
#endif

#ifndef ST_DATA_TYPE 
#define ST_DATA_TYPE    DA_DATA_TYPE
#endif

#ifndef HP_DATA_TYPE 
#define HP_DATA_TYPE    DA_DATA_TYPE
#endif

#ifndef UF_DATA_TYPE 
#define UF_DATA_TYPE    DA_DATA_TYPE
#endif

#ifndef BST_DATA_TYPE 
#define BST_DATA_TYPE   int
#endif

#endif
