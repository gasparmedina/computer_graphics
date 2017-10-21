#include <stdio.h>
#include <stdlib.h>
#include "util/arrayUtil.h"

void exercise4()
{

    int vec[100];

    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        vec[i] = rand() % 2;
    }

    printArray(100, vec);

    printf("\n");
    printf("\n");

}
