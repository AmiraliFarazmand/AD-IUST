// number of strongly connected components in a directed graph using Kosaraju's algorithm
// Solved with using chat-gpt3.5
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <algorithm>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

const int MAXNUMBER = 10000;                              // maximum number of nodes
vector<int> adj[MAXNUMBER], adj_transpose[MAXNUMBER];     // adjacency lists of the graph and its transpose
int scc[MAXNUMBER], disc[MAXNUMBER], finished[MAXNUMBER]; // arrays used in Kosaraju's algorithm
bool visited[MAXNUMBER];                                  // to keep track of visited nodes
int scc_count = 0, disc_time = 0;                         // variables used to count SCCs

void DFS1(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS1(v);
        }
    }
    finished[++disc_time] = u;
}

void DFS2(int u)
{
    visited[u] = true;
    scc[u] = scc_count;
    for (int v : adj_transpose[u])
    {
        if (!visited[v])
        {
            DFS2(v);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_transpose[v].push_back(u);
    }
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            DFS1(i);
        }
    }
    fill(visited, visited + v + 1, false);
    for (int i = v; i >= 1; i--)
    {
        int u = finished[i];
        if (!visited[u])
        {
            scc_count++;
            DFS2(u);
        }
    }
    // cout << scc_count << endl;
    if (scc_count<=1)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}