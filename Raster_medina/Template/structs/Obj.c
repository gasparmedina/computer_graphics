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
http://pubs.opengroup.org/onlinepubs/009695399/functions/strdup.html
https://fresh2refresh.com/c-programming/c-strings/c-strdup-function/
*/

float * vertices;
float * normales;
float * texturas;

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
Lee cada linea del archivo obj, se fija si es una textura
y si es una textura carga los valores en el obj que se paso
por parametro
*/
void loadTextures(Obj* obj, char* fileName)
{

    char temp[50];
    // Array de floats para almacenar las coordenadas de los vertices
    float coordinates[2];
    // Variable para almacenar los valores de las texturas x, y al hacer un stok
    char * token;
    // Definimos una variable para alamacenar un archivo
    FILE *file;
    // Variable para guardar cada linea del archivo a leer
    char storedString[60];
    // Abrimos el archivo que queremos leer, r nos dice que lo abrimos en modo de lectura
    file = fopen(fileName, "r");
    // Variable para contar la cantidad de texturas en el archivo  e ir agregando
    // al array de texturas del obj
    int countTextures = 0;
    // Textura temporal para agregar la info del archivo y agregar a la lista de texturas del obj
    TextureVertex *textureVertexTemp;
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
            if (storedString[1] == 't' && storedString[2] == ' ')
            {
                token = strtok(storedString," ");

                for (int i=0; i<2; i++)
                {
                    token = strtok(NULL," ");
                    strcpy(temp,token);
                    temp[strcspn(temp," ")] = 0;
                    coordinates[i] = (float)atof(temp);
                }

                textureVertexTemp = (TextureVertex *)malloc(sizeof(TextureVertex));

                textureVertexTemp->x = coordinates[0];
                textureVertexTemp->y = coordinates[1];

                obj->textures[countTextures] = textureVertexTemp;

                countTextures++;
            }

        }

        obj->numberOfTextures = countTextures;
    }

    // Cerramos la lectura del archivo.
    fclose(file);

}

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

                    size_t numtokens;

                    char *s = strdup(token);
                    size_t tokens_alloc = 1;
                    size_t tokens_used = 0;
                    char **tokens = calloc(tokens_alloc, sizeof(char*));
                    char *token, *rest = s;

                    while ((token = strsep(&rest, "/")) != NULL)
                    {
                        if (tokens_used == tokens_alloc)
                        {
                            tokens_alloc *= 2;
                            tokens = realloc(tokens, tokens_alloc * sizeof(char*));
                        }
                        tokens[tokens_used++] = strdup(token);
                    }

                    if (tokens_used == 0)
                    {
                        free(tokens);
                        tokens = NULL;
                    }
                    else
                    {
                        tokens = realloc(tokens, tokens_used * sizeof(char*));
                    }
                    numtokens = tokens_used;
                    free(s);

                    if(h==0)
                    {
                        faceTemp = (Face *)malloc(sizeof(Face));
                    }

                    faceTemp->vertices[h] = (int)strtol(tokens[0],NULL,10);
                    faceTemp->normales[h] = (int)strtol(tokens[1],NULL,10);
                    faceTemp->texturas[h] = (int)strtol(tokens[2],NULL,10);

                    // Cargamos la nueva cara al array de caras del struct obj
                    obj->faces[countFaces] = faceTemp;

                    free(tokens[0]);
                    free(tokens[1]);
                    free(tokens[2]);
                    free(tokens);

                    h++;
                }

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
    // Cargamos las texturas
    loadTextures(objParam, fileName);
    // Creamos el array de vertices
    createVertexArray(objParam);
    // Creamos el array de normales
    createNormalArray(objParam);
    // Creamos el array de texturas
    createTexturesArray(objParam);
}

