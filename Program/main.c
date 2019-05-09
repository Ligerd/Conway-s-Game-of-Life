#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_of_cells/matrix_of_cells.h"
#include "cellular_automaton/cellular_automaton.h"
#include "txt_input/txt_input.h"
#include "png_input/png_input.h"
#include "write_png/write_png.h"
#include "read_arguments/read_arguments.h"



int main ( int argc, char ** argv )
{
    matrix_s M;
    arguments_s S;
    if ( read_arguments( argc, argv, &S) == -1 )
            return -1;

    if ( S.png_or_txt == 1)
        read_png( S.input_name, &M );
    else
        if ( read_txt( S.input_name, &M ) == -1 )
            return -1;


    simulation( &M, S.output_name, S.gen_nr, S.series_or_one, write_png );
    if ( S.if_gif == 1)
    {
        char cmd[255];
        strcpy (cmd, "convert -delay 15 -loop 0 ` ls -v wyniki/*.png ");
        strcat (cmd, " `  animation.gif " );
        system (cmd);
    }


    return 0;
}
