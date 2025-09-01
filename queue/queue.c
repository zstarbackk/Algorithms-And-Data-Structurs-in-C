#include "queue.h"
void SQcreateQueue(t_queue * pQueue){
    pQueue->start=0;
    pQueue->end=0;
    pQueue->available=MAX_SIZE;
}
void SQqueueClear(t_queue * pQueue){
    pQueue->start=0;
    pQueue->end=0;
    pQueue->available=MAX_SIZE;
}
int SQisEmpty(const t_queue * pQueue){
    return (pQueue->available==MAX_SIZE);
}
int SQisFull(const t_queue * pQueue, unsigned sizeEl){
    return (pQueue->available>=sizeEl+sizeof(unsigned));
}
int SQenqueue(t_queue * pQueue, void * el, unsigned sizeEl){
    unsigned ini, fin;
    if(pQueue->available<sizeEl+sizeof(unsigned))
        return 0;
    pQueue->available -= sizeof(unsigned)+sizeEl;
    ini = MIN(sizeof(unsigned),MAX_SIZE-pQueue->end);
    fin = sizeof(unsigned)-ini;
    if(ini>0)
        memcpy(pQueue->queue+pQueue->end,&sizeEl,ini);
    if(fin>0)///Si fin > 0 significa que tuvo que ir al inicio del chunk de memoria, por lo tanto pqueue->end = fin;
        memcpy(pQueue->queue+pQueue->end+ini, ((char*)&sizeEl)+ini, fin);
    pQueue->end = fin>0?fin:pQueue->end+ini;
    ini = MIN(sizeEl, MAX_SIZE-pQueue->end);
    fin = sizeEl-ini;
    if(ini>0)
        memcpy(pQueue->queue+pQueue->end, el, ini);
    if(fin>0)
        memcpy(pQueue->queue+pQueue->end+ini, ((char*)el)+ini, fin);
    pQueue->end= fin>0?fin:pQueue->end+ini;
    return 1;
}
int SQdequeue(t_queue * pQueue, void * el, unsigned sizeEl){
    unsigned ini, fin, sizeElQueue, auxStart, auxSize;
    if(pQueue->start==pQueue->end)
        return 0;


    ini = MIN(sizeof(unsigned),MAX_SIZE-pQueue->start);
    fin = sizeof(unsigned)-ini;
    if(ini>0)
        memcpy(&sizeElQueue, pQueue->queue+pQueue->start, ini);
    if(fin>0)
        memcpy(((char*)&sizeElQueue)+ini,pQueue->queue+ pQueue->start+ini, fin);
    auxSize = MIN(sizeEl, sizeElQueue);
    auxStart = fin>0?fin:pQueue->start+ini;


    ini =MIN(auxSize, MAX_SIZE-auxStart);
    fin = auxSize-ini;
    if(ini>0)
        memcpy(el, pQueue->queue+auxStart, ini);
    if(fin>0)
        memcpy(((char*)el)+ini,pQueue->queue, fin);
    auxStart= fin>0?fin:auxStart+ini;


    pQueue->available+=sizeof(unsigned)+auxSize;
    pQueue->start=auxStart;
}
int SQpeek(t_queue * pQueue, void *el , unsigned sizeEl){
    unsigned ini, fin, sizeElQueue, auxStart, auxSize;
    if(pQueue->start==pQueue->end)
        return 0;


    ini = MIN(sizeof(unsigned),MAX_SIZE-pQueue->start);
    fin = sizeof(unsigned)-ini;
    if(ini>0)
        memcpy(&sizeElQueue, pQueue->queue+pQueue->start, ini);
    if(fin>0)
        memcpy(((char*)&sizeElQueue)+ini,pQueue->queue+ pQueue->start+ini, fin);
    auxSize = MIN(sizeEl, sizeElQueue);
    auxStart = fin>0?fin:pQueue->start+ini;


    ini =MIN(auxSize, MAX_SIZE-auxStart);
    fin = auxSize-ini;
    if(ini>0)
        memcpy(el, pQueue->queue+auxStart, ini);
    if(fin>0)
        memcpy(((char*)el)+ini,pQueue->queue, fin);
    auxStart= fin>0?fin:auxStart+ini;
}
