#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED
#include <string.h>
#define STACK_SIZE 200
#define INDEX_SIZE sizeof(unsigned int) ///Size of 'unsigned int'
#define FULL_STACK -1
#define EMPTY_STACK -2
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef struct{
    char stack[STACK_SIZE];
    unsigned int top;
}t_stack;
///Initialize the 'top' var
void createStack(t_stack * pStack);
///Adds an element to the top of the Stack
int push(t_stack * pStack, const void * el, unsigned int elSize);
///Peek the top element without removing it
int peek(t_stack * pStack, void * el, unsigned int elSize);
///
int pop(t_stack * pStack, void * el, unsigned int elSize);
///
int isEmpty(t_stack * pStack);
int isFull(t_stack * pStack, unsigned int elSize);



#endif // PILAESTATICA_H_INCLUDED
