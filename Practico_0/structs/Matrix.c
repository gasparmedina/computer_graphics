#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"


Matrix* matrixNew(int n, int m)
{

    Matrix* matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->rows = n;
    matrix->columns = m;

    matrix->data = (float *)malloc(n*m*sizeof(float));

    for (int i = 0; i<n; i++){
        matrix->data[i] = (float *) malloc(m * sizeof(float));
    }

    for (int i = 0; i<n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            matrixSetElem(matrix, i, j, 0);

        }

    }

}

Matrix* matrixIdentity(int n, int m)
{



}

float matrixGetElem(Matrix* m, int r, int c)
{

}

void matrixSetElem(Matrix* m, int r, int c, float val)
{

   m->data[r][c] =  val;

}

void matrixFree(Matrix* m)
{

    free(m);

}


