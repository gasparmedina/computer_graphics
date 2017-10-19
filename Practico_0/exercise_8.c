#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void exercise8(){

    struct Vec3 myVec1;
    struct Vec3 myVec2;
    struct Vec3 myVec3;

    initVec3(&myVec1, 1, 2, 3);
    initVec3(&myVec2, 4, 2, 3);
    initVec3(&myVec3, 4, 2, 5);

    addpVec3(&miVec1, &miVec2, &miVec3);
    printf("Resultado ejercicio 8 = %d", miVec3.value);
    printf("\n");

}

