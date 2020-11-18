
// Author:  Alex Hiller
// Year:    2020



#ifndef LL_SETTINGS_H
#define LL_SETTINGS_H

/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include "../dsa_settings.h"


#define DATA_TYPE   int
#define TRUE        1
#define FALSE       0
#define FAIL        -1


struct s_node {
    DATA_TYPE* data;
    struct s_node* next;
};
typedef struct s_node s_node_t;


/*
 * Initialises the linked list to have the data point to NULL and the next to 
 * point to NULL.
 */
void sl_init(s_node_t* sl);


/*
 * Returns the struct attribute "next", that points to the next node in the list.
 */
s_node_t* sl_get_next(s_node_t* sl);

/*
 * Set (and possibly validate) the struct attribute "next" to the input value.
 */
bool sl_set_next(s_node_t* new_next, s_node_t* sl);


/*
 * Returns the "data" pointer for the given node.
 */
DATA_TYPE* sl_get_datap(s_node_t* sl);


/*
 * Set (and possibly validate) the "data" pointer to the given node.
 */
bool sl_set_datap(DATA_TYPE* new_datap, s_node_t* sl);


/*
 * Determine whether the input node is the last node in the list.
 */
bool sl_is_end(s_node_t* sl);


/*
 * Return the next node from the node given as input.
 */
s_node_t* sl_next_node(s_node_t* sl);


/*
 * Delete the node from the list, and free the memory associated with that node. 
 *  If node not found, do nothing and return the head.
 * Returns head of linked list after deletion of specified node, or if node not 
 *  found, returns the head of the list with the head unaltered.
 */
s_node_t* sl_delete_node(s_node_t* delete_this, s_node_t* head);


/*
 * Swap the order of the two (non-NULL) input nodes (wrt the list).
 * Returns: TRUE if the swap worked, FALSE if it did not work.
 */
bool sl_swap_nodes(s_node_t* node_a, s_node_t* node_b, s_node_t* head);


/*
 * Return the pointer to the node that is at the end of the list.
 */
s_node_t* sl_goto_end(s_node_t* head);


/*
 * Add a node to the end of the list.
 */
bool sl_append(s_node_t* add_me, s_node_t* head);


/*
 * Insert a node after a given node, which.
 */
void sl_insert_after(s_node_t* to_insert, s_node_t* after_me);


bool sl_insert_at(s_node_t* to_insert, uint64_t index, s_node_t* head);


/*
 * Given a specific DATA_TYPE value, and the head of the list, return the 
 * address of the first node that has that value.
 */
s_node_t* sl_find_value(DATA_TYPE to_find, s_node_t* head);


/*
 * Given an integer index of the list, return the pointer of the node at that
 * index.
 */
s_node_t* sl_find_index(uint64_t index, s_node_t* head);


/*
 * Find the number of elements in the singly-linked-list.
 */
uint64_t sl_len(s_node_t* head);


/*
 * Pop a node by location out of the list. This means the data at that node 
 * is returned and that node is removed from the sequence of the list.
 */
s_node_t* sl_pop(uint64_t location, s_node_t* head);


/* int main (int argc, char *argv[]) {

    return 0;
} */

#endif
