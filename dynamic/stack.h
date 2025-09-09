#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) a<b?a:b

typedef struct sNode{
    void *data;
    unsigned dataSize;
    struct sNodo *next;
} tNode;
typedef tNode * t_stack;

void createStackDS(t_stack *p);
int isFullDS(const t_stack * p, unsigned elSize);
int isEmptyDS(t_stack * p);
int pushDS(t_stack * p, const void * el, unsigned elSize);
int peekDS(t_stack * p, void * el, unsigned elSize);
int popDS(t_stack * p, void *el, unsigned elSize);
void clearStackDS(t_stack *p);
#endif // STACK_H_INCLUDED
