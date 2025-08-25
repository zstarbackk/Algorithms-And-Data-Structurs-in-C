#ifndef PILAREDIMENSIONABLE_H_INCLUDED
#define PILAREDIMENSIONABLE_H_INCLUDED
#define MIN(a,b) ((a)<(b)?(a):(b))
#include <stdlib.h>
typedef struct{
    char * stack;
    unsigned int top;
    unsigned int tam;
}t_stack;
int createStackR(t_stack * pStack);
///Adds an element to the top of the Stack
int pushR(t_stack * pStack, const void * el, unsigned int elSize);
///Peek the top element without removing it
int peekR(t_stack * pStack, void * el, unsigned int elSize);
///
int popR(t_stack * pStack, void * el, unsigned int elSize);
///
int isEmptyR(t_stack * pStack);

int eliminateStackR(t_stack * pStack);
int resize(t_stack *pStack);



#endif // PILAREDIMENSIONABLE_H_INCLUDED
