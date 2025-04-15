#include "CircularQueue.h"
// #include "CircularQueue.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    CircularQueue *cq;
    CircularQueue_create(&cq, 3);
    CircularQueue_enqueue(cq, 12);
    CircularQueue_enqueue(cq, 13);
    CircularQueue_enqueue(cq, 14);
    CircularQueue_dequeue(cq);
    CircularQueue_enqueue(cq, 16);
    print(cq);
}