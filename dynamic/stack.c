#include "stack.h"
void createStackDS(t_stack *p){
    *p =NULL;
}
int isFullDS(const t_stack * p, unsigned elSize){
    tNode * aux = (tNode*)malloc(sizeof(tNode));
    void * info = malloc(elSize);
    free(aux);
    free(info);
    return (aux == NULL || info ==NULL);
}
int isEmptyDS(t_stack * p){
    return *p==NULL;
}
int pushDS(t_stack * p, const void * el, unsigned elSize){
    tNode * aux;
    if((aux = malloc(sizeof(tNode)))== NULL ||
    (aux->data= malloc(elSize))==NULL){
        free(aux->data);
        free(aux);
        return 0;
    }
    memcpy(aux->data, el, elSize);
    aux->dataSize =elSize;
    aux->next = *p;
    *p = aux;
    return 1;
}
int peekDS(t_stack * p, void * el, unsigned elSize){
    if(*p == NULL)
        return 0;
    memcpy(el, (*p)->data, MIN(elSize, (*p)->dataSize));
    return 1;
}
int popDS(t_stack * p, void *el, unsigned elSize){
    tNode *aux = *p;
    if(*p == NULL)
        return 0;
    *p = aux->next;
    memcpy(el, aux->data, MIN(aux->dataSize,elSize));
    free(aux->data);
    free(aux);
    return 1;
}
void clearStackDS(t_stack *p){
    tNode * aux;
    while(*p != NULL){
        aux = *p;
        *p= aux->next;
        free(aux->data);
        free(aux);
    }
}
