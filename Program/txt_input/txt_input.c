#include <stdio.h>
#include <stdlib.h>
#include "../matrix_of_cells/matrix_of_cells.h"
#include <string.h>
#include <ctype.h>
#include "txt_input.h"


int read_txt ( char * name, matrix_s * M )
{
    FILE * IN = fopen ( name, "r");
    if ( IN == NULL )
    {
       printf("Podany plik nie istnieje lub brak dostatecznych praw do otwarcia.\n");
       return -1;
    }

    int width = 0, s = 1, height = 1, test_width = 0;
    char buf;
    buf = getc ( IN );

    while (  buf != EOF )
    {
        while( isblank( buf ) != 0 )
        {
           buf = getc ( IN );
        }

        if ( height == 1 && (isalnum(buf) != 0) )
        {
            width++;
            test_width++;
        }

        if ( height > 1 && (isalnum(buf) != 0) )
            test_width++;

        if ( buf == '\n' )
        {
            if ( test_width == 0 )
            {
                buf = getc ( IN );
                if ( buf == EOF )
                {
                   height--;
                }
            }

            else
            {
                 if ( test_width != width )
                {
					fclose( IN );
                    printf("Blad w pliku wejsciowym! Liczba znakow w wierszy %d jest inna od liczby znaków  wierszy 1.\n", height);
                    return -1;
                }

                height++;
                test_width = 0;
                buf = getc ( IN );
                if ( buf == EOF )
                {
                   height--;
                }
            }
        }
        else
            buf = getc ( IN );
    }

    init_T ( M, width, height );
    fseek( IN, 0, SEEK_SET );

    for ( int i = 0; i < height; ++i )
    {
            for ( int j = 0; j < width; ++j )
            {
                    buf = getc( IN );

                    while(  isalnum( buf ) == 0  )
                    {
                        buf = getc ( IN );
                    }

					if ( i >= 0 && j >= 0)
						if ( isdigit(buf) == 0 && isspace(buf) == 0 && buf != EOF )
							{
								fclose( IN );
								printf("Blad w pliku wejsciowym! Znak w linii %d w kolumnie %d jest rozny od 0 oraz 1.\n", i+1, j+1);
								return -1;
							}
						else
							if ( ( buf -'0' ) == 0 || ( buf -'0' ) == 1 )
								M->matrix[i][j] = ( buf -'0' );

							else
							{
								printf ("sa%d\n", ( buf -'0' ));
								fclose( IN );
								printf("Blad w pliku wejsciowym! Znak w linii %d w kolumnie %d jest rozny od 0 oraz 1.\n", i+1, j+1);
								return -1;
							}
            }
    }
    fclose( IN );
    return 0;
}


