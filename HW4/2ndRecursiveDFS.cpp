// Recursive DFS implementation
//  Used graph DS from techie delight website
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
        adjList.resize(n + 1);

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
void recursiveDFS(Graph const &graph, int node, vector<bool> &visisted)
{
    visisted[node] = true;
    cout << node << endl;
    for (int neighbour : graph.adjList[node])
    {
        if (!visisted[neighbour])
        {
            recursiveDFS(graph, neighbour, visisted);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    int start_node;
    cin >> start_node;

    vector<bool> is_visited(v, 0);
    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        Edge temp_edge;
        int node1, node2;
        cin >> node1 >> node2;
        temp_edge.src = node1;
        temp_edge.dest = node2;
        edges.push_back(temp_edge);
    }
    Graph graph(edges, v);
    recursiveDFS(graph, start_node, is_visited);
    return 0;
}
/*
Input:
4 3
1
1 2
1 3
1 4
Output:
1
2
3
4
*/