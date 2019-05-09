#include <stdio.h>
#include <stdlib.h>
#include "../matrix_of_cells/matrix_of_cells.h"
#include "txt_input.h"

matrix_s Ma;

int main()
{
    int test_t[8][6] = {{1,0,1,0,1,1},
                        {0,0,0,0,0,0},
                        {1,1,1,1,1,1},
                        {1,0,1,1,1,1},
                        {1,1,0,1,0,0},
                        {1,0,1,0,1,1},
                        {0,0,0,0,0,1},
                        {1,0,1,1,1,1}};

    read_txt("test.txt", &Ma );

    if (Ma.height != 8)
    {
        printf("Test txt_input niezaliczony!\n");
        return -2;
    }
     if (Ma.width != 6)
    {
        printf("Test txt_input niezaliczony!\n");
        return -2;
    }


    for ( int i = 0; i < Ma.height; ++i )
    {
        for ( int j = 0; j < Ma.width; ++j )
            if ( test_t[i][j] !=  Ma.matrix[i][j])
            {
                printf("Test txt_input niezaliczony!\n");
                return -1;
            }

      }
    printf("Test txt_input zaliczony!\n");
    free_T( &Ma );


    return 0;
}
