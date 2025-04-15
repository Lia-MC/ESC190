import LL

## symmetric, undirected -> no arrow heads, they go both ways, if there was an adjacency matrix, store it in both sides
## for weighted graphs, put infinities and weights

# adjacency list
# a linked lists of all the neighbours of the nodes

# complexity
# is there an edge between vi and vj?
#       adj matrix: O(1)
#       adj list: O(d) where d is maximum degree in graph / max number of edges that GO OUT of the node
# find all vertices adjacent to vi
#       adj matrix: O(|v|) where |v| is num of vertices in graph
#       adj list: O(d) where d is maximum degree in graph / max number of edges that GO OUT of the node

# using an adjacency matrix
import numpy as np
M = np.array((10, 10)) ## 10by10 matrix
M[0][1] # row 0 col 1

class Graph2:
    def __init__(self, numnodes):
        self.nodes = []
        for i in range(self.numnodes):
            self.nodes.append(LL.LL())

        ## or

        self.adj_matrix = np.zeros((numnodes, numnodes)) # initializes to zeroes

    def is_edge(self, i, j): ## means are they are connected?
        return self.nodes[i].is_in(j)
    
        ## or

        return self.adj_matrix[i][j] == 1
    
    def put_edge(self, i, j):
        self.nodes[i].insert(0, j)
    
        ## or 
        
        return self.adj_matrix[i][j] = 1

    def remove_edge(self, i, j):

        ## or 

        return self.adj_matrix[i][j] = 0


if __name__ == '__main__':
    g = Graph2(4)
    ## same as
    Graph2.__init__(g, 4) ## cant actually do this tho

    g.putedge(1, 2) 
    ## same as 
    Graph2.put_edge(g, 1, 2)
