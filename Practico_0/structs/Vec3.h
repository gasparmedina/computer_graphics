#ifndef VEC3_INCLUDED
#define VEC3_INCLUDED

typedef struct
{

    int x;
    int y;
    int z;

} Vec3;

/*
Inicializa una estructura de datos Vec3 con los elementos pasados por parametro
*/
void vec3Init(Vec3 *vecParam, int x, int y, int z);

/*
Iniciliza una estructura de datos Vec3 con valores random entre 0 y 1
*/
Vec3 vec3RandomInit();

/*
Suma los elementos x, y, z de la estructura de datos Vec3 de los parametros
vec2 y vec1 y el resultado es cargado por referencia en el parametro vec3
*/
void vec3Addp(Vec3 *vec1, Vec3 *vec2, Vec3 *vec3);

/*
Imprime por pantalla la estructura de datos Vec3
*/
void vec3Print(Vec3 *vec);

/*
Suma los elementos x de la estructura de datos Vec3 de los parametros vec1 y vec2 y devuelve
el resultado como un tipo de dato int
*/
int vec3Add(Vec3 vec1, Vec3 vec2);

/*
Imprime un array con estructuras de tipo Vec3
*/
void printVec3Array(int arraySize, Vec3 *myVec);

/*
Genera una estructura de datos de tipo Vec3, en la cual cada elemento x,y,z de la
estructura es asignado un valor entre minInterval y maxInterval
*/
Vec3 vec3RandomCustomInterval(int minInterval, int maxInterval);

#endif // VEC3_INCLUDED
