#include <stdio.h>
#include <stdlib.h>

void writeFile(char fileName [], int *vec, int vecSize)
{

    FILE *outPutFile;

    outPutFile = fopen(fileName, "w");

    if (outPutFile == NULL)
    {
        fprintf(stderr, "No se puede abrir el archivo de salida \n");
    }

    for (int i = 0; i < vecSize; i++)
    {
        if (i == 0)
        {
            fprintf(outPutFile, "[%d",vec[i]);
        }
        else if (i == vecSize - 1)
        {
            fprintf(outPutFile, ",%d]", vec[i]);
        }
        else
        {
            fprintf(outPutFile, ",%d", vec[i]);
        }

    }

    fclose(outPutFile);
}

