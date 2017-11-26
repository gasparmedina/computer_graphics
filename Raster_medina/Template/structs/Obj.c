#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structs/Obj.h"
#include "GL/gl.h"

/*
References

https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm
https://www.tutorialspoint.com/c_standard_library/c_function_strcspn.htm
https://www.tutorialspoint.com/c_standard_library/c_function_atof.htm
https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm
*/

/*
Lee cada linea del archivo obj, se fija si es un vertice,
y si es un vertice carga los valores en el obj que se paso
por parametro
*/
void loadVertices(Obj* obj, char* fileName)
{

    char temp[50];
    // Array de floats para almacenar las coordenadas de los vertices
    float coordinates[3];
    // Variable para almacenar los valores de los vertices x, y , z al hacer un stok
    char * token;
    // Definimos una variable para alamacenar un archivo
    FILE *file;
    // Variable para guardar cada linea del archivo a leer
    char storedString[60];
    // Abrimos el archivo que queremos leer, r nos dice que lo abrimos en modo de lectura
    file = fopen(fileName, "r");
    // Variable para contar la cantidad de vertices en el archivo  e ir agregando
    // al array de vertices del obj
    int countVertices = 0;
    // Vertice temporal para agregar la info del archivo y agregar a la lista del vertices del obj
    Vertex *vertexTemp;
    // Si el archivo no existe salimos con error
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        // Sino recorremos cada linea del archivo con la funcion fgets
        while ((fgets(storedString,60,file)) != NULL)
        {
            // Nos fijamos si la linea es un vertice
            if (storedString[0] == 'v' && storedString[1] == ' ')
            {
                token = strtok(storedString," ");

                for (int i=0; i<3; i++)
                {
                    token = strtok(NULL," ");
                    strcpy(temp,token);
                    temp[strcspn(temp," ")] = 0;
                    coordinates[i] = (float)atof(temp);
                }

                vertexTemp = (Vertex *)malloc(sizeof(Vertex));

                vertexTemp->x = coordinates[0];
                vertexTemp->y = coordinates[1];
                vertexTemp->z = coordinates[2];

                obj->vertices[countVertices] = vertexTemp;

                countVertices++;
            }

        }

        obj->numberOfVerts = countVertices;
    }

    // Cerramos la lectura del archivo.
    fclose(file);

}

/*
Lee cada linea del archivo obj, se fija si es una cara,
y si es una cara carga los valores en el obj que se paso
por parametro
*/
void loadFaces(Obj* obj, char* fileName)
{

    char temp[50];
    // Variable para almacenar los valores de los vertices x, y , z al hacer un stok
    char * token;
    // Definimos una variable para alamacenar un archivo
    FILE *file;
    // Variable para guardar cada linea del archivo a leer
    char storedString[60];
    // Abrimos el archivo que queremos leer, r nos dice que lo abrimos en modo de lectura
    file = fopen(fileName, "r");
    // Vertice temporal para agregar la info del archivo y agregar a la lista del vertices del obj
    Face *faceTemp;

    int countFaces = 0;
    int vert[4];
    int numsides = 4;

    // Si el archivo no existe salimos con error
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        // Sino recorremos cada linea del archivo con la funcion fgets
        while ((fgets(storedString,60,file)) != NULL)
        {
            int h = 0;
            // Nos fijamos si la linea es una cara
            if (storedString[0] == 'f' && storedString[1] == ' ')
            {
                token = strtok(storedString," ");

                while(((token = strtok(NULL," ")) != NULL))
                {
                    strcpy(temp,token);
                    temp[strcspn(temp,"/")] = 0;
                    vert[h] = (int)strtol(temp,NULL,10);
                    h++;
                }

                // Asignamos memoria para la nueva cara
                faceTemp = (Face *)malloc(sizeof(Face));
                //Le seteamos la cantidad de lados de la cara
                faceTemp-> numsides;
                // Cargamos los vertices de la cara
                for(int i=0; i<numsides; i++)
                {
                    faceTemp->vert[i] = vert[i];
                }

                // Cargamos la nueva cara al array de caras del struct obj
                obj->faces[countFaces] = faceTemp;

                countFaces++;

            }
        }

        obj->numberOfFaces = countFaces;
    }

    // Cerramos la lectura del archivo.
    fclose(file);

}


