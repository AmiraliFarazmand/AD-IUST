#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN];

void dfs(int node, int p, int d) {
    depth[node] = d;
    parent[node] = p;
    for(int neighbor : adj[node]) {
        if(neighbor != p) {
            dfs(neighbor, node, d+1);
        }
    }
}

int lca(int u, int v) {
    while(depth[u] > depth[v]) {
        u = parent[u];
    }
    while(depth[v] > depth[u]) {
        v = parent[v];
    }
    while(u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main() {
    int n = 6;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        int lc = lca(u, v);
        cout << lc << " ";
    }
    cout << endl;
    return 0;
}