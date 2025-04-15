'''
Queues FIFO (First in first out)
enqueue and dequeue
enqueue - add an element to the back of the queue
dequeue - return AND remove the element that was first added to the queue
'''

class Queue:
    def __init__(self):
        self.data = []
    def enqueue(self, elem):
        self.data.append(elem)  # Add to the back
    def dequeue(self):
        return self.data.pop(0)  # Remove from the front

if __name__ == '__main__':
    q = Queue()
    q.enqueue(5)
    q.enqueue(15)
    q.dequeue()  # should dequeue 5
