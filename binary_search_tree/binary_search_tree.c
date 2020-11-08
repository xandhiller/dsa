/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    An implementation of the binary search tree, using an array approach,
 *    in C.
 */


#include "binary_search_tree.h"


void bst_init(bst_t* bst) {
    bst->array = (dynamic_array_t*)malloc(sizeof(dynamic_array_t));
    da_init(bst->array);
}


uint8_t bst_order_rel(DATA_TYPE a, DATA_TYPE b) {
    return hp_order_rel(a, b);
}




int main (int argc, char *argv[]) {
    /* <++> */

    return 0;
}
