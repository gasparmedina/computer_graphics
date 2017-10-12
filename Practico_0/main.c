#include <stdio.h>
#include <stdlib.h>
#include "exercise_1.h"
#include "exercise_2.h"
#include "exercise_3.h"
#include "exercise_4.h"
#include "exercise_5.h"
#include "exercise_6.h"
#include "exercise_7.h"
#include "exercise_8.h"
#include "exercise_9.h"
#include "exercise_10.h"
#include "exercise_11.h"
#include "exercise_12.h"
#include "exercise_13.h"
#include "exercise_14.h"
#include "exercise_15.h"
#include "exercise_16.h"
#include "utilh/arrayUtil.h"

int main(){

    /*
    Desarrollar un programa C que imprime en la Terminal el largo en bytes de los siguientes tipos de
    datos: char, int, long, long long, float, double, long double, char*, int*, float*, void*. Sugerencia:
    utilizar el operador sizeof.
    */
    exercise1();

    /*
    Desarrollar un programa C que crea un array de 100 elementos, almacena en cada posición su
    ı́ndice correspondiente y lo imprime en la Terminal.
    */
    exercise2();

    /*
    Desarrollar un programa C que crea un array de 100 elementos, lo llena con números aleatorios
    y lo imprime en la Terminal.
    */
    exercise3();

    /*
    Desarrollar un programa C que crea un array de 100 elementos, lo llena con números aleatorios
    en el intervalo [0, 1] y lo imprime en la Terminal.
    */
    exercise4();

    /*
    Desarrollar el mismo programa del problema anterior, recibiendo la cantidad de elementos como
    entrada del usuario.
    */
    exercise5();


    /*
    Desarrollar el mismo programa del problema anterior, esta vez imprimiendo los números gen-
    erados en un archivo utilizando el siguiente formato: [n 0 , n 1 , ..., n n ], donde n i es el número
    almacenado en la posición i del array.
    */
    exercise6();

    /*
    Desarrollar un nuevo tipo de dato “Vec3” como una estructura (struct) e implementar una
    función add que recibe dos variables de tipo “Vec3” y devuelve su suma.
    */
    exercise7();

    /*
    Desarrollar un nuevo tipo de dato “Vec3” como una estructura (struct) e implementar una
    función addp que recibe tres punteros variables de tipo “Vec3” y devuelve la suma de los primeros
    dos elementos almacenado en el tercero.
    */
    exercise8();

    /*
    Mover la declaración del tipo de dato “Vec3” y las funciones add y addp a su propio archivo y
    referenciarlo desde main.
    */
    exercise9();


    /*
    Desarrollar un programa C que crea un array de 100 “Vec3” donde los 3 componentes (x, y, z)
    de cada elemento son un número aleatorio en el intervalo [0, 1].
    */
    exercise10();

    /*
    Desarrollar el mismo programa del problema anterior, recibiendo la cantidad de elementos y el
    intervalo de generación de números aleatorios como entrada del usuario. Sugerencia: pensar en
    términos de una homotecia del intervalo [0, 1] a [a, b].
    */
    exercise11();

    /*
    Desarrollar el mismo programa del problema anterior, organizando los elementos en una estru-
    cura lógica bidimensional (una “matriz de Vec3”). El usuario proporcionará las dimensiones de
    la misma como entrada.
    */
    exercise12();


    /*
    Implementar la lógica necesaria para representar una Matriz de N XM floats con la siguiente interfaz y funciones:
        (a) Matrix* matrix new(int n, int m) - Crea una matriz de dimensiones N XM
        (b) Matrix* matrix identity(int n, int m) - Crea una matriz de dimensiones N XM inicializada
            en la Identidad.
        (c) float matrix get elem(Matrix* m, int r, int c) - Devuelve el elemento almacenado en m[r, c]
            si y solo si r y c son indices válidos dentro de m.
        (d) void matrix set elem(Matrix* m, int r, int c, float val) - Asigna m[r, c] = val si y solo si r
            y c son indices válidos dentro de m.
        (e) void matrix mult(Matrix* a, Matrix* b, Matrix* c) - Asigna c = aXb.
        (f) void matrix free(Matrix* m) - Elimina una matriz, liberando sus recursos.
    */
    exercise13();

    /*
    Dada la siguiente estructura que declara un Stack Frame, implementar un TDA Pila con al
    menos las operaciones propuestas a continuación.

    struct StackFrameStruct
    {
        void* data;
        struct StackFrameStruct* prev;
    } ;
    typedef struct StackFrameStruct StackFrame;

    Operaciones:
    (a) Stack* stack new() - Crea una nueva pila vacı́a.
    (b) int stack empty(Stack* s) - Devuelve 1 si la pila se encuentra vacı́a, 0 en otro caso.
    (c) void stack push(Stack* s, void* data) - Agrega un nuevo elemento como tope de la pila.
    (d) void* stack pop(Stack* s) - Remueve el tope de la pila, devolviendo los datos contenidos en
        él. Si la pila se encontraba vacı́a, devuelve NULL.
    (e) void stack free(Stack* s) - Elimina la pila, liberando todos sus recursos excepto los datos
        almacenados.

    Desarrollar un programa que instancia una pila, almacena distintos tipos de datos y luego libera
    sus recursos.
    */
    exercise14();

    /*
    Dada la siguiente estructura que declara un “Bloque”, implementar un TDA Lista Encadenada
    con al menos las operaciones propuestas a continuación.
    struct BlockStruct
    {
        void* data,
        struct BlockStruct* next;
    };

    typedef struct BlockStruct Block;

    Operaciones:
    (a) List* list new() - Crea una nueva lista vacı́a.
    (b) int list empty(List* l) - Devuelve 1 si la lista se encuentra vacı́a, 0 en otro caso.
    (c) unsigned int list size(List* l) - Devuelve el largo de la lista l.
    (d) void list add(List* l, Block* b) - Agrega el bloque b como último elemento de la lista l.
    (e) void list insert(List* l, int indx, Block* b) - Inserta el bloque b en la posición indx de la
        lista l si y solo si 0 ≤ indx ≤ n, donde n es el largo de la lista l.
    (f) int list find(List* l, Block* b) - Devuelve la posición en la lista del bloque b o -1 si el bloque
        no se encuentra presente.
    (g) Block* list remove(List* l, int indx) - Remueve el elemento en la posición indx de la lista
        l. Devuelve el bloque que se encontraba en dicha posición o NULL si indx ≥ n, donde n es
        el largo de la lista.
    (h) void list free(List* l) - Elimina la lista, liberando sus recursos, pero no los de sus bloques.

    Desarrollar un programa que instancia una lista, almacena distintos tipos de datos y luego libera
    sus recursos.
    */
    exercise15();

    /*
    Dada la siguiente estructura que declara un vector y lo asocia con su tamaño, implementar un
    tipo de dato “Vector redimensionable” de memoria consecutiva que tiene una capacidad inicial
    variable y se redimensiona automaticamente conforme se agregan nuevos elementos a él.

    struct VectorStruct
    {
        unsigned int size;
        unsigned int capacity;
        float* elems;
    };

    typedef VectorStruct Vector;

    Operaciones:

    (a) Vector* vector new(unsigned int cap) - Crea un nuevo vector de capacidad inicial indicada.
    (b) void vector add(Vector* v, float val) - Agrega un elemento al final del vector, incrementando
        su tamaño. Si el tamaño excede la capacidad, se deberá adquirir más memoria.
    (c) float vector get at(Vector* v, unsigned int i) - Obtiene el elemento en la posición i del
        vector.
    (d) float vector set at(Vector* v, unsigned int i, float val) - Asigna el elemento en la posición i
        del vector con el valor denotado por val.
    (e) void vector free(Vector* v) - Elimina el vector, liberando sus recursos.

    */
    exercise16();

}
