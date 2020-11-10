// Author:  Alex Hiller
// Year:    2020

#ifndef DSA_SETTINGS_H
#define DSA_SETTINGS_H

#define TRUE            1
#define FALSE           0
#define HEAD            -1
#define TAIL            -2

#define A_PRECEDES        1 
#define LEFT_PRECEDES     1
#define B_PRECEDES       -1
#define RIGHT_PRECEDES   -1
#define A_EQUAL_B         0

#define CHOOSE_SMALLEST   1
#define SWAP_RIGHT        2
#define SWAP_LEFT         3
#define DO_NOTHING        4

#include <stdint.h>
typedef uint8_t bool;

/******************************************************************************/
/* DATA TYPES for various data structures. */
/******************************************************************************/
#ifndef DA_DATA_TYPE 
#define DA_DATA_TYPE    void*
#endif

#ifndef Q_DATA_TYPE 
#define Q_DATA_TYPE     DA_DATA_TYPE
#endif

#ifndef ST_DATA_TYPE 
#define ST_DATA_TYPE    DA_DATA_TYPE
#endif

#ifndef HP_DATA_TYPE 
#define HP_DATA_TYPE    DA_DATA_TYPE
#endif

#ifndef UF_DATA_TYPE 
#define UF_DATA_TYPE    DA_DATA_TYPE
#endif

#ifndef BST_DATA_TYPE 
#define BST_DATA_TYPE   int
#endif

#endif
