import numpy as np

class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distancefromstart = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

import heapq

pq = heapq.heapify([])
heapq.heappush(pq, (1, 2))
heapq.heappush(pq, (2, 3))
heapq.heappush(pq, (0, "C!")) # highest priority
heapq.heappop(pq)

def pq_djikstra(start, end):
    start.distancefromstart = 0
    visited = set([start])
    tobeconsidered = [(0, start)]

    while current != end:
        cur_dist, current = heapq.heappop(tobeconsidered)
        current.distancefromstart = cur_dist
        visited.add(current)
        for con in current.connections:
            if con.node in visited:
                continue
            heapq.heappush(tobeconsidered, (con.weight + current.distancefromstart, con.node)) # for pqs: (priority ranking, item)
    
    return current.distancefromstart

def og_djikstra(start, end):
    start.distancefromstart = 0
    visited = set([start])
    current = start

    while current != end:
        cur_dist = np.inf
        cur_v = None

        for node in visited:
            for con in node.connections:
                if con.node in visited:
                    continue
                if cur_dist > node.distancefromstart + con.weight:
                    cur_dist = node.distancefromstart + con.weight
                    cur_v = con.node
        
        current = cur_v
        current.distancefromstart = cur_dist
        visited.add(current)
    
    return current.distancefromstart