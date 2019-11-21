// I collaborated with Tom Mcgee
#include <iostream>
#include <climits>

using namespace std;

int BellmanFord(int ** graph, int source, int numVertices, int numEdges) {
    int i;
    int j;
    int u;
    int v;
    int weight;
    int distance[numVertices];
    bool reachable;
    for(i = 0; i < numVertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    for(i = 1; i <= numVertices-1; i++) {
        for(j = 0; j < numEdges; j++) {
            u = graph[0][j], v = graph[1][j], weight = graph[2][j];
            if((distance[u] != INT_MAX) && (distance[u] + weight < distance[v])) {
                distance[v] = distance[u] + weight;
            }
        }
    }
    for(j = 0; j < numEdges; j++) {
        u = graph[0][j], v = graph[1][j], weight = graph[2][j];
        if((distance[u] != INT_MAX) && (distance[u] + weight < distance[v])) {
            cout << "FALSE" <<endl;
            reachable = false;
        }
    }
    if(reachable) {
        cout << "TRUE" <<endl;
        for(i = 0; i < numVertices; i++) {
            if(distance[i] != INT_MAX) {
                cout << distance[i] <<endl;
            } else {
                cout << "INFINITY" <<endl;
            }
        }
    }
    reachable = true;

    return 0;

}

int main() {
    int i;
    int j;
    int numVertices = 0;
    int numEdges;
    int u = 0;
    int v = 0;
    int weight = 0;
    cin >> numVertices;
    cin >> numEdges;
    int **graph;
    graph = new int *[3];
    for(i = 0; i < numVertices; i++) {
        graph[i] = new int[numEdges];
        for(j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
    for(i = 0; i < numEdges; i++) {
        cin >> u >> v >> weight;
        graph[0][i] = u, graph[1][i] = v, graph[2][i] = weight;
    }
    int BF;
    BF = BellmanFord(graph, 0, numVertices, numEdges);

}