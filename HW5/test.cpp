#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

const int INF = 1e9;

int diameter(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Initialize the distance matrix with edge weights
    for (int i = 0; i < n; i++) {
        for (int j : graph[i]) {
            dist[i][j] = 1;
            dist[j][i] = 1;
        }
    }

    // Compute shortest path between all pairs of vertices using Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Find the maximum distance between any pair of vertices
    int max_dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_dist = max(max_dist, dist[i][j]);
        }
    }

    return max_dist;
}

int main() {
    int n, m;
    cin >> n ;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int diam = diameter(graph);
    cout << "The diameter of the graph is: " << diam << endl;

    return 0;
}