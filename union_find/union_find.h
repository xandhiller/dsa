// Author:  Alex Hiller
// Year:    2020


/* Defines & Enumerations */



/* Libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../arrays/dynamic_arrays.h"


/* Structures */
struct union_find {
    dynamic_array_t* array;
    uint64_t nb_vertices;
};
typedef struct union_find union_find_t;


/******************************************************************************/
/* NOTE ON DESIGN: An element of the structure will be such that a vertex is one 
 * index of the array. I.e., if an array has 5 indices it has 5 vertices. A 
 * vertex will either point to itself or another element, using the value in 
 * the array. E.g., {0,1,2,3,4} is a union_find where each node is its own root.
 * However {0,0,2,2,4} indicates that vertex/index 1 is connected to vertex 0, 
 * the same is true of index/vertex 2 being the root of vertex/index 3. */
/******************************************************************************/


void uf_init(union_find_t* uf, uint64_t nb_elems);
uint64_t uf_get_parent(uint64_t a, union_find_t* uf);
bool uf_is_root(uint64_t a, union_find_t* uf);
uint64_t ug_get_root(uint64_t a, union_find_t* uf);
bool uf_find(uint64_t a, uint64_t b, union_find_t* uf);
void uf_union(uint64_t a, uint64_t b, union_find_t* uf);
