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
#define FAIL        -1


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
 * Swap the order of the two (non-NULL) input nodes (wrt the list).
 * Returns: TRUE if the swap worked, FALSE if it did not work.
 */
bool sl_swap_nodes(s_node_t* node_a, s_node_t* node_b, s_node_t* head) {
    if (node_a == NULL || node_b == NULL) {
        return FALSE;
    }
    s_node_t* trav_a = head;
    s_node_t* trav_b = head;
    /* Go until you're just before node_a, save to trav_a */
    while (trav_a->next != node_a) {
        trav_a = sl_next_node(trav_a);
        if (sl_is_end(trav_a)) {
            return FALSE;
        }
    }
    /* Keep going until you're just before node_b, save to trav_b */
    while (trav_b->next != node_b) {
        trav_b = sl_next_node(trav_b);
        if (sl_is_end(trav_b)) {
            return FALSE;
        }
    }
    /* Make the node before node_a (trav_a) point to node_b */
    trav_a->next = node_b;
    /* Make the node before node_b (trav_b) point to node_a */
    trav_b->next = node_a;
    return TRUE;
}


/*
 * Return the pointer to the node that is at the end of the list.
 */
s_node_t* sl_goto_end(s_node_t* head) {
    s_node_t* trav=head;
    while (!sl_is_end(trav)) {
        trav = sl_next_node(trav);
    }
    return trav;
}

/*
 * Add a node to the end of the list.
 */
bool sl_append(s_node_t* add_me, s_node_t* head) {
    s_node_t* end = sl_goto_end(head);
    end->next = (s_node_t*)malloc(sizeof(s_node_t));
    if (end->next == NULL) {
        return FALSE;
    }
    else {
        sl_init(end->next);
        return TRUE;
    }
}


/*
 * Insert a node after a given node, which.
 */
void sl_insert_after(s_node_t* to_insert, s_node_t* after_me) {
    if (to_insert != NULL) {
        /*Set new nodes next pointer to the next of after_me*/
        to_insert->next = after_me->next;
        /*Set after_me*/
        after_me->next = to_insert;
        return TRUE;
    }
    else {
        return FALSE;
    }
}


bool sl_insert_at(s_node_t* to_insert, uint64_t index, s_node_t* head) {
    /* If the node to insert or the head point to ∅, they are not nodes. */
    if (to_insert == NULL || head == NULL) {
        return FALSE;
    }
    s_node_t* trav = head;
    /* Find the node before where you want to insert */
    int i=0;
    bool found=FALSE;
    while (!sl_is_end(trav) && i<index-1) {
        trav = trav->next;
        i++;
        /* If we're not at the end and we're one index away from the desired
         * insertion point, then we've found it. */
        if (!sl_is_end(trav) && i==index-1) {
            found = TRUE;
        }
    }
    if (!found) {
        return FALSE;
    }
    else {
        to_insert->next = trav->next;
        trav->next = to_insert;
        return TRUE;
    }
}


/*
 * Given a specific DATA_TYPE value, and the head of the list, return the 
 * address of the first node that has that value.
 */
s_node_t* sl_find_value(DATA_TYPE to_find, s_node_t* head) {
    s_node_t* trav = head;
    while(!sl_is_end(trav)) {
        if(*(trav->data) == to_find) {
            return trav;
        }
        else {
            trav = trav->next;
        }
    }
    return NULL;
}


/*
 * Given an integer index of the list, return the pointer of the node at that
 * index.
 */
s_node_t* sl_find_index(uint64_t index, s_node_t* head) {
    s_node_t* trav = head;
    int i=0;
    while (trav != NULL && i<index) {
        trav = trav->next;
        i++;
    }
    return trav;
}


/*
 * Find the number of elements in the singly-linked-list.
 */
uint64_t sl_len(s_node_t* head) {
    int len=0;
    s_node_t* trav = head;
    while (!sl_is_end(trav)) {
        len++;
        trav = trav->next; 
    }
    return len;
}


/*
 * Pop a node by location out of the list. This means the data at that node 
 * is returned and that node is removed from the sequence of the list.
 */
s_node_t* sl_pop(uint64_t location, s_node_t* head) {
    /* If the location index is bigger than the list, cannot pop it. Also, if
     * the list is non-existent, can't pop. */
    if (location >= sl_len(head) || head == NULL) {
        return NULL;
    }
    int i=0;
    /* find location */
    s_node_t* pop = sl_find_index(location, head);
    s_node_t* before_pop = sl_find_index(location-1, head);
    /* Remove the node from the list but don't deallocate the memory, as you 
     * need the nodes contents to return to the user. */
    if (pop != NULL || before_pop != NULL) {
        return NULL;
    }
    else {
        /* Remove the node from the sequence of the list */
        before_pop->next = pop->next;
        return pop;
    }
}


int main (int argc, char *argv[]) {

    return 0;
}
