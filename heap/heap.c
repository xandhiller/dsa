/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    Implementation of the heap data structure, based on arrays, in C.
 */

#include "heap.h"

/* Initialise the heap by calling init on the dynamic array. */
void hp_init(heap_t* hp) {
    da_init(hp->array);
}


bool hp_expand(heap_t* hp) {
    return da_expand(hp);
}


int8_t hp_order_rel(DATA_TYPE a, DATA_TYPE b) {
    if (a > b) {
        return A_GREATER;
    }
    else if (b > a) {
        return B_GREATER;
    }
    else {
        return A_EQUAL_B;
    }
}


uint64_t hp_next_empty(heap_t* hp) {
    return hp->array->nb_vals;
}


DATA_TYPE hp_peek(uint64_t location, heap_t* hp) {
    return hp->array->data[location];
}


uint64_t* hp_get_children(uint64_t index, heap_t* hp) {
    /* If node has two children */
    if (hp->array->nb_vals >= 2*index+1) {
        uint64_t* indices = (uint64_t*)malloc(2*sizeof(uint64_t));
        indices[0] = 2*index+1;
        indices[1] = 2*index+2;
        return indices;
    } 
    /* The node only has one child */
    else if (hp->array->nb_vals == 2*index) {
        uint64_t* indices = (uint64_t*)malloc(sizeof(uint64_t));
        indices[0] = 2*index+1;
        return indices;
    }
    /* Node does not have children */
    else {
        return NULL;
    }
}


uint64_t hp_get_parent(uint64_t index) {
    /* Integer division is important here. */
    return (index-1)/2;
}


int main (int argc, char *argv[]) {
    /* <++> */

    return 0;
}
