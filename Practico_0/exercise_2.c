#include <stdio.h>
#include <stdlib.h>
#include "util/arrayUtil.h"

void exercise2()
{

    int vec[100];

    for (int i = 0; i < 100; i++)
    {
        vec[i] = i;
    }

    printArray(100, vec);

    printf("\n");
    printf("\n");

}
