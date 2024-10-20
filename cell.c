#include "cell.h"

cell_t create_cell(bool trap) {
    cell_t cell;
    cell.trap = trap;
    cell.n_hedgehog = 0;
    return cell;
}

