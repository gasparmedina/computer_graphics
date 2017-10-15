#include <stdio.h>
#include <stdlib.h>
#include "utilh/arrayUtil.h"
#include "utilh/fileUtil.h"

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
