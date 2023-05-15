#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

const int INF = numeric_limits<int>::max();

// Dijkstra's Algorithm
map<int, int> dijkstra(const map<int, map<int, int>>& graph, int start) {
    map<int, int> dist;
    for (auto& kvp : graph) {
        dist[kvp.first] = INF;
    }
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int u = top.second;
        int d = top.first;
        if (d > dist[u]) continue;
        for (auto& kvp : graph.at(u)) {
            int v = kvp.first;
            int weight = kvp.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int findSecondMinimumCost(map<int, map<int, int>> graph) {
    // Step 1: Find the minimum cost of connecting all cities
    map<int, int> minCost = dijkstra(graph, 1);
    int minPathEnd = 1;
    for (auto& kvp : minCost) {
        if (kvp.second != INF) {
            minPathEnd = kvp.first;
        }
    }

    // Step 2: Remove the edges that are part of the minimum cost path
    vector<int> minPath;
    int u = minPathEnd;
    while (u != 1) {
        minPath.push_back(u);
        for (auto& kvp : graph.at(u)) {
            int v = kvp.first;
            if (v == 1) {
                continue;
            }
            if (minCost[u] == minCost[v] + kvp.second) {
                graph[u].erase(v);
                graph[v].erase(u);
                u = v;
                break;
            }
        }
    }
    minPath.push_back(1);

    // Step 3: Find the second minimum cost of connecting all cities
    int secondMinCost = INF;
    for (auto& kvp : graph) {
        int node = kvp.first;
        map<int, int> dist = dijkstra(graph, node);
        int currentCost = 0;
        for (auto& kvp2 : dist) {
            currentCost += kvp2.second;
        }
        if (currentCost < secondMinCost && currentCost > minCost[minPathEnd]) {
            secondMinCost = currentCost;
        }
    }
    return secondMinCost != INF ? secondMinCost : -1;
}

int main() {
    int v, e;
    cin >> v >> e;
    map<int, map<int, int>> graph;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int secondMinCost = findSecondMinimumCost(graph);
    cout << secondMinCost << endl;
    return 0;
}

/*

Input:
4 3
1 2 1
4 1 3
2 3 1
Output:
-1

4 4
1 2 1
4 1 3
2 3 1
1 3 2
Output:
6
*/