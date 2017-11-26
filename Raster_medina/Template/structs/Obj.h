#ifndef OBJ_INCLUDED
#define OBJ_INCLUDED

typedef struct
{
    float x,y,z;
} Vertex;

typedef struct
{
    int numsides;
    int vert[4];
} Face;

typedef struct
{
    int numberOfFaces;
    int numberOfVerts;
    int numberOfVertsNormal;
    Face *faces[10000];
    Vertex *vertices[10000];
    Vertex *normales[10000];
} Obj;

void loadObj(char* fileName, Obj *objParam);

void showObj(Obj * obj);

void freeMemoryObj(Obj * obj);

#endif // OBJ_INCLUDED
