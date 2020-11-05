// Author:  Alex Hiller
// Year:    2020


/* Defines & Enumerations */


/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../arrays/dynamic_arrays.h"


/* Structures */
struct heap {
    dynamic_array_t* data;
};
typedef struct heap heap_t;


/* Needs to be like da_expand, but always expand in powers of two. */
void hp_expand(void);

/* Get the first index of the heap that is empty.  */
uint64_t hp_next_empty(heap_t hp);

/* Returns the value at "location", without altering the heap.  */
DATA_TYPE hp_peak(uint64_t location, heap_t* hp);

/* Each node has two children, so must indices must be returned as a pointer to 
 * an array of the index values.  */
uint64_t* hp_get_children(void);

/* Returns the index of the parent for the given node.  */
uint64_t hp_get_parent(uint64_t index, heap_t hp);


void hp_add(void);

void hp_bubble_up(void);

void hp_bubble_down(void);

void hp_pop_by_val(void);

void hp_pop_by_index(void);

