/* Author: Alex Hiller
 * Year: 2020
 *
 * Program Description: 
 *    Question: Whether local copies of structs are made in functions.
 *    Ans: Yes.
 */

/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


/* Structures */
struct blah {
    int data;
};
typedef struct blah blah_t;


void mod_blah(blah_t* b) {
    b->data = 222;
}

int main (int argc, char *argv[]) {
    blah_t my_blah;
    printf("%d\n", my_blah.data); 
    mod_blah(&my_blah);
    printf("%d\n", my_blah.data); 
    return 0;
}
