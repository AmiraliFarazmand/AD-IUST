#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 10005;
const int INF = 1e9;

struct Edge {
    int from, to, weight;
};

int V, E;
int dist[MAXN][MAXN], parent[MAXN][MAXN];
vector<int> smallest_cycle;

void floyd_warshall() {
    // Initialize distances and parent pointers
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = INF;
            parent[i][j] = -1;
        }
        dist[i][i] = 0;
    }
    // Read in the edges and update the distances and parent pointers
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        parent[u][v] = u;
    }
    // Compute all pairs shortest paths
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}

void find_smallest_cycle() {
    // Iterate over all cycles in the graph and check if they have negative weight
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (dist[i][j] != INF && dist[j][i] != INF && dist[i][j] + dist[j][i] < 0) {
                vector<int> cycle;
                int x = j;
                bitset<MAXN> visited;
                // Traverse parent pointers to find the nodes in the negative cycle
                while (!visited[x]) {
                    cycle.push_back(x);
                    visited[x] = 1;
                    x = parent[i][x];
                }
                cycle.push_back(x);
                reverse(cycle.begin(), cycle.end());
                // Print the nodes in the negative cycle if itis the smallest one found so far
                if (cycle.size() < smallest_cycle.size() || smallest_cycle.empty()) {
                    smallest_cycle = cycle;
                }
            }
        }
    }
}

int main() {
    // Read in the input
    scanf("%d%d", &V, &E);
    // Run the Floyd-Warshall algorithm to compute all pairs shortest paths
    floyd_warshall();
    // Find the smallest negative cycle in the graph
    find_smallest_cycle();
    // Print the result
    if (!smallest_cycle.empty()) {
        printf("%d", smallest_cycle[0]);
        for (int i = 1; i < smallest_cycle.size(); i++) {
            printf(" %d", smallest_cycle[i]);
        }
    } else {
        printf("-1");
    }
    return 0;
}