/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    Implementing the "dynamic array" data structure in C.
 */


#include "dynamic_arrays.h"

/* Get and set length */
int da_get_length(dynamic_array_t* da) {
    return da->length;
}
void da_set_length(dynamic_array_t* da, int new_length) {
    da->length = new_length;
}

/* Get and set nb_vals */
int da_get_nb_vals(dynamic_array_t* da) {
    return da->nb_vals;
}
void da_set_nb_vals(dynamic_array_t* da, int new_nb_vals) {
    da->nb_vals = new_nb_vals;
}


/* Initialise the da by making the original array's pointer NULL, so it's not 
 * pointing to nonsense in memory. */
void da_init(dynamic_array_t* da) {
    da->data = NULL;
    da_set_length(da, 0);
    da_set_nb_vals(da, 0);
}


/* Expand the available slots in the array */
bool da_expand(dynamic_array_t* da) {
    int count = da_get_length(da);
    if (count == 0) {
        da->data = (DATA_TYPE*)realloc(da->data, sizeof(DATA_TYPE));
        if (da->data != NULL) {
            /* Only change the da's parameter if the allocation worked. */
            da_set_length(da, 1);
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
    /* Double the size of the array up until it's 128, then just add 128. Unless
     * the dynamic array is being used for a heap data structure, in which case 
     * just always double. */
//    if (count < MAX_CHUNK_SIZE) {
    else {
        da->data = (DATA_TYPE*)realloc(da->data, 2*count*sizeof(DATA_TYPE));
        /* If the memory allocation failed, let the user know */
        if (da->data != NULL) {
            /* Only change the da's parameter if the allocation worked. */
            da_set_length(da, 2*count);
            return TRUE;
        }
        else {
            return FALSE;
        }
    }
//    }
//   else {
//       da->data = (DATA_TYPE*)realloc(da->data, (count + 128)*sizeof(DATA_TYPE));
//       /* If the memory allocation failed, let the user know */
//       if (da->data != NULL) {
//           /* Only change the da's parameter if the allocation worked. */
//           da_set_length(da, count+128);
//           return TRUE;
//       }
//       else {
//           return FALSE;
//       }
//   }
}


/* Delete certain value from array and then resize. */
bool da_delete_val(DATA_TYPE val, dynamic_array_t* da) {
    int val_index=0, i=0;
    bool found=FALSE;
    for (i=0; i<da_get_length(da); val_index++, i++) {
        if (da->data[i] == val) {
            found=TRUE;
            break;
        }
    }
    if (found == FALSE) return FALSE;
    /* Move the elements after val_index to the left by one */
    for (int j=val_index; j<da->length; j++) {
        da->data[j] = da->data[j+1];
    }
    /* Resize the length attribut of the da struct */
    da_set_length(da, da->length-1);
    da_set_nb_vals(da, da->nb_vals-1);
    /* Officially allocate the memory that way */
    da->data = (DATA_TYPE*)realloc(da->data, (da->length)*sizeof(DATA_TYPE));
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
        da_set_nb_vals(da, da_get_nb_vals(da)-1);
        /* Decrement the count of length after the shift*/ 
        da_set_length(da, da_get_length(da)-1);
        /* Realloc the array to the size of length*/
        da->data = (DATA_TYPE*)realloc(da->data, da_get_length(da)*sizeof(DATA_TYPE));
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
    int length = da_get_nb_vals(da);
    for (int i=0; i<length; i++) {
        printf("%d ", da->data[i]); 
    }
    printf("\n"); 
}


void da_append(DATA_TYPE val, dynamic_array_t* da) {
    if (da_get_length(da) <= da_get_nb_vals(da)) {
        while (!da_expand(da));
    }
    da->data[da_get_nb_vals(da)] = val;
    da_set_nb_vals(da, da_get_nb_vals(da)+1);
}


/* Pop values from the front (HEAD), end of the list (TAIL), or index of a value */
DATA_TYPE da_pop(int location, dynamic_array_t* da) { 
    DATA_TYPE popped=0;
    if (location == HEAD) {
        popped = da->data[0];
        for (int i = 0; i < da->nb_vals; i++) {
            da->data[i] = da->data[i+1];
        }
        da->length = da->length-1;
        da->nb_vals = da->nb_vals-1;
        da->data = (DATA_TYPE*)realloc(da->data, (da->length)*sizeof(*da->data));

    }
    else if (location == TAIL) {
        popped = da->data[da->nb_vals-1];
        da->length = da->length-1;
        da->nb_vals = da->nb_vals-1;
        da->data = (DATA_TYPE*)realloc(da->data, (da->length)*sizeof(*da->data));
    }
    else if (location >=0 && location < da->nb_vals) {
        popped = da->data[location];

    }
    else {
        return '\0';
    }
    return popped;
}


void da_swap(uint64_t loc_a, uint64_t loc_b, dynamic_array_t* da) {
    DATA_TYPE temp = da->data[loc_a];
    da->data[loc_a] = da->data[loc_b];
    da->data[loc_b] = temp;
}


uint64_t* da_find_by_val(DATA_TYPE val, dynamic_array_t* da) {
    uint64_t len = da->nb_vals;
    uint64_t count = 0;
    uint64_t* indices = NULL;
    for (int i = 0; i < len; i++) {
        if (da->data[i] == val) {
            count++;
            indices = (uint64_t*)realloc(da->data, sizeof(count));
            indices[count-1] = i;
        }
    }
    return indices;
}


// int main (int argc, char *argv[]) {
//     dynamic_array_t my_da;
//     da_init(&my_da); 
//     /* test append */
//     for (int i=0; i<100; i++) {
//         da_append(99-i, &my_da);
//     }
//     da_display(&my_da);
//     /* test delete */
//     da_delete_val(5, &my_da);
//     da_display(&my_da);
//     da_delete_index(0, &my_da);
//     da_display(&my_da);
//     return 0;
// }
//
//
//
