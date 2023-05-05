#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> adj[20001];
bool visited[20001];
int dist[20001];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    int farthest = 0;
    int max_dist = 0;
    for (int i = 1; i <= 20000; i++) {
        if (visited[i] && dist[i] > max_dist) {
            farthest = i;
            max_dist = dist[i];
        }
    }

    return farthest;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = bfs(1);

    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    int end = bfs(start);
    cout << dist[end] << endl;

    return 0;
}