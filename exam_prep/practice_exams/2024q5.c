// Question 5. [15 marks]
// In C, implement a circular queue of strings.
// Your implementation must include ENQUEUE and DEQUEUE operations, which must work with
// enqueing and dequeing C strings. Your implementation should enable the use of enqueue an arbitrary
// number of elements.
// A circular queue, is a data structure that uses a an array and two pointers to indicate the start position
// and the end position.
// Consider a circular queue with a maximum size of 4, that holds elements ‘a’, ‘b’, ‘c’, and ‘d’. The
// initial state of the queue might be:
// a b c d
// Front Rear
// After a dequeue operation, the front pointer moves to ‘b’. After an enqueue operation of ‘e’, the rear
// pointer moves to ‘e’. The queue now contains: ‘b’, ‘c’, ‘d’, and ‘e’.
// e b c d
// Rear Front
// If another dequeue operation is performed, the front pointer moves to ‘c’. The queue becomes: ‘c’, ‘d’,
// ‘e’, and the front position is now free. This illustrates the efficient use of space in a circular queue where
// elements can wrap around to the beginning of the array.

// in python:
/*
MY ATTEMPT RN:
class CircularQueue:
    def __init__(self, cap, start):
        self.arr = []
        self.size = 0
        self.start = start
        self.capacity = cap
    def enqueue(self, item):
        self.arr[(self.start + self.size) % self.cap] = item
        self.size += 1
    def dequeue (self):
        pop(self.arr[start])
        self.size -= 1
        if (self.start != self.size - 1):
            self.start += 1
        else:
            self.start = 0
ANSWER:
class CircularQueue:
    def __init__(self, size):
        self.array = [None] * size
        self.start = 0
        self.end = 0
        self.size = size
        self.numelemts = 0
    def push(self, item):
        if self.numelemts == self.size:
            print("queue is full :(")
            return 
        self.array[self.end] = item
        self.end = (self.end + 1) % self.size
        self.numelemts += 1

    def __repr__(self):
        res = []
        i = self.start
        count = 0
        while count < self.numelemts:
            res.append(self.array[i])
            i = (i + 1) % self.size
            count += 1
        return str(res)

    def pop(self):
        item = self.array[self.start]
        self.start = (self.start + 1) % self.size
        self.numelemts -= 1
*/

// Your implementation must include ENQUEUE and DEQUEUE operations, which must work with
// enqueing and dequeing C strings. Your implementation should enable the use of enqueue an arbitrary
// number of elements.

#if !defined(CQ_H)

#define CQ_H

typedef struct CircularQueue {
    int front;
    int rear;
    int *arr;
    int size;
    int cap;
} CircularQueue;

void createcircqueue(int cap) {
    CircularQueue *cq = (CircularQueue *)malloc(cap * sizeof(int));
    cq->size = 0;
    cq->cap = cap;
    cq->front;
    cq->rear;
    cq->arr = (int *)malloc(cap * sizeof(int));
}

void enqueue(CircularQueue *cq, int val) {
    cq->arr[cq->rear] = val;
    cq->rear = (cq->rear + 1) % cq->cap;
    cq->size++;
}

void dequeue(CircularQueue *cq) {
    free(cq->arr[cq->front]);
    cq->front = (cq->front + 1) % cq->cap;
    cq->size--;
}

#endif