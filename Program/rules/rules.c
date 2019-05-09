#include <stdlib.h>
#include "rules.h"

int rules( int cellular, int neighbours)
{
    if ( cellular == 1 )
    {
        if ( neighbours == 2 || neighbours == 3)
            return 1;
        else
            return 0;
    }
    else if ( cellular == 0 )
    {
         if ( neighbours == 3 )
            return 1;
        else
            return 0;
    }
    else
        return -1;
}
