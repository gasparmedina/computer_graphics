#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void exercise8()
{

    Vec3 myVec1;
    Vec3 myVec2;
    Vec3 myVec3;

    vec3Init(&myVec1, 1, 2, 3);
    vec3Init(&myVec2, 4, 2, 3);

    vec3Addp(&myVec1, &myVec2, &myVec3);

    printf("Resultado ejercicio 8 \n");

    vec3Print(&myVec3);

    printf("\n");
    printf("\n");

}

