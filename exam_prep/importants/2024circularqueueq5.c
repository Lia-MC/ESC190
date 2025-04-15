#include "2024circularqueueq5.h"
#include <stdio.h>
#include <stdlib.h>

void createcircularqueue(CircularQueue **p_cq, int size) {
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue));
    cq->start = 0;
    cq->end = 0;
    cq->size;
    cq->arr = (int *)malloc(size * sizeof(int));
    cq->numelems = 0;
    *p_cq = cq;
}

void destroycircularqueue(CircularQueue *cq) { // needs int size - why????
    free(cq->arr);
    free(cq);
}

void enqueuecircularqueue(CircularQueue *cq, int data) {
    // recall its a queue so we add to the end
    cq->numelems++;
    cq->arr[cq->end] = data;
    cq->end = (cq->end + 1) % cq->size;
}

void dequeuecircularqueue(CircularQueue *cq) {
    // free(cq->arr[cq->start]);
    cq->start = (cq->start + 1) % cq->size;
    cq->numelems--;
}