#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

// pass in **p_cq because changing cq itself

void CircularQueue_create(CircularQueue **p_cq, int size) {
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue) * size);
    cq->start = 0;
    cq->end = 0;
    cq->size = size;
    cq->numelems = 0;
    cq->arr = (int *)malloc(sizeof(int) * size);
    *p_cq = cq;
}

// CircularQueue *cq;
// CircularQueue_create(&cq, 5);


// pass in *cq because changing contents of cq:

void CircularQueue_destroy(CircularQueue *cq, int size) {
    free(cq->arr);
    free(cq);
}

void CircularQueue_enqueue(CircularQueue *cq, int data) {
    if (cq->numelems == cq->size) {
        cq->arr = (int *)realloc(cq->arr, 2 * cq->size * sizeof(int)); // params of realloc: old block, size of newblock
        // if we already wrap around, but we expand the list, then we need to take some of the wrapped around stuff and move it
        if (cq->end < cq->start) {
            for (int i = 0; i < cq->end; i++) {
                cq->arr[i + cq->size] = cq->arr[i];
            }
        }
        cq->end += cq->size;
        cq->size *= 2;
        // or could also do with memmove
        // memove(cq->arr + cq->size, cq->arr, cq->end * sizeof(int));
        // return;
    }

    cq->arr[cq->end] = data;
    cq->end = (cq->end + 1) % cq->size;
    cq->numelems++;
}

void CircularQueue_dequeue(CircularQueue *cq) {
    // free(cq->arr[cq->start]);
    cq->start = (cq->start + 1) % cq->size;
    cq->numelems--;
}

void CircularQueue_print(CircularQueue *cq) {
    int i = cq->start;
    int count = 0;
    for (count = 0; count < cq->numelems; count++) {
        // print("%d", cq->arr[(count) % cq->numelems]);
        print("%d ", cq->arr[i]);
        i = (i + 1) % cq->size;
    }
    print("\n");
}