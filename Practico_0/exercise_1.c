#include <stdio.h>
#include <stdlib.h>

void exercise1()
{

    printf("Cantidad de bytes para un char : %d \n", sizeof(char));
    printf("Cantidad de bytes para un int : %d \n", sizeof(int));
    printf("Cantidad de bytes para un long : %d \n", sizeof(long));
    printf("Cantidad de bytes para un int16 : %d \n", sizeof(int16_t));
    printf("Cantidad de bytes para un int32 : %d \n", sizeof(int32_t));
    printf("Cantidad de bytes para un int64 o long-long : %d \n", sizeof(int64_t));
    printf("Cantidad de bytes para un float : %d \n", sizeof(float));
    printf("Cantidad de bytes para un double : %d \n", sizeof(double));
    printf("Cantidad de bytes para un long-double : %d \n", sizeof(long double));
    printf("Cantidad de bytes para un char* : %d \n", sizeof(char*));
    printf("Cantidad de bytes para un int* : %d \n", sizeof(int*));
    printf("Cantidad de bytes para un float* : %d \n", sizeof(float*));
    printf("Cantidad de bytes para un void* : %d \n", sizeof(void*));

    printf("\n");

}
