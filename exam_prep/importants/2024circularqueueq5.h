// Question 5. [15 marks]
// In C, implement a circular queue of strings.
// Your implementation must include ENQUEUE and DEQUEUE operations, which must work with
// enqueing and dequeing C strings. Your implementation should enable the use of enqueue an arbitrary
// number of elements.
// A circular queue, is a data structure that uses a an array and two pointers to indicate the start position
// and the end position.
// Consider a circular queue with a maximum size of 4, that holds elements ‘a’, ‘b’, ‘c’, and ‘d’. The
// initial state of the queue might be
// After a dequeue operation, the front pointer moves to ‘b’. After an enqueue operation of ‘e’, the rear
// pointer moves to ‘e’. The queue now contains: ‘b’, ‘c’, ‘d’, and ‘e’.
// If another dequeue operation is performed, the front pointer moves to ‘c’. The queue becomes: ‘c’, ‘d’,
// ‘e’, and the front position is now free. This illustrates the efficient use of space in a circular queue where
// elements can wrap around to the beginning of the array.

#if !defined(CQ_H)
#define CQ_H

typedef struct CircularQueue {
    int start;
    int end;
    int size;
    int *arr;
    int numelems;
} CircularQueue;

void createcircularqueue(CircularQueue **p_cq, int size);

void destroycircularqueue(CircularQueue *cq, int size); // needs int size - why????

void enqueuecircularqueue(CircularQueue *cq, int data);

void dequeuecircularqueue(CircularQueue *cq);

#endif