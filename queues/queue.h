// Author:  Alex Hiller
// Year:    2020


/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "../arrays/dynamic_arrays.h"

/* Structures */
struct queue {
    dynamic_array_t* data;
};
typedef struct queue queue_t;

void queue_init(queue_t* q);
DATA_TYPE queue_poll(queue_t* q);
void queue_add(DATA_TYPE val, queue_t* q);
