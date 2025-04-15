'''
Stacks LIFO (Last in first out)
push and pop
push - an element onto the stack
pop - return AND remove the element that was most recently put onto the stack
'''

class Stack:
    def __init__(self):
        self.data = []
    def push(self, elem):
        self.data.append(elem)
    def pop(self):
        return self.data.pop()
    
if __name__ == '__main__':
    s = Stack()
    s.push(5)
    s.push(15)
    s.pop() ## should pop 15