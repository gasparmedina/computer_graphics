#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void exercise7()
{

    Vec3 myVec1;
    Vec3 myVec2;
    vec3Init(&myVec1, 1, 0, 0);
    vec3Init(&myVec2, 4, 0, 0);

    int result = vec3Add(myVec1, myVec2);
    printf("Resultado ejercicio 7 = %d \n\n", result);

}
