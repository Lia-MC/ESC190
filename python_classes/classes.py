
# equivalent of struct student where
# struct student {
#     char *name;
#     int age;
# }
class student:
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade
    def __lt__(self, other): # less than
        return self.grade < other.grade
        ## or make it like
        ## return self.name < other.name (that way bob comes first so its true that self is less than other)
    def __repr__(self):
        return self.name + "  " + str(self.grade)

# bob = student("Bob", 52)
# charlie = student("Charlie", 50)
# student.__lt__(bob, charlie) # False
# another way to call __lt__
# bob < charlie (calls __lt__ with self being bob, other being charlie)
# print(bob < charlie) # False
# david = student("David", 100)

printsorted([david, bob, charlie])

class Queue:
    def __init__(self):
        self.array = []
    def enqueue(self, item):
        self.array.append(item)
    def dequeue(self, item):
        ret = self.array[0]
        del self.array[0]
        return ret

if __name__ == "__main__":
    s = student("Bob", 52) ## essentially s.name = "Bob"; s.age = 52;
    s.eeffjkuhduigciu = 5 # adds a new attribute to this particular object
    print(s.name, s.age)

    q = Queue()
    Queue.enqueue(q, 5)
    q.enqueue(5) # same as above