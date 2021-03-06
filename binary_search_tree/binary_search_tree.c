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


void bst_insert(BST_DATA_TYPE to_insert, bst_node_t* root) {
    bst_node_t* trav = root;
    while (TRUE) {
        switch(bst_order_rel(to_insert, trav->val)) {
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
                    trav->left_child->val = to_insert;
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
                    trav->right_child->val = to_insert;
                    trav->right_child->parent = trav;
                    trav->right_child->left_child = NULL;
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


bst_node_t* bst_find(BST_DATA_TYPE to_find, bst_node_t* root) {
    bst_node_t* trav = root;
    while (trav->val != to_find) {
        /* If the node is NULL then you're at the end of the bst and you 
         * haven't found the value requested. */
        if (trav == NULL) {
            return NULL;
        }
        switch (bst_order_rel(to_find, trav->val))  {
            case(A_PRECEDES):
                trav = trav->left_child;
                break;
            case(B_PRECEDES):
                trav = trav->right_child;
                break;
            case(A_EQUAL_B):
                return trav;
                break;
        } 
    /* Fail-safe: Value not found. */
    return NULL;
}




bool is_power_of_two(uint64_t x) {
    return ((x != 0) && ((x & (~x + 1)) == x));
}


void bst_display(bst_node_t* root) {
    queue_t* to_print = (queue_t*)malloc(sizeof(queue_t));
    queue_init(to_print);
    queue_add(root, to_print);
    uint64_t count = 0;
    /* Note that the sum of m-terms of powers of two is  2^(m+1)-1. */
    uint64_t row_count = 0;
    while (to_print->data->nb_vals != 0) {
        /* Poll the queue, save that val, and print its return value */
        bst_node_t* current = (bst_node_t*)queue_poll(to_print);
        printf("%c ", current->val); 
        count++;
        /* Get the children and add to the queue if they're not NULL */
        if (current->left_child != NULL) {
            queue_add(current->left_child, to_print);
        }
        if (current->right_child != NULL) {
            queue_add(current->right_child, to_print);
        }
        /* If count is a sum of a power of two, print a newline. */
        if (count == (1 << (row_count+1))-1) {
            row_count++;
            printf("\n"); 
        }
    }
    printf("\n"); 
}


bst_node_t* bst_biggest_val(bst_node_t* root) {
    bst_node_t* trav = root;
    while (trav->right_child != NULL) {
        trav = trav->right_child;
    }
    return trav;
}


bst_node_t* bst_smallest_val(bst_node_t* root) {
    bst_node_t* trav = root;
    while (trav->left_child != NULL) {
        trav = trav->left_child;
    }
    return trav;
}


uint8_t bst_deletion_case(bst_node_t* to_delete) {
    if (to_delete->left_child == NULL && to_delete->right_child == NULL) {
        return LEAF_NODE;
    }
    if (to_delete->left_child != NULL && to_delete->right_child == NULL) {
        return LEFT_SUB_TREE;
    }
    if (to_delete->left_child == NULL && to_delete->right_child != NULL) {
        return RIGHT_SUB_TREE;
    }
    if (to_delete->left_child != NULL && to_delete->right_child != NULL) {
        return L_AND_R_SUB_TREE;
    }
    /* Failsafe. */
    return FALSE;
}


uint8_t bst_which_child(bst_node_t* current) {
    /* Invalid input. */
    if (current == NULL) {
        return FALSE;
    }
    /* If it is its own parent, its root. */
    else if (current->parent == current) {
        return IS_ROOT;
    }
    else if (current->parent->right_child == current) {
        return IS_RIGHT_CHILD;
    }
    else if (current->parent->left_child == current) {
        return IS_LEFT_CHILD;
    }
    /* Fail-safe. */
    return FALSE;
}


/* Source: https://www.codesdope.com/blog/article/binary-search-tree-in-c/ */
bst_node_t* bst_delete(BST_DATA_TYPE to_delete, bst_node_t* root) {
    /* searching for the item to be deleted */
    if (root==NULL) {
        return NULL;
    }
    if (to_delete > root->val) {
        root->right_child = bst_delete(to_delete, root->right_child);
    }
    else if (to_delete < root->val) {
        root->left_child = bst_delete(to_delete, root->left_child);
    }
    else {
        /* No children */
        if (root->left_child==NULL && root->right_child==NULL) {
            free(root);
            return NULL;
        }
        /* One child */
        else if (root->left_child==NULL || root->right_child==NULL) {
            bst_node_t* temp;
            if (root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }
        /* Two children */
        else {
            bst_node_t* temp = bst_smallest_val(root->right_child);
            root->val = temp->val;
            root->right_child = bst_delete(temp->val, root->right_child);
        }
    }
    return root;
}







int main (int argc, char *argv[]) {
    bst_node_t* root = (bst_node_t*)malloc(sizeof(bst_node_t));
    bst_init(root, 10);
    bst_insert(20 , root);
    bst_insert(5 , root);
    bst_insert(1 , root);
    bst_insert(15 , root);
    bst_insert(9 , root);
    bst_insert(7 , root);
    bst_insert(12 , root);
    bst_insert(30 , root);
    bst_insert(25 , root);
    bst_insert(40 , root);
    bst_insert(45 , root);
    bst_insert(42 , root);
    bst_display(root);
    return 0;
}
