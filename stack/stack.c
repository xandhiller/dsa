/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    <++>
 */

#include "stack.h"

void stack_init(stack_t* st) {
    da_init(st->data);
}

void stack_add(stack_t* st, DATA_TYPE val) {
    da_append(val, st->data);
}

DATA_TYPE stack_pop(stack_t* st) {
    return da_pop(TAIL, st->data);
}


int main (int argc, char *argv[]) {
    stack_t my_stack;
    stack_init(&my_stack);
    for (int i = 0; i < 50; i++) {
        stack_add(&my_stack, i);
        printf("%d\n", i); 
    }
    for (int i = 0; i < 50; i++) {
        printf("%d\n", stack_pop(&my_stack));
    }


    return 0;
}
