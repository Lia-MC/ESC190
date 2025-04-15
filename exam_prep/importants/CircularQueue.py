class CircularQueue:
    def __init__(self, size):
        self.array = [None] * size
        self.start = 0
        self.end = 0
        self.size = size
        self.numelemts = 0
    def enqueue(self, item):
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