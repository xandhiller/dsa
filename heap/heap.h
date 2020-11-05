// Author:  Alex Hiller
// Year:    2020


/* Defines & Enumerations */
#define A_GREATER   1 
#define B_GREATER  -1
#define A_EQUAL_B   0

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


/* Each node has two children, so must indices must be returned as a pointer to 
 * an array of the index values.  */
uint64_t* hp_get_children(void);


/* Returns the index of the parent for the given node.  */
uint64_t hp_get_parent(uint64_t index, heap_t hp);


/* Add an element to the heap. */
void hp_add(void);


void hp_bubble_up(void);


void hp_bubble_down(void);


void hp_pop_by_val(void);


void hp_pop_by_index(void);


void hp_display(heap_t* hp);

