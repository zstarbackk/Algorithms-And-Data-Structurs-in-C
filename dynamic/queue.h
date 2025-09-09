#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdlib.h>
#include <string.h>
#define MIN(a,b) a<b?a:b
typedef struct {
    void *data;
    unsigned dataSize;
    struct qNode *next;
}qNode;

typedef struct{
    qNode *first,
          *last;
}d_queue;

void createQueueDQ(d_queue * p);
void queueClearDQ(d_queue * p);
int isEmptyDQ(const d_queue * p);
int isFullDQ(const d_queue * p, unsigned sizeEl);
int enqueueDQ(d_queue * p, void * el, unsigned sizeEl);
int dequeueDQ(d_queue * p, void * el, unsigned sizeEl);
int peekDQ(d_queue * p, void *el , unsigned sizeEl);
#endif // QUEUE_H_INCLUDED

