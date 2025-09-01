#ifndef HYBRIDQUEUE_H_INCLUDED
#define HYBRIDQUEUE_H_INCLUDED
#define CANT 30
#define MIN(a,b) ((a)<(b)?(a):(b))
#include <stdlib.h>
typedef struct{
    char * data;
    unsigned tam;
}t_element;
typedef struct{
    t_element cola[CANT];
    unsigned available;
    unsigned start;
    unsigned end;
}h_queue;

void HQcreateQueue(h_queue * pQueue);
void HQqueueClear(h_queue * pQueue);
int HQisEmpty(const h_queue * pQueue);
int HQisFull(const h_queue * pQueue, unsigned sizeEl);
int HQenqueue(h_queue * pQueue, void * el, unsigned sizeEl);
int HQdequeue(h_queue * pQueue, void * el, unsigned sizeEl);
int HQpeek(h_queue * pQueue, void *el , unsigned sizeEl);

#endif // HYBRIDQUEUE_H_INCLUDED
