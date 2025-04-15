if !defined(CQ_H)

#define CQ_H

typedef struct CircularQueue {
    int start, end, size, numelems;
    int *arr;
} CircularQueue;

void createcircqueue(CircularQueue **p_cq, int size);
void destroycircqueue(CircularQueue *cq, int size);
void enqueue(CircularQueue *cq, int data);
void dequeue(CircularQueue *cq);
void print(CircularQueue *cq);

#endif