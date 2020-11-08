/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    An implementation of the binary search tree, using a linked list approach,
 *    in C.
 */


#include "binary_search_tree.h"



void bst_init(bst_node_t* root, DATA_TYPE root_val) {
    root->val = root_val;
    /* Root node is its own parent. */
    root->parent = root;
    /* No children, point them to NULL. */
    root->left_child = NULL;
    root->right_child = NULL;
}


int8_t bst_order_rel(DATA_TYPE a, DATA_TYPE b) {
    return hp_order_rel(a, b);
}


void bst_insert(DATA_TYPE to_insert, bst_node_t* root) {
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



int main (int argc, char *argv[]) {
    /* <++> */

    return 0;
}
