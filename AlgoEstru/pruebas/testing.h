#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define ARCH_TXT "people.txt"
#define ARCH_BIN "people.dat"
typedef struct{
    int id;
    char username[20];
    char rol;
}t_person;
int createTxtPrueba();
int createBinPrueba();
FILE * openFile(const char * fileName, const char * openMethod);
int closeFile(FILE * pf);
int readElement(FILE * pf, void *el,int (*read)(FILE *pf, void  * el));
int readBin(FILE *pf, void *el);
#endif // TESTING_H_INCLUDED
