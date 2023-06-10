#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, capacity;
};

// Returns true if there is a path from source 's' to sink 't' in residual graph.
// Also fills parent[] to store the path
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

// A DFS based function to find all reachable vertices from s.
void dfs(vector<vector<int>>& rGraph, int s, vector<bool>& visited) {
    visited[s] = true;
    int V = rGraph.size();

    for (int v = 0; v < V; v++) {
        if (!visited[v] && rGraph[s][v] > 0) {
            dfs(rGraph, v, visited);
        }
    }
}

// Prints the minimum s-t cut
void minCut(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> rGraph = graph;
    vector<int> parent(V, -1);

    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }
    }

    vector<bool> visited(V, false);
    dfs(rGraph, s, visited);

    // Print all edges that are from a reachable vertex to non-reachable vertex in the original graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (visited[i] && !visited[j] && graph[i][j] > 0) {
                cout << i << " - " << j << endl;
            }
        }
    }
}

// Driver program to test above functions
int main() {
    int n, src, dest;
    cin >> n >> src >> dest;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    while (true) {
        int temp1, temp2, temp3;
        cin >> temp1;
        if (temp1 == -1)
            break;
        cin >> temp2 >> temp3;
        graph[temp1][temp2] = temp3;
    }

    minCut(graph, src, dest);

    return 0;
}
