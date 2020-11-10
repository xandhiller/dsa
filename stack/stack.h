// Author:  Alex Hiller
// Year:    2020

#ifndef STACK_H
#define STACK_H

/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "../arrays/dynamic_arrays.h"

/* Structures */
struct stack {
    dynamic_array_t* data;
};
typedef struct stack stack_t;

void stack_init(stack_t* st);
void stack_add(stack_t* st, ST_DATA_TYPE val);
ST_DATA_TYPE stack_pop(stack_t* st);

#endif
