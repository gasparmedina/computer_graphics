#ifndef VEC3_INCLUDED
#define VEC3_INCLUDED

typedef struct {

 int x;
 int y;
 int z;

}Vec3;


void vec3Init(Vec3 *vecParam, int x, int y, int z);

void vec3Addp(Vec3 *vec1, Vec3 *vec2, Vec3 *vec3);

void vec3Print(Vec3 *vec);

int vec3Add(Vec3 vec1, Vec3 vec2);

#endif // VEC3_INCLUDED
