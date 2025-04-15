# for each vertex v:
# 	dist[v] = float(‘inf’)
# 	prev[v] = none
# dist[source] = 0
# set all vertices to unexplored
# while destination not explored:
# 	v = least-valued unexplored vertex
# 	set v to explored
# 	for each edge(v, w):
# 		if dist[v] + len(v, w) < dist[w]:
# 			dist[w] = dist[v] + len(v, w)
# 			prev[w] = v

import pq
import nodes

def mydijkstra(nodes, source, destination):
    dist = []
    prev = []
    explored = []
    ds = pq() ## priority queue
    for node in nodes:
        dist[v] = float('inf')
        prev[v] = None
    dist[source] = 0
    explored.append(source)
    while destination not in explored:
        v = ds[0]
        explored.append(v)
        for v, w in node.neighbours:
            if dist[v] + len(v, w) < dist[w]:
                dist[w] = dist[v] + len(v, w)
                prev[w] = v