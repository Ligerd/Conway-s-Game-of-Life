#ifndef CELLULAR_AUTOMATON_H
#define CELLULAR_AUTOMATON_H
#include <stdlib.h>
#include "../matrix_of_cells/matrix_of_cells.h"

int neighbours( matrix_s generation_t, int x, int y );

void evolve( matrix_s * generation_t );

int simulation( matrix_s * generation_t, char * name, int generation_nr, int series_or_one, void (*write_output)( matrix_s * generation_t, char* file_name) );
#endif // CELLULAR_AUTOMATON_H
