/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    An implementation of the binary search tree, using a linked list approach,
 *    in C.
 */


#include "binary_search_tree.h"



void bst_init(bst_node_t* root, BST_DATA_TYPE root_val) {
    root->val = root_val;
    /* Root node is its own parent. */
    root->parent = root;
    /* No children, point them to NULL. */
    root->left_child = NULL;
    root->right_child = NULL;
}


int8_t bst_order_rel(BST_DATA_TYPE a, BST_DATA_TYPE b) {
    return hp_order_rel(a, b);
}


void bst_insert(BST_DATA_TYPE to_insert, bst_node_t* root) {
    bst_node_t* trav = root;
    while (TRUE) {
        switch(bst_order_rel(trav->val, to_insert)) {
            /* Go left, to_insert is smaller than current node */
            case(A_PRECEDES):
                if (trav->left_child != NULL) {
                    trav = trav->left_child;
                    /* This break work? */
                    break;
                }
                else {
                    /* Insert the node here */
                    trav->left_child = (bst_node_t*)malloc(sizeof(bst_node_t));
                    trav->val = to_insert;
                    trav->left_child->parent = trav;
                    trav->left_child->left_child = NULL;
                    trav->left_child->right_child = NULL;
                    return;
                }
            /* Go right, to_insert is bigger than current node. */
            case(B_PRECEDES):
                if (trav->right_child != NULL) {
                    trav = trav->right_child;
                    break;
                }
                else {
                    /* Insert the node here */
                    trav->right_child = (bst_node_t*)malloc(sizeof(bst_node_t));
                    trav->val = to_insert;
                    trav->right_child->parent = trav;
                    trav->right_child->right_child = NULL;
                    trav->right_child->right_child = NULL;
                    return;
                }
            /* Only unique values in the tree, you can leave. */
            case(A_EQUAL_B):
                return;
                break;
        }
    }
}


bst_node_t* bst_find(void) {
}


void bst_delete(bst_node_t* to_delete, bst_node_t* root) {
}

bool is_power_of_two(uint64_t x) {
    return ((x != 0) && ((x & (~x + 1)) == x));
}

void bst_display(bst_node_t* root) {
    queue_t v_to_print; 
    queue_t* to_print = &v_to_print;
    queue_init(to_print);
    queue_add(root, to_print);
    uint64_t count = 0;
    while (to_print->data->nb_vals != 0) {
        /* Poll the queue, save that val, and print its return value */
        bst_node_t* current = (bst_node_t*)queue_poll(to_print);
        printf("%d\n", current->val); 
        count++;
        /* Get the children and add to the queue if they're not NULL */
        if (current->left_child != NULL) {
            queue_add(current->left_child, to_print);
        }
        if (current->right_child != NULL) {
            queue_add(current->right_child, to_print);
        }
        /* If count is a power of two, print a newline. */
        if (is_power_of_two(count)) {
            printf("\n"); 
        }
    }
}



int main (int argc, char *argv[]) {
    bst_node_t v_root;
    bst_node_t* root = &v_root;
    bst_init(root, 10);
    bst_insert(20, root);
    bst_insert(5, root);
    bst_insert(11, root);
    bst_insert(6, root);
    bst_insert(4, root);
    bst_display(root);
    return 0;
}
