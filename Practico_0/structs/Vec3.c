#include <stdio.h>
#include <stdlib.h>
#include "Vec3.h"

void vec3Init(Vec3 *vecParam, int x, int y, int z) {

    vecParam->x = x;
    vecParam->y = y;
    vecParam->z = z;

}

void vec3Addp(Vec3 *vec1,Vec3 *vec2,Vec3 *vec3) {

   (*vec3).x = (*vec1).x + (*vec2).x;
   (*vec3).y = (*vec1).y + (*vec2).y;
   (*vec3).z = (*vec1).z + (*vec2).z;

}

void vec3Print(Vec3 *vec){

    printf("x->%d y->%d z->%d \n", (*vec).x, (*vec).y, (*vec).z);

}

int vec3Add(Vec3 vec1, Vec3 vec2){

    return vec1.x + vec2.x;

}

Vec3 vec3RandomInit(){

   Vec3 result;

   srand(time(NULL));

   result.x = rand() % 2;
   result.y = rand() % 2;
   result.z = rand() % 2;

   return result;

}

void printVec3Array(int arraySize, Vec3 *myVec){
    for (int i = 0; i < arraySize ; i++) {
        vec3Print(&myVec[i]);
    }
}



