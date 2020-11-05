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
    if (a < b) {
        return A_PRECEDES;
    }
    else if (b < a) {
        return B_PRECEDES;
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
        uint64_t* indices = (uint64_t*)malloc(3*sizeof(uint64_t));
        indices[0] = 2;
        indices[1] = 2*index+1;
        indices[2] = 2*index+2;
        return indices;
    } 
    /* The node only has one child */
    else if (hp->array->nb_vals == 2*index) {
        uint64_t* indices = (uint64_t*)malloc(2*sizeof(uint64_t));
        indices[0] = 2;
        indices[1] = 2*index+1;
        return indices;
    }
    /* Node does not have children */
    else {
        uint64_t* indices = (uint64_t*)malloc(sizeof(uint64_t));
        indices[0] = 0;
        return indices;
    }
}


uint64_t hp_get_parent(uint64_t index) {
    /* If the index the root, it is its own parent. */
    if (index == 0) {
        return 0;
    }
    /* Otherwise, the node has a parent. */
    else {
        /* Integer division is important here. */
        return (index-1)/2; 
    }
}



void hp_bubble_up(uint64_t location, heap_t* hp) {
    uint64_t parent_index = hp_get_parent(location);
    switch(hp_order_rel(hp->array->data[location], hp->array->data[parent_index])) { 
        case(A_PRECEDES):
            da_swap(location, parent_index, hp->array);
            location = parent_index;
            hp_bubble_up(location, hp);
            break;
        case(B_PRECEDES):
            return;
            break;
        case(A_EQUAL_B):
            return;
            break;
    }
}

uint8_t hp_bubble_down_action(DATA_TYPE left_child, DATA_TYPE right_child, DATA_TYPE current) {
    uint8_t l_to_c = hp_order_rel(left_child,  current);
    uint8_t r_to_c = hp_order_rel(right_child, current);
    uint8_t l_to_r = hp_order_rel(left_child,  right_child);
    /* Both of the children could be before the current node. */
    if (l_to_c == A_PRECEDES && r_to_c == A_PRECEDES) {
        if (l_to_r == B_PRECEDES) {
            return SWAP_RIGHT;
        }
        /* Default to swapping left if they tie. */
        else {
            return SWAP_LEFT;
        }
    }
    else if (l_to_c == A_EQUAL_B && r_to_c == A_PRECEDES) {
        return SWAP_RIGHT;
    }
    else if (l_to_c == B_PRECEDES && r_to_c == A_PRECEDES) {
        return SWAP_RIGHT;
    }
    else if (l_to_c == A_PRECEDES && r_to_c == A_EQUAL_B) {
        return SWAP_LEFT;
    }
    else if (l_to_c == A_EQUAL_B && r_to_c == A_EQUAL_B) {
        return DO_NOTHING;
    }
    else if (l_to_c == B_PRECEDES && r_to_c == A_EQUAL_B) {
        return DO_NOTHING;
    }
    else if (l_to_c == A_PRECEDES && r_to_c == B_PRECEDES) {
        return SWAP_LEFT;
    }
    else if (l_to_c == A_EQUAL_B && r_to_c == B_PRECEDES) {
        return DO_NOTHING;
    }
    else if (l_to_c == B_PRECEDES && r_to_c == B_PRECEDES) {
        return DO_NOTHING;
    }
}


void hp_bubble_down(uint64_t location, heap_t* hp) {
    uint64_t* child_inds = hp_get_children(location, hp);
    uint8_t nb_child = child_inds[0];
    /* If there are no children on the current location then you cannot bubble
     * down. */
    if (nb_child == 0) {
        free(child_inds);
        return;
    }
    else if (nb_child == 1) {
        uint64_t left_child  = child_inds[1];
        free(child_inds);
        /* Storage defaults to creating left node first, so check left. */
        DATA_TYPE l_child_value  = hp->array->data[left_child];
        DATA_TYPE current_value = hp->array->data[location];
        if (hp_order_rel(l_child_value, current_value) == A_PRECEDES) {
            /* Swap left */
            da_swap(location, left_child, hp->array);
            location = left_child;
            hp_bubble_down(location, hp);
        }
        else {
            return;
        }
    }
    else if (nb_child == 2) {
        uint64_t left_child  = child_inds[1];
        uint64_t right_child = child_inds[2];
        free(child_inds);
        DATA_TYPE l_child_value  = hp->array->data[left_child];
        DATA_TYPE r_child_value = hp->array->data[right_child];
        DATA_TYPE current_value = hp->array->data[location];
        switch(hp_bubble_down_action(l_child_value, r_child_value, current_value)) {
            case(SWAP_LEFT):
                da_swap(location, left_child, hp->array);
                location = left_child;
                hp_bubble_down(location, hp);
                break;
            case(SWAP_RIGHT):
                da_swap(location, left_child, hp->array);
                location = right_child;
                hp_bubble_down(location, hp);
                break;
            case(DO_NOTHING):
                break;
        }
    }
    return;
}


void hp_add(DATA_TYPE val, heap_t* hp) {
    da_append(val, hp->array);
    hp_bubble_up(hp->array->nb_vals-1, hp);
}


DATA_TYPE* hp_pop_by_val(DATA_TYPE val, heap_t* hp) {
    /* Find val's index with end */
    uint64_t* indices = da_find_by_val(val, hp->array);
    if (indices == NULL) {
        free(indices);
        return NULL;
    }
    /* Swap val with the last value */
    da_swap(
    /* Pop end  */
    /* Bubble down the new root */
    /* Return the popped value */
}


int main (int argc, char *argv[]) {
    /* ; */

    return 0;
}
