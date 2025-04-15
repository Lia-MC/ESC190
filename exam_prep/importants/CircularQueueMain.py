from CircularQueue import CircularQueue

if __name__ == '__main__':
    q = CircularQueue(5)  # Max size = 5

    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)

    print("Dequeued:", q.dequeue())

    q.enqueue(40)
    q.enqueue(50)
    q.enqueue(60)  # May show full if size limit reached

    q.pop()

    while not q.is_empty():
        print("Dequeued:", q.dequeue())