#ifndef PILAHIBRIDA_H_INCLUDED
#define PILAHIBRIDA_H_INCLUDED
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef struct{
    char * stack;
    unsigned int top;
    unsigned int tam;
}t_stack;
int createStackH(t_stack * pStack, unsigned int tam);
///Adds an element to the top of the Stack
int pushH(t_stack * pStack, const void * el, unsigned int elSize);
///Peek the top element without removing it
int peekH(t_stack * pStack, void * el, unsigned int elSize);
///
int popH(t_stack * pStack, void * el, unsigned int elSize);
///
int isEmptyH(t_stack * pStack);
int isFullH(t_stack * pStack, unsigned int elSize);

int eliminateStackH(t_stack * pStack);


#endif // PILAHIBRIDA_H_INCLUDED
