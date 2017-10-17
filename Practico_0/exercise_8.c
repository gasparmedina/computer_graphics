#include <stdio.h>
#include <stdlib.h>

struct Vec3 {

 int value;

};

void exercise8(){

    struct Vec3 miVec1;
    struct Vec3 miVec2;
    miVec1.value = 2;
    miVec2.value = 8;
    struct Vec3 miVec3;

    addp(&miVec1, &miVec2, &miVec3);
    printf("Resultado ejercicio 8 = %d", miVec3.value);
    printf("\n");

}


void addp(struct Vec3 *vec1, struct Vec3 *vec2, struct Vec3 *vec3) {
   (*vec3).value = (*vec1).value + (*vec2).value;
}
