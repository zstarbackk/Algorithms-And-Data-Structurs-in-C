#include "HybridQueue.h"

void HQcreateQueue(h_queue *pQueue) {
    pQueue->end = 0;
    pQueue->start = 0;
    pQueue->available = CANT;
}

void HQqueueClear(h_queue *pQueue) {
    int idx = pQueue->start;
    int count = CANT - pQueue->available;

    for (int i = 0; i < count; i++) {
        free(pQueue->cola[idx].data);
        pQueue->cola[idx].data = NULL;
        pQueue->cola[idx].tam = 0;
        idx = (idx + 1) % CANT;
    }

    pQueue->start = 0;
    pQueue->end = 0;
    pQueue->available = CANT;
}

int HQisEmpty(const h_queue *pQueue) {
    return pQueue->available == CANT;
}

int HQisFull(const h_queue *pQueue, unsigned sizeEl) {
    return pQueue->available == 0;
}

int HQenqueue(h_queue *pQueue, void *el, unsigned sizeEl) {
    if (HQisFull(pQueue, sizeEl))
        return 0;

    void *newData = malloc(sizeEl);
    if (!newData)
        return 0;

    memcpy(newData, el, sizeEl);
    pQueue->cola[pQueue->end].data = newData;
    pQueue->cola[pQueue->end].tam = sizeEl;

    pQueue->end = (pQueue->end + 1) % CANT;
    pQueue->available--;

    return 1;
}

int HQdequeue(h_queue *pQueue, void *el, unsigned sizeEl) {
    if (HQisEmpty(pQueue))
        return 0;

    memcpy(el, pQueue->cola[pQueue->start].data,
           MIN(pQueue->cola[pQueue->start].tam, sizeEl));

    free(pQueue->cola[pQueue->start].data);
    pQueue->cola[pQueue->start].data = NULL;
    pQueue->cola[pQueue->start].tam = 0;

    pQueue->start = (pQueue->start + 1) % CANT;
    pQueue->available++;

    return 1;
}

int HQpeek(h_queue *pQueue, void *el, unsigned sizeEl) {
    if (HQisEmpty(pQueue))
        return 0;

    memcpy(el, pQueue->cola[pQueue->start].data,
           MIN(pQueue->cola[pQueue->start].tam, sizeEl));

    return 1;
}
