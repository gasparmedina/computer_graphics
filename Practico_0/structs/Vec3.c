#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void initVec3 (Vec3 *vecParam, int x, int y, int z) {

    vecParam->x = x
    vecParam->y = y
    vecParam->z = z

}

void addpVec3(struct Vec3 *vec1, struct Vec3 *vec2, struct Vec3 *vec3) {

   (*vec3).x = (*vec1).x + (*vec2).x;
   (*vec3).y = (*vec1).y + (*vec2).y;
   (*vec3).z = (*vec1).z + (*vec2).z;

}

void printVec3(struct Vec3 *vec){

}

