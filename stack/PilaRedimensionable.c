#include "PilaRedimensionable.h"
void createStackR(t_stack * pStack){
    pStack->stack = NULL;
    pStack->top = 0;
    pStack->tam = 0;
}
///Adds an element to the top of the Stack
int pushR(t_stack * pStack, const void * el, unsigned int elSize){
    unsigned int auxTop = pStack->top;
    if(pStack->tam<auxTop+sizeof(unsigned int)+elSize){
        if(resize(pStack))
            return -1;
    }
    memcpy(pStack->stack+auxTop, el, elSize);
    auxTop+=elSize;
    memcpy(pStack->stack+auxTop, &elSize, sizeof(unsigned int));
    pStack->top = auxTop+sizeof(unsigned int);
    return 0;
}
///Peek the top element without removing it
int peekR(t_stack * pStack, void * el, unsigned int elSize){
    if(pStack->top == 0)
        return 0;
    unsigned int auxTop = pStack->top;
    unsigned int stackElSize, auxSize;
    auxTop-=sizeof(unsigned int);
    memcpy(&stackElSize, pStack->stack+auxTop,sizeof(unsigned int));
    auxSize = MIN(elSize, stackElSize);
    memcpy(el, pStack->stack+auxSize, auxSize);
    return 1;
}
///
int popR(t_stack * pStack, void * el, unsigned int elSize){
    if(pStack->top==0)
        return 0;
    unsigned int auxTop = pStack->top;
    unsigned int stackElSize, auxSize;
    auxTop-=sizeof(unsigned int);
    memcpy(&stackElSize, pStack->stack+auxTop,sizeof(unsigned int));
    auxSize = MIN(elSize, stackElSize);
    memcpy(el, pStack->stack+auxTop-auxSize, auxSize);
    pStack->top =auxTop-auxSize;
    return 1;
}
///
int isEmptyR(t_stack * pStack){
    return (pStack->top==0?1:0);
}

int eliminateStackR(t_stack * pStack){
    free(pStack->stack);
    pStack->stack= 0;
    pStack->tam= 0;
    pStack->top = 0;
}

int resize(t_stack *pStack) {
    unsigned int tamAdd = (unsigned int)(pStack->tam * 0.5);
    void *tmp;
    if(pStack->stack == NULL){
        pStack->stack=malloc(100);
        if(pStack->stack==NULL)
            return -1;
        tamAdd = 100;
    }
    else{
        tmp = realloc(pStack->stack, pStack->tam + tamAdd);
        if (tmp == 0)
            return -1; // fallo al redimensionar
        pStack->stack = tmp;
    }
    pStack->tam += tamAdd;

    return 0;
}
