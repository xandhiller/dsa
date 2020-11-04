/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    Implementing a simple queue (LIFO) built on dynamic arrays.
 */



#include "queue.h"


void queue_init(queue_t* q) {
    da_init(q->data);
}

/* Probably should change the return value to pointer in case the 
 * queue is empty. */
DATA_TYPE queue_poll(queue_t* q) {
    return da_pop(HEAD, q->data);
}

void queue_add(DATA_TYPE val, queue_t* q) {
    da_append(val, q->data);
}

int main (int argc, char *argv[]) {
    queue_t my_q;
    queue_init(&my_q);
    for (int i = 0; i < 40; i++) {
        queue_add(i, &my_q);
        printf("%d\n", i); 
    }
    for (int i = 0; i < 40; i++) {
        printf("%d\n", queue_poll(&my_q));
    }

    return 0;
}
