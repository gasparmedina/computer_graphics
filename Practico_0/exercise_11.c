#include <stdio.h>
#include <stdlib.h>
#include "structs/Vec3.h"

void exercise11(){

 printf("Resultado ejercicio 11 \n\n");

 int input;
 printf("Ingrese cantidad de elementos: ");
 scanf("%i", &input);

 Vec3 vec[input];

 printf("Ingrese el intervalo de generacion aleatoria \n");

 printf("Ingrese el limite inferior del intervalo: \n");

 int lowerLimitInterval;
 scanf("%i", &lowerLimitInterval);

 printf("Ingrese el limite superior del intervalo: \n");

 int upperLimitInterval;
 scanf("%i", &upperLimitInterval);

 for(int i = 0; i <= input; i++) {
    vec[i] = vec3RandomCustomInterval(lowerLimitInterval, upperLimitInterval);
 }

 printVec3Array(input, vec);

 printf("\n");
 printf("\n");

}
