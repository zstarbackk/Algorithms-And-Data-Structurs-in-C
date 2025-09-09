#include "queue.h"
void createQueueDQ(d_queue * p){
    p->first = NULL;
    p->last = NULL;
}
void queueClearDQ(d_queue * p){
    qNode *aux;
    while(p->first!=NULL){
        aux = p->first;
        p->first = aux->next;
        free(aux->data);
        free(aux);
    }
    p->last =NULL;
}
int isEmptyDQ(const d_queue * p){
    return p->first ==NULL;
}
int isFullDQ(const d_queue * p, unsigned sizeEl){
    qNode * aux = (qNode*)malloc(sizeof(qNode));
    void *data = malloc(sizeEl);
    free(aux);
    free(data);
    return aux ==NULL || data ==NULL;
}
int enqueueDQ(d_queue * p, void * el, unsigned sizeEl){
    qNode * newOne =(qNode*)malloc(sizeof(qNode));
    if(newOne==NULL|| (newOne->data = malloc(sizeEl))==NULL){
        free(newOne);
        return 0;
    }
    memcpy(newOne->data,el, sizeEl);
    newOne->next = NULL;
    newOne->dataSize = sizeEl;
    if(p->last!=NULL)
        p->last->next=newOne;
    else
        p->first=newOne;
    p->last = newOne;
    return 1;
}
int dequeueDQ(d_queue * p, void * el, unsigned sizeEl){
    qNode * aux = p->first;
    if(aux==NULL)
        return 0;
    p->first = aux->next;
    memcpy(el, aux->data, MIN(sizeEl,aux->dataSize));
    free(aux->data);
    free(aux);
    return 1;
}
int peekDQ(d_queue * p, void *el , unsigned sizeEl){
    qNode * aux = p->first;
    if(aux ==NULL)
        return 0;
    memcpy(el, aux->data,MIN(sizeEl,aux->dataSize));
    return 1;
}
