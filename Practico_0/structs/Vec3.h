#ifndef VEC3_INCLUDED
#define VEC3_INCLUDED

struct Vec3 {

 int x;
 int y;
 int z;

};


void initVec3(Vec3 *vecParam, int x, int y, int z);

void addpVec3(struct Vec3 *vec1, struct Vec3 *vec2, struct Vec3 *vec3);

void printVec3(struct Vec3 *vec);

#endif // VEC3_INCLUDED
