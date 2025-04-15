#include <stdio.h>
#include <stdlib.h>
#include "2024circularqueueq5.h"

int main() {
    CircularQueue *q; // make memory storage
    int size = 5;

    createcircularqueue(&q, size); // initialize explicitly

    // Enqueue elements
    enqueuecircularqueue(q, 10); // normal enqueue
    enqueuecircularqueue(q, 20);
    enqueuecircularqueue(q, 30);
    enqueuecircularqueue(q, 40);
    enqueuecircularqueue(q, 50);

    // Try to enqueue one more (should fail if full)
    enqueuecircularqueue(q, 60);

    // Dequeue two elements
    dequeuecircularqueue(q); // normal dequeue
    dequeuecircularqueue(q);

    // Enqueue again (should work now)
    enqueuecircularqueue(q, 60);
    enqueuecircularqueue(q, 70); // Might be full here

    // Print the queue state
    printf("Queue contents:\n");
    int i = q->start;
    for (int count = 0; count < q->numelems; count++) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");

    destroycircularqueue(q); // normal destroy
    return 0;
}