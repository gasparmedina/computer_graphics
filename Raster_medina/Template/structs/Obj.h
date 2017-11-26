#ifndef OBJ_INCLUDED
#define OBJ_INCLUDED

typedef struct
{
    float x,y,z;
} Vertex;

typedef struct
{
    float x,y;
} TextureVertex;

typedef struct
{
    int numsides;
    int vert[4];
} Face;

typedef struct
{
    int vertices[3];
    int normales[3];
    int texturas[3];
} Face2;

typedef struct
{
    int numberOfFaces;
    int numberOfVerts;
    int numberOfVertsNormal;
    int numberOfTextures;
    Face2 *faces[1000];
    Vertex *vertices[1000];
    Vertex *normales[1000];
    TextureVertex *textures[1000];
} Obj;

void loadObj(char* fileName, Obj *objParam);

void showObj(Obj * obj);

void freeMemoryObj(Obj * obj);

#endif // OBJ_INCLUDED
