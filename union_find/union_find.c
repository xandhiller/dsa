
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
    uf->nb_vertices = nb_elems;
}


uint64_t uf_get_parent(uint64_t a, union_find_t* uf) {
    return uf->array->data[a];
}


bool uf_is_root(uint64_t a, union_find_t* uf) {
    if (uf->array->data[a] == a) {
        return TRUE;
    }
    return FALSE;
}


uint64_t uf_get_root(uint64_t a, union_find_t* uf) {
    uint64_t a_root=a;
    while (!uf_is_root(a_root, uf)) {
        a_root = uf_get_parent(a_root, uf);
    }
    return a_root;
}


bool uf_find(uint64_t a, uint64_t b, union_find_t* uf) {
    uint64_t a_root = uf_get_root(a, uf);
    uint64_t b_root = uf_get_root(b, uf);
    if (a_root == b_root) {
        return TRUE;
    }
    return FALSE;
}


void uf_union(uint64_t a, uint64_t b, union_find_t* uf) {
    if (uf_find(a, b, uf)) {
        printf("uf_find true\n"); 
        return;
    }
    else {
        uint64_t a_root = uf_get_root(a, uf);
        uint64_t b_root = uf_get_root(b, uf);
        if (a <= b) {
            uf->array->data[b_root] = a_root;
        }
        else {
            uf->array->data[a_root] = b_root;
        }
    }
}


void uf_display(union_find_t* uf) {
    printf("\n"); 
    da_display(uf->array);
}


int main (int argc, char *argv[]) {
    union_find_t my_uf;
    uf_init(&my_uf, 10);
    uf_display(&my_uf);
    uf_union(0,1,&my_uf);
    uf_display(&my_uf);
    uf_union(1,2,&my_uf);
    uf_display(&my_uf);
    if (uf_find(1,2,&my_uf)) {
        printf("1 and 2 connected!\n"); 
    }
    if (uf_find(1,8,&my_uf)) {
        printf("1 and 8 connected!\n"); 
    }
    return 0;
}
