#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int diameter(vector<vector<int>>& graph) {
    int n = graph.size();
    int max_dist = 0;

    // Perform a BFS traversal starting from vertex 0 to find the farthest vertex
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    int last_visited = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int j = 0; j < size; j++) {
            int curr = q.front();
            q.pop();
            last_visited = curr;

            for (int neighbour : graph[curr]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        max_dist++;
    }

    // Perform a BFS traversal starting from the farthest vertex to find the diameter
    fill(visited.begin(), visited.end(), false);
    q.push(last_visited);
    visited[last_visited] = true;
    int dist = 0;

    while (!q.empty()) {
        int size = q.size();

        for (int j = 0; j < size; j++) {
            int curr = q.front();
            q.pop();

            for (int neighbour : graph[curr]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        dist++;
    }

    return max_dist ;//+ dist - 2;
}

int main() {
    int n;
    cin >> n ;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int diam = diameter(graph);
    cout  << diam ;

    return 0;
}