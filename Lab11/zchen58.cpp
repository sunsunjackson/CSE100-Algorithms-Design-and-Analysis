//I collaborated with Angel Snavely
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <stack>
#include <list>

using namespace std;

const int MAX_N = 101;

bool visit[MAX_N] = {0};
vector<int> adj[MAX_N], rev[MAX_N], seq;
vector< vector<int> > SCC;

void DFS(vector<int> G[], vector<int> &res, int i) {
    visit[i] = true;
    for(int j = 0; j < G[i].size(); j++) // for each vertex
        if(!visit[G[i][j]]) 
            DFS(G, res, G[i][j]);
    res.push_back(i);
}

int main() {
    int i, j, k, u, v, vertices = 0, edges = 0, comp;
    cin >> vertices >> edges;
    int arr[vertices];
    for(i = 0; i < vertices; i++)
        arr[i] = i;
    for(i = 0; i < edges; i++) { //make "graph" for edge(u,v)
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(i = 0; i < vertices; i++)
        visit[i] = false;
    for(i = 0; i < vertices; i++)
        if(!visit[i])
            DFS(adj, seq, i);
    for(i = 0; i < vertices; i++)
        for(j = 0; j < adj[i].size(); j++)
            rev[adj[i][j]].push_back(i);
    for(i = 0; i < vertices; i++)
        visit[i] = false;
    reverse(seq.begin(), seq.end());
    for(i = 0; i < seq.size(); i++)
        if(!visit[seq[i]]) {
            vector<int> comp;
            DFS(rev, comp, seq[i]);
            SCC.push_back(comp);
        }
    for(i = 0; i < SCC.size(); i++) {
        for(j = 0; j < SCC[i].size(); j++) {
            comp = SCC[i][j];
            for(k = 0; k < vertices; k++) {
                if(arr[k] == comp)
                    arr[k] = *min_element(SCC[i].begin(), SCC[i].end());
            }
        }
    }
    for(i = 0; i < vertices; i++)
        cout << arr[i] <<endl;
    return 0;
}

