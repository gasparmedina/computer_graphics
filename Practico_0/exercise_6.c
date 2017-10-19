#include <stdio.h>
#include <stdlib.h>
#include "util/arrayUtil.h"
#include "util/fileUtil.h"

void exercise6(){

 int input;
 printf("Ingrese un valor numerico mayor que cero: ");
 scanf("%i", &input);

 int vec[input];

 srand(time(NULL));

 for (int i = 0; i < input; i++) {
    vec[i] = rand() % 2;
 }

 writeFile("archivoSalidaEjercicio_6.txt",vec, input);

 printf("\n");
 printf("\n");


}
