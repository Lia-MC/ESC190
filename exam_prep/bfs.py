import graphs.py
def breadthfirsttraversal(g, start_name):
    start_i = g.node_names[start_name]
    visited = [False] * g.num_nodes # [false, false, false, ...]
    DS = ds.Queue() # initialize data structure, ds is the file that stores the Queue
    # note for ^, if i change it to ds.Stack() then this becomes depthfirsttraversal!!!!!!!!
    DS.add(start_i) # add a nonvisited vertex vi to datastructure
    while not DS.is_empty(): # while data structure is not empty
        cur = DS.get() # remove some nonvisited vertext from datastructure, here its a queue so get implies dequeue
        if not visited[cur]:
            visited[cur] = True # mark it as visited
            cur = g.nodes[cur].head.next
            while cur:
                if not visited[cur.data]:
                    DS.add(cur.data)
                cur = cur.next