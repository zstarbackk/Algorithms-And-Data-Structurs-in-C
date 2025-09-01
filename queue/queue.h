#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX_SIZE 400
#define MIN(a,b) ((a)<(b)?(a):(b))
#include <string.h>
typedef struct{
    char queue[MAX_SIZE];
    unsigned start;
    unsigned end;
    unsigned available;
}t_queue;
void SQcreateQueue(t_queue * pQueue);
void SQqueueClear(t_queue * pQueue);
int SQisEmpty(const t_queue * pQueue);
int SQisFull(const t_queue * pQueue, unsigned sizeEl);
int SQenqueue(t_queue * pQueue, void * el, unsigned sizeEl);
int SQdequeue(t_queue * pQueue, void * el, unsigned sizeEl);
int SQpeek(t_queue * pQueue, void *el , unsigned sizeEl);
#endif // QUEUE_H_INCLUDED
