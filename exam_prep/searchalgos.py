# graph
graph1 = {
    'A': ['B', 'C'],
    'B': ['D', 'E', 'F'],
    'C': ['G'],
    'D': [],
    'E': [],
    'F': ['H'],
    'G': ['I'],
    'H': [],
    'I': []
}


# breadth first search
# search horizontally before vertically
# use queues (first in first out)

class Node:
    def __init__(self, data):
        self.data = data
        self.neighbours = []
class Graph:
    def __init__(self):
        self.nodes = [] # One representation

def bfs(graph): 
    visited = set() # Average insertion/lookup time is O(1)
    
    for starting_node in graph.nodes:
        queue = [starting_node]

        while len(queue) > 0:
            node = queue.pop(0)
            if node not in visited:
                print(node.data) #  Process Step!
                visited.add(node)
                queue.extend(node.neighbours)

    return visited

# def bfs(graph, node): # node -> starting node?

    # visited = []
    # queue = []

    # visited.append(node)
    # queue.append(node)

    # while queue: # while queue is not empty
    #     s = queue.pop(0) # first elem is the one i refer 
        
    #     for n in graph[s]: # for each adjacent node for the element im referring to
    #         if n not in visited:
    #             visited.append(n)
    #             queue.append(n)

graph2 = {
    'A': ['B', 'G'],
    'B': ['C', 'D', 'E'],
    'C': [],
    'D': [],
    'E': ['F'],
    'F': [],
    'G': ['H'],
    'H': ['I'],
    'I': []
}

# depth first search (iterative)
# search vertically before horizontally
# use stacks (first in last out?????)

class Node:
    def __init__(self, data):
        self.data = data
        self.neighbours = []
class Graph:
    def __init__(self):
        self.nodes = [] # One representation

def dfs(graph, starting_node):
    visited = set() # Average insertion/lookup time is O(1)
    
    stack = [starting_node]
    
    while len(stack) > 0:
        node = stack.pop()
        if node not in visited:
            print(node.data) #Process step!
            visited.add(node)
            stack.extend(node.neighbours)
    return visited

# def dfs(graph, node):
    # visited = []
    # stack = dequeue()
    
    # visited.append(node)
    # stack.append(node)

    # while stack:
    #     s = stack.pop()
        
    #     for n in reversed(graph[s]):
    #         if n not in visited:
    #             visited.append(n)
    #             stack.append(n)

# depth first search (recursive)
# search vertically before horizontally
# use stacks (Last in, first out)
    # push(elem): add elem to the top of the stack
    # pop(): return the elem from the top of the stack, and remove it
    # isEmpty(): return True iff stack is empty and element cannot be popped

def DFS_rec(g, cur, visited = None):
    if visited == None:
        visited = [False] * g.num_nodes
    
    cur_i = g.node_names[cur]
    cur_neighbour = g.nodes[cur_i].head
    visited[cur_i] = True
    print(cur)
    while cur_neighbour:
        if not visited[cur_neighbour.data]:
            DFS_rec(g, g.node_names_rev[cur_neighbour.data], visited)
        cur_neighbour = cur_neighbour.next