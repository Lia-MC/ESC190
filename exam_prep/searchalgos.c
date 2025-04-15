void BFS(Graph* g, int startVertex) {
    //initialize visited list and queue
    int* visited = (int *)malloc(graph->numVertices * sizeof(int));
    Queue q;
    initQueue(&q);
    visited[startVertex] = true;
    enqueue(&q, startVertex);
    
    while (!isEmpty(&q)) { //isEmpty method is simple to implement
        int current = dequeue(&q); //get first element from list
        printf("%d ", current); // <-- Process Step
        for (int i = 0; i < graph->numVertices; ++i) {
            if (g->adjMatrix[current][i] == 1 && !visited[i]) {
                //get all adjacent ("1 distance" away)
                //mark as visited and add to queue
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}