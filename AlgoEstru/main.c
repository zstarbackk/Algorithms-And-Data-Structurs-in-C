#include <stdio.h>
#include <stdlib.h>

#include "../dynamic/stack.h"
#include "../dynamic/queue.h"
#include "pruebas/testing.h"
int main(){
    createTest();
    printf("---------------------------------\n\Stack\n",
           "---------------------------------");
    dynamicStackTest();
    printf("---------------------------------\n\tQueue\n",
           "---------------------------------");
    dynamicQueueTest();
}
void dynamicStackTest(){
    int readyEl, cant = 0;
    t_person person;
    FILE * pf = openFile("people.dat", "rb");
    t_stack pila;
    readyEl = readElement(pf,&person, readBin);
    createStackDS(&pila);
    while(readyEl){
        pushDS(&pila, &person, sizeof(t_person));
        cant++;
        readyEl = readElement(pf, &person, readBin);
    }
    while(popDS(&pila, &person, sizeof(t_person))){
        printf("Persona %i: %d\t%20s %c\n",
               cant, person.id, person.username,person.rol);
        cant--;
    }
    clearStackDS(&pila);
    closeFile(pf);
}
void dynamicQueueTest(){
    int readyEl, cant = 0;
    t_person person;
    FILE * pf = openFile("people.dat", "rb");
    d_queue cola;
    readyEl = readElement(pf,&person, readBin);
    createQueueDQ(&cola);
    while(readyEl){
        enqueueDQ(&cola, &person, sizeof(t_person));
        cant++;
        readyEl = readElement(pf, &person, readBin);
    }
    while(dequeueDQ(&cola, &person, sizeof(t_person))){
        printf("Persona %i: %d\t%20s %c\n",
               cant, person.id, person.username,person.rol);
        cant--;
    }
    queueClearDQ(&cola);
    closeFile(pf);
}
/*void hybridQueueTest(){
    int readyEl, cant = 0;
    t_person person;
    FILE * pf = openFile("people.dat", "rb");
    h_queue cola;
    readyEl = readElement(pf,&person, readBin);
    HQcreateQueue(&cola);
    while(readyEl){
        HQenqueue(&cola, &person, sizeof(t_person));
        cant++;
        readyEl = readElement(pf, &person, readBin);
    }
    while(HQdequeue(&cola, &person, sizeof(t_person))){
        printf("Persona %i: %d\t%s\t%c\n",
               cant, person.id, person.username,person.rol);
        cant--;
    }
    HQqueueClear(&cola);
    closeFile(pf);
}
void staticQueueTest(){
    int readyEl, cant = 0;
    t_person person;
    FILE * pf = openFile("people.dat", "rb");
    t_queue cola;
    readyEl = readElement(pf,&person, readBin);
    SQcreateQueue(&cola);
    while(readyEl){
        SQenqueue(&cola, &person, sizeof(t_person));
        cant++;
        readyEl = readElement(pf, &person, readBin);
    }
    while(SQdequeue(&cola, &person, sizeof(t_person))){
        printf("Persona %i: %d\t%s\t%c\n",
               cant, person.id, person.username,person.rol);
        cant--;
    }
    SQqueueClear(&cola);
    closeFile(pf);
}
void RedimensionableStack()
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
}*/
