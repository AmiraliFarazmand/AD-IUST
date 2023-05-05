#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int parent[MAXN][20], depth[MAXN];

void dfs(int u, int p, int d) {
    parent[u][0] = p;
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void precompute_parents(int n) {
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (parent[i][j-1] != -1) {
                parent[i][j] = parent[parent[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = 19; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1, -1, 0);
    precompute_parents(n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = lca(u, v);
        cout << ans << endl;
    }

    return 0;
}