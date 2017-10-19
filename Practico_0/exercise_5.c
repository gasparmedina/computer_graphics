#include <stdio.h>
#include <stdlib.h>
#include "util/arrayUtil.h"

void exercise5(){

 int input;
 printf("Ingrese un valor numerico mayor que cero: ");
 scanf("%i", &input);

 int vec[input];

 srand(time(NULL));

 for (int i = 0; i < input; i++) {
    vec[i] = rand() % 2;
 }

 printArray(input, vec);

 printf("\n");
 printf("\n");

}
