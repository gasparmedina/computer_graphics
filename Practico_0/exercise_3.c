#include <stdio.h>
#include <stdlib.h>
#include "util/arrayUtil.h"

void exercise3(){

 int vec[100];

 for (int i = 0; i < 100; i++) {
    vec[i] = rand();
 }

 printArray(100, vec);

 printf("\n");
 printf("\n");

}
