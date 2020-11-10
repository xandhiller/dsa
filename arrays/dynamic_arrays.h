// Author:  Alex Hiller
// Year:    2020


#ifndef DYNAMIC_ARRAYS_H
#define DYNAMIC_ARRAYS_H


/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../dsa_settings.h"

 
struct dynamic_array {
    DA_DATA_TYPE* data;    /* Data array */
    uint64_t length;    /* Length of allocated space taken up by the array */
    uint64_t nb_vals;   /* Number of meaningful values stored in the array */
};
typedef struct dynamic_array dynamic_array_t;

/* Initialise the da by making the original array's pointer NULL, so it's not 
 * pointing to nonsense in memory. */
void da_init(dynamic_array_t* da);

/* Expand the available slots in the array */
bool da_expand(dynamic_array_t* da);

/* Delete certain value from array and then resize. */
bool da_delete_val(DA_DATA_TYPE val, dynamic_array_t* da);

/* Returns bool: TRUE if deletion successful, FALSE if deletion failed  */
bool da_delete_index(uint64_t index, dynamic_array_t* da);

void da_display(dynamic_array_t* da);

void da_append(DA_DATA_TYPE val, dynamic_array_t* da);

/* Pop values from the front (HEAD), end of the list (TAIL), or index of a value */
DA_DATA_TYPE da_pop(int location, dynamic_array_t* da);

/* Swap the values of loc_a and loc_b within the array, da */
void da_swap(uint64_t loc_a, uint64_t loc_b, dynamic_array_t* da);


/* Find the indices of a certain value in the array. Returns an array of 
 * indices */
uint64_t* da_find_by_val(DA_DATA_TYPE val, dynamic_array_t* da);


#endif
