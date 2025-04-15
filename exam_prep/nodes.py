class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class LL:
    def __init__(self):
        self.head = None
    def insert(self, ind, data):
        newnode = Node(data)
        if self.head == None:
            self.head = newnode
        else:
            if ind == 0:
                head_save = self.head
                self.head = newnode
                self.head.next = head_save
            else:
                cur = self.head
                for i in range(ind - 1):
                    cur = cur.next 
                cur.next, newnode.next = newnode, cur.next
    def print(self):
        cur = self.head
        while (cur.next):
            print(cur.data)
            cur = cur.next

if __name__ == '__main__':
    myLL= LL()
    myLL.insert(0, 123)
    myLL.insert(0, 123)