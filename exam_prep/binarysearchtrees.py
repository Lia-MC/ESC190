class Node:
  def __init__(self, key):
      self.left = None
      self.right = None
      self.val = key


def make_tree():
    root = Node(3)
    root.left = Node(2)
    root.right = Node(5)
    root.left.left = Node(0)
    root.left.right = Node(2)
    #     3
    #    /  \
    #   1   5
    #  / \
    # 0  2
    return root

def in_tree(root, elem):
    if root is None:
        return False
    if root.val == elem:
        return True
    if root.val < elem:
        return in_tree(root.right, elem)
    else:
        return in_tree(root.left, elem)