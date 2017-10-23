#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct
{

    int rows;
    int columns;
    float **data;

} Matrix;


Matrix* matrixNew(int n, int m);

Matrix* matrixIdentity(int n, int m);

float matrixGetElem(Matrix* m, int r, int c);

void matrixSetElem(Matrix* m, int r, int c, float val);

void matrixFree(Matrix* m);

#endif // MATRIX_H_INCLUDED
