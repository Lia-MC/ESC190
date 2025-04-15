# Problem 1. Getting starting with Queue Implementation
# In Python, implement and test a Class that implements the Queue ADT as a circular array. The idea is
# as follows: the data is stored in a list. You keep track of the index where the data begins and the index
# where the data ends. You enqueue by inserting at the end, and dequeue by taking the element from the
# beginning.

# Start with the Queue implementation we had in class. Change it to start with a fixed-size list of None’s
# and modify it so that the indices wrap around when needed.
# Write an str method for your CircularQueue class. It should output a string that represents the
# contents of the queue.
# Test your CircularQueue class.

class Queue:
    def __init__(self):
        self.array = []
    def push(self, value):
        self.array.append(value)
    def pop(self):
        return self.array.pop(0) ## pop elem at index 0 of array
    
    def enqueue(self, item):
        self.array.append(item)
    def dequeue(self, item):
        ret = self.array[0]
        del self.array[0]
        return ret
    
# to use this class:
q = Queue() ## creates new q object in this class
q.push(11) ## appends 11 to queue


## queue is first in first out -> if i put in [5, 6, 7, 8] then 5 was put in first so im poping that first
## stack is last in first out??

class CircularQueue:
    def __init__(self, size):
        self.array = []
        self.start = 0
        self.end = 0
        self.size = size
    def enqueue(self, item):
        if self.end == self.size - 1:
            self.array[0] = item
            self.end = 0
        else: 
            self.array.append(item)
            self.end += 1
    # def baddequeue(self, item):
    #     found = False
    #     if self.end > self.start:
    #         for i in range(self.start, self.end):
    #             if self.array[i] == item:
    #                 found = True
    #             elif found == True:
    #                 self.array[i - 1] = self.array[i]
    #     else:
    #         for i in range(self.start, self.size - 1):
    #             if found:
    # def olddequeue(self):
    #     if self.end > self.start:
    #         for i in range(0, self.end - self.start):
    #             self.array[self.start + i] = self.array[self.start + i + 1]
    #     else:
    #         for i in range(self.start):
    # def wrongdequeue(self):
    #     if self.end > self.start:
    #         for i in range(self.start, self.end):
    #             self.array[i] = self.array[i + 1]
    #     else:
    #         for i in range(self.start, self.size - 2):
    #             self.array[i] = self.array[i + 1]
    #         self.array[self.size-2] = self.array[0]
    #         for i in range(0, self.end):
    #             self.array[i] = self.array[i + 1]
    def wrongdequeue(self):
        self.array[self.start] = None
        self.start += 1

# Write an str method for your CircularQueue class. It should output a string that represents the
# contents of the queue.
# Test your CircularQueue class.


# class solutions
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

        ## initial instincts:
        # self.array[self.end] = item ## append it to the end of the list
        # self.end += 1
        self.array[self.end] = item
        # self.end += 1
        # if self.end == self.size:
        #     self.end = 0
        self.end = (self.end + 1) % self.size
        self.numelemts += 1

        # if self.end == self.size - 1:
        #     self.array[0] = item
        #     self.end = 0
        # else: 
        #     self.array.append(item)
        #     self.end += 1

    # def __repr__(self):
    #     res = []
    #     i = self.start
    #     while i != self.end:
    #         res.append(self.array[i])
    #         i = (i + 1) % self.size
    #     return str(res)

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
        # self.start += 1 ## cant just do this because this doesnt account for the wrap arounds
        self.numelemts -= 1


    # Problem 2. Sorting CircularQueues
    # Suppose we would like to sort CircularQueues, assuming that they contain integers as data. The Queues
    # would be sorted lexicographically: a sequence of number s1 comes before sequence s2 if in the first number
    # that differs between s1 and s2, the number in s1 is smaller than the one in s2. For example, the following
    # is an example a list of sorted queues:
    # 1->5->5
    # 2->1->5
    # 2->5->10->12
    # 11->2
    # Write code that sorts CircularQueues. Do this by implementing the lt method.

    # sorts multiple circular queues in order

    # def __lt__(self):
    #     if 

def to_list(self):
        res = []
        i = self.start
        count = 0
        while count < self.numelemts:
            res.append(self.array[i])
            i = (i + 1) % self.size
            count += 1
        return res

def __repr__(self):
    return str(self.to_list())

def __lt__(self, other):
    L1 = self.to_list()
    L2 = other.to_list()
    return L1 < L2

def lt(q1, q2): ## less than operator, ## self is q1, other is q2
    sorted = False
    i = 0
    while (sorted == False): 
        if q1.array[(q1.start + i) % q1.size] < q2.array[(q2.start + i) % q2.size]:
            return q1, q2
        elif q1.array[(q1.start + i) % q1.size] == None and q2.array[(q2.start + i) % q2.size] != None:
            return q1, q2
        elif q1.array[(q1.start + i) % q1.size] != None and q2.array[(q2.start + i) % q2.size] == None:
            return q2, q1
        i += 1