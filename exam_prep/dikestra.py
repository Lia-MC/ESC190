# path optimization - shortest path algorithm

# priority queues:
# A queue where each element has a priority
# Operations:
# enqueue(elem, priority): insert elem, with a given priority
# find_min: return the element with the smallest priority
# extract_min: remove the element with the smallest priority and return it
# Use: assign lower numbers to patients in the emergency room who need to be seen sooner

## NOT keeping track of path
import heapq
def dijkstra(graph, start_node):
    # Initialize distances
    dist = {node: float('inf') for node in graph.nodes}
    dist[start_node] = 0
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
    #returns a dictionary of thhe shortest distance to every node from "start_node"
    return dist

## YES keeping track of path
import heapq
def dijkstra(graph, start_node):
    # Initialize distances
    dist = {node: float('inf') for node in graph.nodes}
    dist[start_node] = 0
    # Initialize prev
    prev = {node: None for node in graph.nodes}
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

## KNOW HOW TO MAKE A PRIORITY QUEUE

# understand how to implement relaxation step
# understand how to use heapq




# even if we have a priority queue wouldnt we add nodes into the queue only when a node being visited is adjacent to it?
# if so, why does the first queue have all the nodes in it??