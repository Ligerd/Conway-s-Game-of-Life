#include <stdlib.h>
#include "cellular_automaton.h"
#include "../matrix_of_cells/matrix_of_cells.h"
#include "../rules/rules.h"

int neighbours( matrix_s generation_t, int x, int y )
{
    int s = 0;
     if ( x > 0 )
    {
        if ( generation_t.matrix[x-1][y] == 1 )
            s++;

        if ( y > 0 )
            if ( generation_t.matrix[x-1][y-1] == 1 )
                s++;

        if ( y < generation_t.width - 1 )
            if ( generation_t.matrix[x-1][y+1] == 1 )
                s++;
    }

    if ( x < generation_t.height - 1 )
    {
        if ( generation_t.matrix[x+1][y] == 1 )
            s++;

        if ( y > 0 )
            if ( generation_t.matrix[x+1][y-1] == 1 )
                s++;

        if ( y < generation_t.width - 1 )
            if ( generation_t.matrix[x+1][y+1] == 1 )
                s++;
    }

    if ( y < generation_t.width - 1 )
        if ( generation_t.matrix[x][y+1] == 1 )
                s++;
    if ( y > 0 )
        if ( generation_t.matrix[x][y-1] == 1 )
                s++;
    return s;

}



void evolve( matrix_s * generation_t )
{
    int **tab = malloc ( generation_t->height * sizeof (int*));
    for (int i = 0; i < generation_t->height; ++i)
    {
        tab[i] = malloc ( generation_t->width * sizeof (int));
    }

    for (int i = 0; i < generation_t->height; ++i)
        for (int j = 0; j < generation_t->width; ++j)
            tab[i][j] = rules ( generation_t->matrix[i][j], neighbours( *(generation_t), i, j ) );

    free_T ( generation_t );
    generation_t->matrix = tab;

}

void create_name (char * name_of_file, char * name, int nr )
{
    sprintf(name_of_file, "wyniki/%s%d.png", name, nr);
}


int simulation( matrix_s * generation_t, char * name, int generation_nr, int series_or_one, void (*write_output)( matrix_s * generation_t, char* file_name) )
{
        char * name_of_file = malloc((strlen(name) + 40)*sizeof(char));
        for (int i = 0; i < generation_nr; ++i)
        {
              create_name( name_of_file, name, i);
              if ( series_or_one == 1 || i == generation_nr - 1)
                  write_output( generation_t, name_of_file);
              evolve( generation_t );
        }
        free_T ( generation_t );
        free (name_of_file);
        return 0;
}
