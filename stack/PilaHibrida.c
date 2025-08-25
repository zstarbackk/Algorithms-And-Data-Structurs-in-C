#include "PilaHibrida.h"
int createStackH(t_stack * pStack, unsigned int tam){
    pStack->stack=malloc(tam);
    if(pStack->stack==0)
        return -1;
    pStack->tam = tam;
    pStack->top = tam;
    return 0;
}
///Adds an element to the top of the Stack
int pushH(t_stack * pStack, const void * el, unsigned int elSize){
    unsigned int index = pStack->top;
    if(pStack->top < elSize+sizeof(unsigned int))
        return -1;
    index -= elSize;
    memcpy(pStack->stack+index, el, elSize);
    index -=sizeof(unsigned int);
    memcpy(pStack->stack+index,&elSize, sizeof(unsigned int));
    pStack->top = index;
    return 0;
}
///Peek the top element without removing it
int peekH(t_stack * pStack, void * el, unsigned int elSize){
    unsigned int auxIndex, stackElSize;
    if(pStack->top==pStack->tam)
        return -1;
    auxIndex = pStack->top;
    memcpy(&stackElSize,pStack->stack+auxIndex,sizeof(unsigned int));
    auxIndex +=sizeof(unsigned int);
    memcpy(el, pStack->stack+auxIndex, MIN(stackElSize,elSize));
    return 0;
}
///
int popH(t_stack * pStack, void * el, unsigned int elSize){
    unsigned int auxIndex, stackElSize;
    if(pStack->top==pStack->tam)
        return -1;
    auxIndex = pStack->top;
    memcpy(&stackElSize,pStack->stack+auxIndex,sizeof(unsigned int));
    auxIndex +=sizeof(unsigned int);
    memcpy(el, pStack->stack+auxIndex, MIN(stackElSize,elSize));
    pStack->top = auxIndex+MIN(stackElSize,elSize);
    return 0;
}
///
int isEmptyH(t_stack * pStack){
    return (pStack->top==pStack->tam?1:0);
}
int isFullH(t_stack * pStack, unsigned int elSize){
    return (pStack->top<elSize+sizeof(unsigned int)?1:0);
}

int eliminateStackH(t_stack * pStack){
    if (!pStack->stack)
        return -1;
    free(pStack->stack);
    pStack->stack = 0;
    pStack->tam = 0;
    pStack->top = 0;
    return 0;
}
