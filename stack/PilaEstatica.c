#include "PilaEstatica.h"
void createStack(t_stack * pStack){
    pStack->top = STACK_SIZE;
}
int push(t_stack * pStack, const void * el, unsigned int elSize){
    int auxTop;
    if(pStack->top<elSize+INDEX_SIZE)
        return FULL_STACK;
    auxTop = pStack->top-elSize;
    memcpy(pStack->stack+auxTop,el,elSize);

    auxTop-=INDEX_SIZE;
    memcpy(pStack->stack+auxTop,&elSize, INDEX_SIZE);

    pStack->top=auxTop;
    return 0;
}
int peek(t_stack * pStack, void * el, unsigned int elSize){
    unsigned int stackElSize;
    if(pStack->top== STACK_SIZE)
        return EMPTY_STACK;
    memcpy(&stackElSize,pStack->stack+pStack->top,INDEX_SIZE);
    memcpy(el, pStack->stack+pStack->top+INDEX_SIZE, MIN(stackElSize, elSize));
    return 0;
}
int pop(t_stack * pStack, void * el, unsigned int elSize){
    unsigned int stackElSize;
    if(pStack->top== STACK_SIZE)
        return EMPTY_STACK;
    memcpy(&stackElSize,pStack->stack+pStack->top,INDEX_SIZE);
    memcpy(el, pStack->stack+pStack->top+INDEX_SIZE, MIN(stackElSize, elSize));
    pStack->top+=MIN(stackElSize,elSize)+INDEX_SIZE;
    return 0;
}

int isEmpty(t_stack * pStack){
    return (pStack->top==STACK_SIZE?1:0);
}
int isFull(t_stack * pStack, unsigned int elSize){
    return (pStack->top<elSize+INDEX_SIZE?1:0);
}
