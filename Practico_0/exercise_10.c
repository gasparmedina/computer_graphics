#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void exercise10(){

 Vec3 vec[2];

 for (int i = 0; i < 2; i++) {
    Vec3 myVec;
    vec[i] = vec3RandomInit(&myVec);
 }

 printf("Resultado ejercicio 10 \n");

 printVec3Array(2, vec);

 printf("\n");
 printf("\n");


}
