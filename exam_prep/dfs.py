# RECURSIVE

# mark whatever node was visited as visited and whatever wasnt marked as visited, call dfs on it

def DFS_rec(g, cur, visited = None):
    if visited == None:
        visited = [False] * g.num_nodes
    
    cur_i = g.node_names[cur]
    cur_neighbour = g.nodes[cur_i].head # this is because each node i nthe adjacency list has a linked list, so the head is diff for each node
    visited[cur_i] = True
    print(cur)
    while cur_neighbour:
        if not visited[cur_neighbour.data]: # whatever wasnt marked as visited, call dfs on it
            DFS_rec(g, g.node_names_rev[cur_neighbour.data], visited) # loop through all the neighbours of that node
        cur_neighbour = cur_neighbour.next