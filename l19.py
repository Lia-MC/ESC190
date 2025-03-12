class Graph:
    def __init__(self, num_nodes):
        self.adj_matrix = np.array((num_nodes, num_nodes))

    def is_edge(self, i , j):
        return self.adj_matrix[i][j] == 1

    def put_edge(self, i, j):
        self.adj_matrix[i][j] = 1

    def remove_edge(self, i, j):
        self.adj_matrix[i][j] = 0

    import numpy as np
    M = np.array((10, 10)) # a 10x10 matrix
    M[0][1] ## row 0 column 1

if __name__ == '__main__':
    g = Graph(4) # same as Graph.__init__(g, 4)
    g.put_edge(1, 2) # same as Graph.put_edge(g, 1, 2)