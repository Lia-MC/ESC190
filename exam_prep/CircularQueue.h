#if !defined(CQ_H)

#define CQ_H

typedef struct CircularQueue {
    int start;
    int end;
    int *arr;
    int size;
    int numelems;
} CircularQueue;

void CircularQueue_create(CircularQueue **p_cq, int size);

void CircularQueue_destroy(CircularQueue *cq, int size);

void CircularQueue_enqueue(CircularQueue *cq, int data);

void CircularQueue_dequeue(CircularQueue *cq);

#endif