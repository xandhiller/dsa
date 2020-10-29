/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    An implementation of the "singly-linked-list" abstract data type.
 */


/* Libraries */
#include <stdlib.h>
#include <stdint.h>


#define DATA_TYPE int


struct s_node {
    DATA_TYPE* data;
    struct s_node* next;
};
typedef struct s_node s_node_t;


typedef uint8_t bool;


/*
 * Initialises the linked list to have the data point to NULL and the next to 
 * point to NULL.
 */
void slist_init(s_node_t* sl) {
    sl->data = NULL;
    sl->next = NULL;
}


/*
 * Returns the struct attribute "next", that points to the next node in the list.
 */
void slist_get_next(void) {}


/*
 * Set (and possibly validate) the struct attribute "next" to the input value.
 */
void slist_set_next(void) {}


/*
 * Returns the "data" pointer for the given node.
 */
void slist_get_data(void) {}


/*
 * Set (and possibly validate) the "data" pointer to the given node.
 */
void slist_set_data(void) {}


/*
 * Determine whether the input node is the last node in the list.
 */
bool slist_is_end(void) {}


/*
 * Return the next node from the node given as input.
 */
bool slist_next_node(void) {}


/*
 * Delete the node from the list, and free the memory associated with that node.
 */
void slist_delete_node(void) {}


/*
 * Swap the order of the two input nodes (wrt the list).
 */
void slist_swap_nodes(void) {}


/*
 * Add a node to the end of the list.
 */
void slist_append(void) {}


/*
 * Pop a value by location out of the list. This means the data at that node 
 * is returned and that node is removed from the list.
 */
DATA_TYPE* slist_pop(void) {}


int main (int argc, char *argv[]) {
    /* <++> */

    return 0;
}
