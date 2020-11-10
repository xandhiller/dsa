// Author:  Alex Hiller
// Year:    2020


#ifndef QUEUE_H
#define QUEUE_H


/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "../dsa_settings.h"
#include "../arrays/dynamic_arrays.h"

/* Structures */
struct queue {
    dynamic_array_t* data;
};
typedef struct queue queue_t;

void queue_init(queue_t* q);
Q_DATA_TYPE queue_poll(queue_t* q);
void queue_add(Q_DATA_TYPE val, queue_t* q);

#endif
