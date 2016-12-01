#include "Map.hpp"

Map::Map ()
{

    for 
    (
        int i = 0; 
        i < (sizeof (y)) / (sizeof (y[0])); 
        i++
    )
    {

        y[i] = ' ';

        for 
        (
            int j = 0; 
            j < (sizeof (x)) / (sizeof (x[0])); 
            j++
        )
        {

            x[j] = '.';

        }

    }

}