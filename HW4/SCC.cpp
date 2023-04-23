#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 100005;                 // maximum number of nodes
vector<int> adj[MAXN], adjT[MAXN];       // adjacency lists of the graph and its transpose
int scc[MAXN], disc[MAXN], finish[MAXN]; // arrays used in Kosaraju's algorithm
bool vis[MAXN];                          // to keep track of visited nodes
// stack<int> st;                           // stack used in Kosaraju's algorithm
int scc_count = 0, disc_time = 0;        // variables used to count SCCs

void dfs1(int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs1(v);
        }
    }
    finish[++disc_time] = u;
}

void dfs2(int u)
{
    vis[u] = true;
    scc[u] = scc_count;
    for (int v : adjT[u])
    {
        if (!vis[v])
        {
            dfs2(v);
        }
    }
}

int main()
{
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u); // transpose the graph
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    // reset visited array
    fill(vis, vis + n + 1, false);
    // process nodes in reverse order of finish time
    for (int i = n; i >= 1; i--)
    {
        int u = finish[i];
        if (!vis[u])
        {
            scc_count++;
            dfs2(u);
        }
    }
    cout << scc_count << endl;
    return 0;
}