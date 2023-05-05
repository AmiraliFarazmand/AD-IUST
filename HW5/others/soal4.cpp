#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
vector<int> adj[MAXN], radj[MAXN];
bool vis[MAXN];
stack<int> st;
int scc[MAXN], scc_count = 0;
int scc_indegree[MAXN], ans = 0;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
    st.push(u);
}

void rdfs(int u, int component) {
    vis[u] = true;
    scc[u] = component;
    for (int v : radj[u])
        if (!vis[v])
            rdfs(v, component);
}

void kosaraju() {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    memset(vis, false, sizeof(vis));
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!vis[u]) {
            scc_count++;
            rdfs(u, scc_count);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    kosaraju();
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc[u] != scc[v])
                scc_indegree[scc[v]]++;
        }
    }
    for (int i = 1; i <= scc_count; i++)
        if (scc_indegree[i] == 0)
            ans++;
    cout << ans << endl;
    return 0;
}