#ifndef CELL_H
#define CELL_H

#include<stdbool.h>

#define MAX_HERISSON_PAR_CASE 500

typedef struct cell {

    bool pieger;
    int nbr_herisson;
    char herissons[MAX_HERISSON_PAR_CASE];
    
} cell_t;

cell_t creer_cellule(bool pieger);

#endif//CELL_H