void createVertexArray(Obj * objParam)
{
    int vertexArraySize = objParam->numberOfFaces*3*3;
    vertices = (float *) malloc(sizeof(float) * vertexArraySize);

    for (int i = 0; i < objParam->numberOfFaces ; ++i)
    {
        vertices[9*i + 0] = objParam->vertices[objParam->faces[i]->vertices[0] -1 ]->x;
        vertices[9*i + 1] = objParam->vertices[objParam->faces[i]->vertices[0] -1 ]->y;
        vertices[9*i + 2] = objParam->vertices[objParam->faces[i]->vertices[0] -1 ]->z;

        vertices[9*i + 3] = objParam->vertices[objParam->faces[i]->vertices[1] -1 ]->x;
        vertices[9*i + 4] = objParam->vertices[objParam->faces[i]->vertices[1] -1 ]->y;
        vertices[9*i + 5] = objParam->vertices[objParam->faces[i]->vertices[1] -1 ]->z;

        vertices[9*i + 6] = objParam->vertices[objParam->faces[i]->vertices[2] -1 ]->x;
        vertices[9*i + 7] = objParam->vertices[objParam->faces[i]->vertices[2] -1 ]->y;
        vertices[9*i + 8] = objParam->vertices[objParam->faces[i]->vertices[2] -1 ]->z;
    }

}

void createNormalArray(Obj * objParam)
{
    int normalArraySize = objParam->numberOfFaces*3*3;
    normales = (float *) malloc(sizeof(float) * normalArraySize);

    for (int i = 0; i < objParam->numberOfFaces ; ++i)
    {
        normales[9*i + 0] = objParam->normales[objParam->faces[i]->normales[0] -1 ]->x;
        normales[9*i + 1] = objParam->normales[objParam->faces[i]->normales[0] -1 ]->y;
        normales[9*i + 2] = objParam->normales[objParam->faces[i]->normales[0] -1 ]->z;

        normales[9*i + 3] = objParam->normales[objParam->faces[i]->normales[1] -1 ]->x;
        normales[9*i + 4] = objParam->normales[objParam->faces[i]->normales[1] -1 ]->y;
        normales[9*i + 5] = objParam->normales[objParam->faces[i]->normales[1] -1 ]->z;

        normales[9*i + 6] = objParam->normales[objParam->faces[i]->normales[2] -1 ]->x;
        normales[9*i + 7] = objParam->normales[objParam->faces[i]->normales[2] -1 ]->y;
        normales[9*i + 8] = objParam->normales[objParam->faces[i]->normales[2] -1 ]->z;
    }
}

void createTexturesArray(Obj * objParam)
{

    int texturesArraySize = objParam->numberOfFaces*3*2;
    texturas = (float *) malloc(sizeof(float) * texturesArraySize);

    for (int i = 0; i < objParam->numberOfFaces; ++i)
    {

            texturas[(6 * i) + 0] = objParam->textures[objParam->faces[i]->texturas[0] - 1]->x;
            texturas[(6 * i) + 1] = objParam->textures[objParam->faces[i]->texturas[0] - 1]->y;

            texturas[(6 * i) + 2] = objParam->textures[objParam->faces[i]->texturas[1] - 1]->x;
            texturas[(6 * i) + 3] = objParam->textures[objParam->faces[i]->texturas[1] - 1]->y;

            texturas[(6 * i) + 4] = objParam->textures[objParam->faces[i]->texturas[2] - 1]->x;
            texturas[(6 * i) + 5] = objParam->textures[objParam->faces[i]->texturas[2] - 1]->y;

    }
}


void showObj(Obj * obj)
{
    // activate and specify pointer to vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT,0, normales);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, texturas);

    // draw
    glDrawArrays(GL_TRIANGLES, 0, obj->numberOfFaces * 3);

    // deactivate vertex arrays after drawing
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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

    for (int k = 0; k < obj->numberOfTextures; ++k)
    {
        free(obj->textures[k]);
    }

    free(vertices);
    free(normales);
    free(texturas);

    free(obj);
}

