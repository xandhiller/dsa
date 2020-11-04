
// Author:  Alex Hiller
// Year:    2020

/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


#define MAX_CHUNK_SIZE  128
#define TRUE            1
#define FALSE           0
#define DATA_TYPE       int
#define HEAD            -1
#define TAIL            -2


struct dynamic_array {
    DATA_TYPE* data;    /* Data array */
    int length;         /* Length of allocated space taken up by the array */
    int nb_vals;        /* Number of meaningful values stored in the array */
};
typedef struct dynamic_array dynamic_array_t;


typedef uint8_t bool;

int da_get_length(dynamic_array_t* da);

void da_set_length(dynamic_array_t* da, int new_length);

int da_get_nb_vals(dynamic_array_t* da);

void da_set_nb_vals(dynamic_array_t* da, int new_nb_vals);

/* Initialise the da by making the original array's pointer NULL, so it's not 
 * pointing to nonsense in memory. */
void da_init(dynamic_array_t* da);

/* Expand the available slots in the array */
bool da_expand(dynamic_array_t* da);

/* Delete certain value from array and then resize. */
bool da_delete_val(DATA_TYPE val, dynamic_array_t* da);

/* Returns bool: TRUE if deletion successful, FALSE if deletion failed  */
bool da_delete_index(uint64_t index, dynamic_array_t* da);

void da_display(dynamic_array_t* da);

void da_append(DATA_TYPE val, dynamic_array_t* da);

/* Pop values from the front (HEAD), end of the list (TAIL), or index of a value */
int da_pop(int location, dynamic_array_t* da);
