#include <stdio.h>
#include <stdlib.h>
#include "stack/PilaRedimensionable.h"
int main()
{
    t_stack pila;
    int vec[]={1,2,3,4};
    int numero;
    createStackR(&pila);
    pushR(&pila, &vec[0], sizeof(int));
    popR(&pila, &numero, sizeof(int));
    printf("Numero: %d \n", numero);
    eliminateStackR(&pila);
    printf("pstack->stack:%p\npstack->top:%u\npstack->tam:%u", pila.stack,pila.top, pila.tam);
}
