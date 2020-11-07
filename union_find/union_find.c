
/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    Implementation of the union-find abstract data type in C.
 */



#include "union_find.h"

void uf_init(union_find_t* uf, uint64_t nb_elems) {
    uf->array = (dynamic_array_t*)malloc(sizeof(dynamic_array_t));
    /* Create the discrete topology on the elements. Bijectively mapping them 
     * to themselves. */
    for (int i=0; i<nb_elems; i++) {
        da_append(i, uf->array);
    }
}


uint64_t uf_get_parent(uint64_t a, union_find_t* uf) {

}

bool uf_is_root(uint64_t a, union_find_t* uf) {

}

bool uf_find(uint64_t a, uint64_t b, union_find_t* uf) {

}

void uf_union(uint64_t a, uint64_t b, union_find_t* uf) {

}

int main (int argc, char *argv[]) {
    /* <++> */

    return 0;
}
