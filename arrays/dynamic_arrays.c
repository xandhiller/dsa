/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    Implementing the "dynamic array" data structure in C.
 */


#include "dynamic_arrays.h"


/* Initialise the da by making the original array's pointer NULL, so it's not 
 * pointing to nonsense in memory. */
void da_init(dynamic_array_t* da) {
    da->data = NULL;
    da->length = 0;
    da->nb_vals = 0;
}


/* Expand the available slots in the array */
bool da_expand(dynamic_array_t* da) {
    int count = da->length;
    /* If it has no elements, allocate the first one. */
    if (count == 0) {
        da->data = (DA_DATA_TYPE*)realloc(da->data, sizeof(DA_DATA_TYPE));
        if (da->data != NULL) {
            /* Only change the da's parameter if the allocation worked. */  
            da->length = 1;
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
    /* Double the size of the array. */
    else {
        da->data = (DA_DATA_TYPE*)realloc(da->data, 2*count*sizeof(DA_DATA_TYPE));
        /* If the memory allocation failed, let the user know */
        if (da->data != NULL) {
            /* Only change the da's parameter if the allocation worked. */
            da->length = 2*count;
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
}


/* Delete certain value from array and then resize. */
bool da_delete_val(DA_DATA_TYPE val, dynamic_array_t* da) {
    int val_index=0, i=0;
    bool found=FALSE;
    /* Perform the search. */
    for (i=0; i<(da->length); val_index++, i++) {
        if (da->data[i] == val) {
            found=TRUE;
            break;
        }
    }
    if (found == FALSE) {
        return FALSE;
    }
    /* Move the elements after val_index to the left by one */
    for (int j=val_index; j<da->length; j++) {
        da->data[j] = da->data[j+1];
    }
    /* Resize the length attribut of the da struct */
    da->length = da->length-1;
    da->nb_vals = da->nb_vals-1;
    /* Officially allocate the memory that way */
    da->data = (DA_DATA_TYPE*)realloc(da->data, (da->length)*sizeof(DA_DATA_TYPE));
    /* If the memory allocation failed, let the user know */
    if (da->data != NULL) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


/* Returns bool: TRUE if deletion successful, FALSE if deletion failed  */
bool da_delete_index(uint64_t index, dynamic_array_t* da) {
    /* Cannot delete value if the index is greater than the number of values */
    if (index >= da->nb_vals) {
        return FALSE;
    }
    else {
        /* Left shift the values after the index*/
        for (int i = index; i < da->nb_vals; i++) {
            da->data[i] = da->data[i+1];
        }
        /* Decrement the count of nb_vals after the shift*/ 
        da->nb_vals = da->nb_vals-1;
        /* Decrement the count of length after the shift*/ 
        da->length = da->length-1;
        /* Realloc the array to the size of length*/
        da->data = (DA_DATA_TYPE*)realloc(da->data, da->length*sizeof(DA_DATA_TYPE));
        /* If the memory allocation failed, the deletion failed.*/
        if (da->data != NULL) {
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
}


void da_display(dynamic_array_t* da) {
    int length = da->nb_vals;
    for (int i=0; i<length; i++) {
        printf("%d ", da->data[i]); 
    }
    printf("\n"); 
}


void da_append(DA_DATA_TYPE val, dynamic_array_t* da) {
    if (da->length <= da->nb_vals) {
        while (!da_expand(da));
    }
    da->data[da->nb_vals] = val;
    da->nb_vals = da->nb_vals+1;
}


/* Pop values from the front (HEAD), end of the list (TAIL), or index of a value */
DA_DATA_TYPE da_pop(int location, dynamic_array_t* da) { 
    if (location == HEAD) {
        DA_DATA_TYPE popped = da->data[0];
        for (int i = 0; i < da->nb_vals; i++) {
            da->data[i] = da->data[i+1];
        }
        da->length = da->length-1;
        da->nb_vals = da->nb_vals-1;
        da->data = (DA_DATA_TYPE*)realloc(da->data, (da->length)*sizeof(DA_DATA_TYPE));
        return popped;
    }
    else if (location == TAIL) {
        DA_DATA_TYPE popped = da->data[da->nb_vals-1];
        da->length = da->length-1;
        da->nb_vals = da->nb_vals-1;
        da->data = (DA_DATA_TYPE*)realloc(da->data, (da->length)*sizeof(DA_DATA_TYPE));
        return popped;
    }
    else if (location >=0 && location < da->nb_vals) {
        DA_DATA_TYPE popped = da->data[location];
        return popped;
    }
    else {
        /* Safest thing to return from a fn with various possible types. */
        return NULL;
    }
}


void da_swap(uint64_t loc_a, uint64_t loc_b, dynamic_array_t* da) {
    DA_DATA_TYPE temp = da->data[loc_a];
    da->data[loc_a] = da->data[loc_b];
    da->data[loc_b] = temp;
}


uint64_t* da_find_by_val(DA_DATA_TYPE val, dynamic_array_t* da) {
    uint64_t len = da->nb_vals;
    uint64_t count = 0;
    uint64_t* indices = (uint64_t*)malloc(sizeof(uint64_t));
    for (int i=0; i<len; i++) {
        if (da->data[i] == val) {
            count++;
            indices = (uint64_t*)realloc(indices, sizeof(uint64_t)*(count+1));
            indices[count] = i;
        }
    }
    indices[0] = count;
    return indices;
}

/*
    int main (int argc, char *argv[]) {
        dynamic_array_t my_da;
        da_init(&my_da); 
        for (int i=0; i<100; i++) {
            da_append(99-i, &my_da);
        }
        da_display(&my_da);
        da_delete_val(5, &my_da);
        da_display(&my_da);
        da_delete_index(0, &my_da);
        da_display(&my_da);
        return 0;
    }
*/



