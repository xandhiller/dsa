// Author:  Alex Hiller
// Year:    2020

#ifndef HEAP_H
#define HEAP_H

/* Defines & Enumerations */
#define A_PRECEDES        1 
#define LEFT_PRECEDES     1
#define B_PRECEDES       -1
#define RIGHT_PRECEDES   -1
#define A_EQUAL_B         0

#define CHOOSE_SMALLEST   1
#define SWAP_RIGHT        2
#define SWAP_LEFT         3
#define DO_NOTHING        4

/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../arrays/dynamic_arrays.h"


/* Structures */
struct heap {
    dynamic_array_t* array;
};
typedef struct heap heap_t;


/* Initialise the heap, init the dynamic array. */
void hp_init(heap_t* hp);


/* Must always expand in powers of two -- da_expand has been altered to only
 * behave this way. */
bool hp_expand(heap_t* hp);


/* The order relation used to determine the ordering of the heap. Currently uses
 * the '>' and '<' of the order relation. */
int8_t hp_order_rel(DATA_TYPE a, DATA_TYPE b);


/* Get the first index of the heap that is empty.  */
uint64_t hp_next_empty(heap_t* hp);


/* Returns the value at "location", without altering the heap.  */
DATA_TYPE hp_peek(uint64_t location, heap_t* hp);


/******************************************************************************/
/* NOTE: The get_children and get_parents method return indexes, as that 
 * gives the user more information -- both the position in the array, and using
 * the index they can find the value from the heap, which they have access to
 * already. */
/******************************************************************************/


/* Each node has two children, so must indices must be returned as a pointer to 
 * an array of the index values. First index is how many children. The other 
 * elements of the array are the indices of the children in the heap array. */
uint64_t* hp_get_children(uint64_t index, heap_t* hp);


/* Returns the index of the parent for the given node. */
uint64_t hp_get_parent(uint64_t index);


/* Should just keep going until the order relation is satisfied. */
void hp_bubble_up(uint64_t location, heap_t* hp);


/* A little more involved than bubble up, as it requires two nodes to choose 
 * from. */
void hp_bubble_down(uint64_t location, heap_t* hp);


/* Add an element to the heap. */
void hp_add(DATA_TYPE val, heap_t* hp);


/******************************************************************************/
/* NOTE: The pop functionality can fail if the val does not exist in the heap. 
 * Because of this, we need to return a pointer and if it is NULL, then it 
 * wasn't found in the heap. */
/******************************************************************************/
DATA_TYPE* hp_pop_by_val(DATA_TYPE val, heap_t* hp);


DATA_TYPE* hp_pop_by_index(uint64_t index, heap_t* hp);


void hp_display(heap_t* hp);

#endif
