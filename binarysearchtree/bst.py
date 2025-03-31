class MySet:
    def __init__(self):
        self.data = []
    def insert(self, x):
        if x not in self.data:
            self.data.append(x)
    def is_in(self, x):
        return x in self.data
    
# insertion is O(n)
# search is in O(n)



class MyDict:
    def __init__(self):
        self.data = []
    def insert(self, x, value):
        if x not in self.data:
            self.data.append((x, value))
    def is_in(self, x):
        for k, val in self.data:
            if k == x:
                return True
        return False
    def get(self, x):
        for k, val in self.data:
            if k == x:
                return val
        return None
    




class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val =key

def make_tree():
    root = Node((3, "lia"))
    root.left = Node((3, "Alice"))
    root.right = Node((5, "Charlie"))
    root.left.left = Node((0, "Dave"))
    root.left.right = Node((2.5, "Eve"))

def getval(key, root):
    if root == None:
        return None
    elif key == root.val[0]:
        return root.val[1]
    elif key < root.val[0]:
        return getval(key root.left)
    else:
        return getval(key, root.right)