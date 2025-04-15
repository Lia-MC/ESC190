import heapq

def pq_djikstra_no_path(start, end):
    start.distancefromstart = 0 # my source node!
    tobeconsidered = [(0, start)] # my priority queue!
    # Each element in pq is a tuple: (distance_from_start, node)
    visited = set() # keeps track of visited nodes

    # whats set()??

    while tobeconsidered: # as long as pq is not empty
        cur_dist, current = heapq.heappop(tobeconsidered) 
        # cur_dist is shortest known distance to reach current
        # current is current node
        # this is because Each element in pq is a tuple: (distance_from_start, node)
        if current in visited:
            continue
        visited.add(current) # add to the set, append if visited is a list
        # Adding checks if an element is in a set and, if it isn’t, 
        # it puts the element in the set in an arbitrary order determined by a data structure 
        # called a hash table that you cannot modify.
        current.distancefromstart = cur_dist

        if current == end:
            return current.distancefromstart # we've reached destination! whatever is there is there
        
        # Assumes current.connections is a list of edge objects (with .node and .weight)
        for neighbour in current.connections: # for each neighbour of the current node
            if neighbour.node not in visited:
                heapq.heappush(tobeconsidered, (cur_dist + neighbour.weight, neighbour.node)) # priority is based on the weight
    
    return float('inf')


import heapq
def full_dijkstra_with_path(graph, start_node):
    # Initialize distances
    dist = {}
    for node in graph.nodes:
        dist[node] = float('inf')
    dist[start_node] = 0
    # Initialize prev
    prev = {}
    for node in graph.nodes:
        prev[node] = None
    # Priority queue: (distance, node)
    pq = [(0, start_node)]
    while pq:
        current_dist, current_node = heapq.heappop(pq)
        # Skip if we've already found a better path
        if current_dist > dist[current_node]:
            continue
        for neighbor, weight in current_node.neighbours:
            new_dist = dist[current_node] + weight
            if new_dist < dist[neighbor]: # "Relaxation" step
                dist[neighbor] = new_dist
                heapq.heappush(pq, (new_dist, neighbor))
                prev[neighbor] = current_node
    #returns a dictionary of thhe shortest distance to every node from "start_node"
    return dist

'''
import pq  # Assuming this is a custom priority queue class
import nodes  # Your custom node definitions

def mydijkstra(nodes_dict, source, destination):
    dist = {}
    prev = {}
    explored = set()
    ds = pq()

    for node in nodes_dict:
        dist[node] = float('inf')
        prev[node] = None

    dist[source] = 0
    ds.push((0, source))  # priority queue holds (distance, node)

    while not ds.is_empty():
        current_dist, u = ds.pop()  # get node
'''