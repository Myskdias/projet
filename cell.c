#include "cell.h"

cell_t creer_cellule(bool pieger) {
    cell_t cell;
    cell.pieger = pieger;
    cell.nbr_herisson = 0;
    return cell;
}

