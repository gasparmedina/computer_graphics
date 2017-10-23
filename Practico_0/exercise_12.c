#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void exercise12()
{

    int rows, cloumns;

    printf("Ingrese cantidad de filas: ");
    scanf("%i", &rows);

    printf("Ingrese cantidad de columnas: ");
    scanf("%i", &cloumns);

    Vec3 ** array = (Vec3 **)malloc(rows * sizeof(Vec3 *));

    for (int i = 0; i<rows; i++){
        array[i] = (Vec3 *) malloc(cloumns * sizeof(Vec3));
    }

    for (int i = 0; i<rows; i++)
    {
        for(int j = 0; j< cloumns; j++)
        {
            array[i][j] = vec3RandomCustomInterval(12,52);

        }

    }


    for (int i = 0; i<rows; i++)
    {
        printf("\n");

        for(int j = 0; j< cloumns; j++)
        {
            vec3Print(&array[i][j]);
        }

    }


    free(array);

}
