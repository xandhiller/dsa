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



int main (int argc, char *argv[]) {
    /* <++> */

    return 0;
}
