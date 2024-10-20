#ifndef CELL_H
#define CELL_H

#include<stdbool.h>

#define MAX_HERISSON_PAR_CASE 500

typedef struct cell {

    bool trap;
    int n_hedgehog;
    char hedgehogs[MAX_HERISSON_PAR_CASE];
    
} cell_t;

cell_t create_cell(bool trap);

#endif//CELL_H