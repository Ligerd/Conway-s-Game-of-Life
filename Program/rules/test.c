#include <stdio.h>
#include <stdlib.h>
#include "rules.h"
int main()
{
    if ( 0  != rules ( 0, 1 ) )
    {
        printf ("Test rules niezaliczony!\n");
        return -1;
    }
    if ( 1  != rules ( 0, 3 ) )
    {
        printf ("Test rules niezaliczony!\n");
        return -1;
    }
    if ( 0  != rules ( 1, 8 ) )
    {
        printf ("Test rules niezaliczony!\n");
        return -1;
    }
    if ( 1  != rules ( 1, 2 ) )
    {
        printf ("Test rules niezaliczony!\n");
        return -1;
    }
   if ( 1 != rules ( 1, 3 ) )
    {
        printf ("Test rules niezaliczony!\n");
        return -1;
    }
    if ( -1  != rules ( 4, 3 ) )
    {
        printf ("Test rules niezaliczony!\n");
        return -1;
    }

    printf ("Test rules zaliczony!\n");
    return 0;
}
