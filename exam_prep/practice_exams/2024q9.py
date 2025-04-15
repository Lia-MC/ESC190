# Question 9. [5 marks]


# Part (a) [2 marks]
# Construct a binary search tree as shown. You must use the code below. Store the root of the tree in the
# variable root.
#  1
# / \
# 4  5
#   /
#  7
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

if __name__ == '__main__':
    root = Node(1)
    root.left = Node(4)
    root.right = Node(5)
    root.right.left = Node(7)

# Part (b) [3 marks]
# Write a function that takes in the root of a binary search tree and returns the sum of all the nodes in the
# tree

def findsum(root):
    if root is None:
        return 0
    return root.value + findsum(root.left) + findsum(root.right)

def badfindsum(root):
    sum = 0
    while (root != None):
        sum += findsum(root.left) + findsum(root.right)
    return sum