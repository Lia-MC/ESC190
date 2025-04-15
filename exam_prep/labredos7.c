// typedef struct CircularQueue {
//     int start, end, size, numelems;
//     int *arr;
// } CircularQueue;

// void createcircqueue(CircularQueue **p_cq, int size);
// void destroycircqueue(CircularQueue *cq, int size);
// void enqueue(CircularQueue *cq, int data);
// void dequeue(CircularQueue *cq);

#include "labredos7.h"
#include <stdio.h>
#include <stdlib.h>

void createcircqueue(CircularQueue **p_cq, int size) {
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue));
    cq->start = 0;
    cq->end = 0;
    cq->size = size;
    cq->numelems = 0;
    cq->arr = (int *)malloc(size * sizeof(int));
    *p_cq = cq;
}

void destroycircqueue(CircularQueue *cq, int size) {
    // apprently you dont need to do this???
    // for (int i = 1; size; i++) {
    //     if (cq->arr[i] != NULL) {
    //         free(cq->arr[i]);
    //     }
    // }
    free(cq->arr);
    free(cq);
}

void enqueue(CircularQueue *cq, int data) {
    if (cq->numelems == cq->size) {
        return; // not enough space
    } 
    cq->arr[cq->end] = data;
    cq->end = (cq->end + 1) % cq->size;
    cq->numelems++;
}

void dequeue(CircularQueue *cq) {
    cq->arr[cq->start] = NULL;
    cq->numelems--;
    cq->start = (cq->start + 1) % cq->size;
}

void print(CircularQueue *cq) {
    int i;
    int count = 0;
    for (count = 0; count < cq->numelems; count++) {
        print("%d", cq->arr[i]);
        i = (i + 1) % cq->size;
    }
    print("n");
}