/*
Lee cada linea del archivo obj, se fija si es una normal de un vertice,
y si es una normal de un vertice carga los valores en el obj que se paso
por parametro
*/
void loadNormales(Obj* obj, char* fileName)
{

    char temp[50];
    // Array de floats para almacenar las coordenadas de las normales de los vertices
    float coordinates[3];
    // Variable para almacenar los valores de las normales del vertice x, y , z al hacer un stok
    char * token;
    // Definimos una variable para alamacenar un archivo
    FILE *file;
    // Variable para guardar cada linea del archivo a leer
    char storedString[60];
    // Abrimos el archivo que queremos leer, r nos dice que lo abrimos en modo de lectura
    file = fopen(fileName, "r");
    // Variable para contar la cantidad de vertices en el archivo  e ir agregando
    // al array de vertices del obj
    int countVerticesNormales = 0;
    // Vertice temporal para agregar la info del archivo y agregar a la lista del normales del obj
    Vertex *vertexTemp;
    // Sino recorremos cada linea del archivo con la funcion fgets
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        // Sino recorremos cada linea del archivo con la funcion fgets
        while ((fgets(storedString,60,file)) != NULL)
        {
            // Nos fijamos si la linea es un vertice
            if (storedString[1] == 'n' && storedString[2] == ' ')
            {
                token = strtok(storedString," ");

                for (int i=0; i<3; i++)
                {
                    token = strtok(NULL," ");
                    strcpy(temp,token);
                    temp[strcspn(temp," ")] = 0;
                    coordinates[i] = (float)atof(temp);
                }

                vertexTemp = (Vertex *)malloc(sizeof(Vertex));

                vertexTemp->x = coordinates[0];
                vertexTemp->y = coordinates[1];
                vertexTemp->z = coordinates[2];

                obj->normales[countVerticesNormales] = vertexTemp;

                countVerticesNormales++;
            }

        }

        obj->numberOfVertsNormal = countVerticesNormales;
    }

    // Cerramos la lectura del archivo.
    fclose(file);

}

void loadObj(char* fileName, Obj *objParam)
{

    // Cargamos los vertices al obj
    loadVertices(objParam, fileName);

    // Cargamos la normales de los vertices
    loadNormales(objParam, fileName);

    // Cargamos las caras al obj
    loadFaces(objParam, fileName);
}

void showObj(Obj * obj)
{
    int i;
    glBegin(GL_TRIANGLES);
    //glColor3f(1.0,0.0,0.0);
    for(i=0; i< obj->numberOfFaces; i++)
    {
        glVertex3f(
            obj->vertices[obj->faces[i]->vert[0] -1]->x,
            obj->vertices[obj->faces[i]->vert[0] -1]->y,
            obj->vertices[obj->faces[i]->vert[0] -1]->z
        );
        glVertex3f(
            obj->vertices[obj->faces[i]->vert[1] -1]->x,
            obj->vertices[obj->faces[i]->vert[1] -1]->y,
            obj->vertices[obj->faces[i]->vert[1] -1]->z
        );
        glVertex3f(
            obj->vertices[obj->faces[i]->vert[2] -1]->x,
            obj->vertices[obj->faces[i]->vert[2] -1]->y,
            obj->vertices[obj->faces[i]->vert[2] -1]->z
        );
    }
    glEnd();
}

void freeMemoryObj(Obj * obj)
{
    // Se libera la memora de las caras
    for (int i=0; i < obj->numberOfFaces; ++i)
    {
        free(obj->faces[i]);
    }

    // Se libera la memoria de los vertices
    for (int j = 0; j < obj->numberOfVerts; ++j)
    {
        free(obj->vertices[j]);
    }
    free(obj);
}

