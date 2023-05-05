#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int farthestNode, maxDist;

void dfs(int node, int dist) {
    visited[node] = true;
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }
    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs(v, dist + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);  
    visited.assign(n + 1, false);
    dfs(farthestNode, 0);  
    cout << maxDist << endl;
    return 0;
}
