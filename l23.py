def DFS_rec(g, cur, visited = None):
    if visited == None:
        visited = [False] * g.num_nodes
    
    cur_i = g.node_names[cur]
    cur_neighbour = g.nodes[cur_i].head
    visited[cur_i] = True
    print(cur)
    while cur_neighbour:
        if not visited[cur_neighbour.data]:
            DFS_rec(g, g.node_names_rev[cur_neighbour.data], visited) # helps go through all nodes
        cur_neighbour = cur_neighbour.next


# to travel and ensure all nodes in the tree are visited