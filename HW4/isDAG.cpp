// Singly connected graph
//  Used graph DS from techie delight website
// I also may have used the code from previous problems
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
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
        adjList.resize(n);

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            // adjList[edge.dest].push_back(edge.src);
        }
    }
};
void DFS(Graph const &graph, int node, vector<bool> &visisted, vector<int> &departure_time, int &time)
{
    visisted[node] = true;
    for (int neighbour : graph.adjList[node])
    {
        if (!visisted[neighbour])
        {
            DFS(graph, neighbour, visisted, departure_time, time);
        }
    }
    departure_time[node] = time++;
}

bool isDAG(Graph const &graph, int n)
{
    vector<bool> visited_nodes(n);

    vector<int> departure(n);

    int time = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited_nodes[i])
        {
            DFS(graph, i, visited_nodes, departure, time);
        }
    }
    for (int u = 0; u < n; u++)
    {
        for (int v : graph.adjList[u])
        {
            if (departure[u] <= departure[v])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int e, v;
    cin >> v >> e;
    vector<Edge> edges;
    for (int i = 1; i <= e; i++)
    {
        Edge temp_edge;
        int u, v;
        cin >> u >> v;
        temp_edge.src = u - 1;
        temp_edge.dest = v - 1;
        edges.push_back(temp_edge);
    }

    Graph graph = Graph(edges, v);
    bool res = isDAG(graph, v);
    if (res)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
/*
Example 1 :
Input:
4 2
1 2
2 3
Output:
YES
19
Example 2 :
Input:
4 4
1 2
2 3
3 4
4 2
Output:
YES
Example 3 :
Input:
3 3
1 2
2 3
1 3
Output:
NO
*/