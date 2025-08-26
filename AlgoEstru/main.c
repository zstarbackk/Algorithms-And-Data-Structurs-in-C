#include <stdio.h>
#include <stdlib.h>
#include "../stack/PilaRedimensionable.h"
#include "pruebas/testing.h"
int main()
{
    int readyEl, cant = 0;
    t_person person;
    FILE * pf = openFile("people.dat", "rb");
    t_stack pila;
    readyEl = readElement(pf,&person, readBin);
    createStackR(&pila);
    while(readyEl){
        pushR(&pila, &person, sizeof(t_person));
        cant++;
        readyEl = readElement(pf, &person, readBin);
    }
    while(popR(&pila, &person, sizeof(t_person))){
        printf("Persona %i: %d\t%s\t%c\n",
               cant, person.id, person.username,person.rol);
        cant--;
    }
    eliminateStackR(&pila);
    closeFile(pf);
}
