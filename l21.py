# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.next = None


# # 0->1->2->3->4->5->6
# class LL:
#     def __init__(self):
#         self.head = None

#     def insert(self, ind, data):
#         new_node = Node(data)
#         if self.head == None:
#             self.head = new_node
#         else:
#             if ind == 0:
#                 head_save = self.head
#                 self.head = new_node
#                 self.head.next = head_save
#             else:
#                 cur = self.head
#                 for i in range(ind-1):
#                     cur = cur.next
#                 # right now, cur is the node after which we want to insert
#                 # need: cur.next = new_node, new_node.next = cur.next
#                 cur.next, new_node.next = new_node, cur.next
#     def is_in(self, data):
#         cur = self.head
#         while cur:
#             if cur.data == data:
#                 return True
#             cur = cur.next
#         return False

#     def print(self):
#         cur = self.head
#         while cur:  # can say != None
#             print(cur.data, "-> ", end = "")
#             cur = cur.next
#         print("None")

    
# if __name__ == '__main__':
#     myLL = LL()
#     myLL.insert(0, 123)
#     myLL.insert(0, 125)
#     myLL.print()

                


# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.next = None


# # 0->1->2->3->4->5->6
# class LL:
#     def __init__(self):
#         self.head = None

#     def insert(self, ind, data):
#         new_node = Node(data)
#         if self.head == None:
#             self.head = new_node
#         else:
#             if ind == 0:
#                 head_save = self.head
#                 self.head = new_node
#                 self.head.next = head_save
#             else:
#                 cur = self.head
#                 for i in range(ind-1):
#                     cur = cur.next
#                 # right now, cur is the node after which we want to insert
#                 # need: cur.next = new_node, new_node.next = cur.next
#                 cur.next, new_node.next = new_node, cur.next
#     def is_in(self, data):
#         cur = self.head
#         while cur:
#             if cur.data == data:
#                 return True
#             cur = cur.next
#         return False

#     def print(self):
#         cur = self.head
#         while cur:  # can say != None
#             print(cur.data, "-> ", end = "")
#             cur = cur.next
#         print("None")

    
# if __name__ == '__main__':
#     myLL = LL()
#     myLL.insert(0, 123)
#     myLL.insert(0, 125)
#     myLL.print()


import LL
class Graph2:
    def __init__(self, num_nodes):
        self.nodes = []
        for i in range(self.num_nodes):
            self.nodes.a[[end(LL.LL())]]

    def is_edge(self, i, j):
        return self.nodes[i].is_in(j)
    
    def put_edge(self, i, j):
        self.nodes[i].insert(0, j) ## insert is easy, just replace head with new node

    def remove_edge(self, i, j):
        ## 