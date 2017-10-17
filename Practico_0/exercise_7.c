#include <stdio.h>
#include <stdlib.h>

struct Vec3 {

 int a;

};

void exercise7(){

    struct Vec3 miVec1;
    struct Vec3 miVec2;
    miVec1.a = 2;
    miVec2.a = 2;

    int result = add(miVec1, miVec2);
    printf("Resultado ejercicio 7 = %d", result);
    printf("\n");

}

int add (struct Vec3 vec1, struct Vec3 vec2){

    return vec1.a + vec2.a;

}
