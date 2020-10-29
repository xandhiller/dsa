/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    An implementation of the "singly-linked-list" abstract data type.
 */


/* Libraries */
#include <stdlib.h>
#include <stdint.h>


#define DATA_TYPE   int
#define TRUE        1
#define FALSE       0


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
void sl_init(s_node_t* sl) {
    sl->data = NULL;
    sl->next = NULL;
}


/*
 * Returns the struct attribute "next", that points to the next node in the list.
 */
s_node_t* sl_get_next(s_node_t* sl) {
    return sl->next;
}


/*
 * Set (and possibly validate) the struct attribute "next" to the input value.
 */
bool sl_set_next(s_node_t* new_next, s_node_t* sl) {
    /* Validate pointer? */
    sl->next = new_next;
    return TRUE;
}


/*
 * Returns the "data" pointer for the given node.
 */
DATA_TYPE* sl_get_datap(s_node_t* sl) {
    return sl->data;
}


/*
 * Set (and possibly validate) the "data" pointer to the given node.
 */
bool sl_set_datap(DATA_TYPE* new_datap, s_node_t* sl) {
    /* Validate datap? */
    sl->data = new_datap;
    return TRUE;
}


/*
 * Determine whether the input node is the last node in the list.
 */
bool sl_is_end(s_node_t* sl) {
    if (sl->next == NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


/*
 * Return the next node from the node given as input.
 */
s_node_t* sl_next_node(s_node_t* sl) {
    return sl->next;
}


/*
 * Delete the node from the list, and free the memory associated with that node. 
 *  If node not found, do nothing and return the head.
 * Returns head of linked list after deletion of specified node, or if node not 
 *  found, returns the head of the list with the head unaltered.
 */
s_node_t* sl_delete_node(s_node_t* delete_this, s_node_t* head) {
    s_node_t* trav=head;
    /* Head is to be deleted */
    if (trav == delete_this) {
        s_node_t* new_head = trav->next;
        free(trav);
        return new_head;
    }
    /* Go until next is "delete this" */
    while(trav->next != delete_this) {
        trav = sl_next_node(trav);
        if (sl_is_end(trav)) {
            /* If the node is not found, the list is returned unaltered. */
            return head;
        }
    }
    /* "trav" is currently the node before "delete this" */
    /* Set the next node as the one after the one being deleted */
    trav->next = delete_this->next;
    free(delete_this);
    return head;
}


/*
 * Swap the order of the two input nodes (wrt the list).
 */
void sl_swap_nodes(void) {}


/*
 * Add a node to the end of the list.
 */
void sl_append(void) {}


/*
 * Pop a value by location out of the list. This means the data at that node 
 * is returned and that node is removed from the list.
 */
DATA_TYPE* sl_pop(void) {}


int main (int argc, char *argv[]) {
    /* <++> */

    return 0;
}
