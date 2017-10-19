#include <stdio.h>
#include <stdlib.h>

void printArray(int arraySize, int *vec) {
  for (int i = 0; i < arraySize ; i++) {
    if (i != arraySize -1) {
      printf("%d - ", vec[i]);
    } else {
      printf("%d", vec[i]);
    }
  }
}
