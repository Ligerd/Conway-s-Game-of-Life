#include <stdio.h>
#include <stdlib.h>
#include "../txt_input/txt_input.h"
#include "cellular_automaton.h"
#include "../matrix_of_cells/matrix_of_cells.h"

void write_test( matrix_s * M, char* file_name )
{
    int test_t[5][5] = {{0,0,0,0,0},
                          {0,1,0,1,0},
                          {0,0,1,1,0},
                          {0,0,1,0,0},
                          {0,0,0,0,0}};

        for ( int i = 0; i < M->height; ++i )
        {
        for ( int j = 0; j < M->width; ++j )
            if ( test_t[i][j] != M->matrix[i][j])
            {
                printf("Niepowodzenie testu cellular_automaton!\n");
                return;
            }

        }
        printf("Test cellular_automaton zaliczony!\n");
       return;



}

matrix_s M;
int main()
{
    read_txt( "test.txt", &M );

    simulation( &M, "test.png", 2, 0, write_test);


    return 0;
}
