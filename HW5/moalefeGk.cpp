// Gk (connected components)
//  Using connected # of components implementation from HW4// Count the number of connected components in a graph

#include <string>
#include <vector>
#include <queue>
// #include <sstream>
// #include <iterator>
#include <bits/stdc++.h>
// #include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;
struct Edge
{
    int src, dest;
};

class Graph
{
public:
    vector<vector<int>> adjList;

    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n + 1);

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
// int dp[10000][10000] = {10000};
Matrix dp(10000, vector<int>(10000, 10000));
void recursiveDFS(Graph const &graph, int node, vector<bool> &visisted, vector<int> &departure_time, int &time)
{
    visisted[node] = true;

    time++;

    for (int neighbour : graph.adjList[node])
    {
        if (!visisted[neighbour])
        {
            // dp[node][neighbour] = dp[neighbour][node] = distance + 1;
            recursiveDFS(graph, neighbour, visisted, departure_time, time);
        }
    }
    departure_time[time] = node;
    time++;
}
// void newBFS(Graph const &graph, int node, vector<bool> &visisted ,int distance)
// {
//     visisted[node] = true;

//     for (int neighbour : graph.adjList[node])
//     {
//         if (!visisted[neighbour])
//         {
//             dp[node][neighbour] = dp[neighbour][node] = distance + 1;
//             newBFS(graph, neighbour, visisted, distance + 1);
//         }
//     }
// }
void newBFS(Graph const &graph, queue<int> &q, vector<bool> &discovered, int distance)
{
    if (q.empty())
    {
        return;
    }

    // dequeue front node and print it
    int v = q.front();
    q.pop();
    // cout << v << " ";

    // do for every edge (v, u)
    for (int u : graph.adjList[v])
    {
        if(dp[v][u] >distance){
            dp[v][u] = dp[u][v] = distance+1;
        }
        if (!discovered[u])
        {
            // mark it as discovered and enqueue it
            discovered[u] = true;
            q.push(u);
        }
    }

    newBFS(graph, q, discovered, distance+1);
}

void count_connected_components(Graph const &graph, int n)
{
    vector<int> departure(2 * n, -1);

    vector<bool> visited(n, false);
    int time = 0;

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            count++;
            recursiveDFS(graph, i, visited, departure, time);
        }
    }

    cout << count << " ";
}

int main()
{
    int e, n;
    cin >> n;
    vector<Edge> edges;
    Edge temp_edge;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        temp_edge.src = u - 1;
        temp_edge.dest = v - 1;
        edges.push_back(temp_edge);
    }

    Graph graph = Graph(edges, n);
    vector<bool> visisted(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        q.push(i);
        newBFS(graph, q, visisted,0);
    }
    for (int k = 1; k <= n; k++)
    {
        vector<Edge> temp_edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] >= k & dp[i][j]!=10000)
                {
                    temp_edge.src = i;
                    temp_edge.dest = j;
                    temp_edges.push_back(temp_edge);
                }
            }
        }
        Graph tempGraph(temp_edges, n);
        count_connected_components(tempGraph, n);
    }
    // cout << endl;
    // count_connected_components(graph, n);
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//             cout << dp[i][j] << " ";
//         cout << endl;
//     }
    return 0;
}
/*
Example 1 :
Input:
6
1 2
1 3
2 4
2 5
3 6
Output:
1 1 2 4 6 6
*/