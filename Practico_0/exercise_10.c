#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void exercise10(){

 Vec3 vec[100];

 for (int i = 0; i < 100; i++) {
    vec[i] = vec3RandomInit();
 }

 printf("Resultado ejercicio 10 \n");

 printVec3Array(100, vec);

 printf("\n");
 printf("\n");


}
