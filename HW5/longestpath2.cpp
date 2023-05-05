// longest path in a graph
//  Used graph DS from techie delight website, and help from chat-gpt 3.5
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
    Graph(vector<Edge> const &edges, int V) : adjList(V)
    {
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }

    vector<vector<int>> adjList;
};
int last_node=0;
int max_length=0;
void recursiveDFS(Graph const &graph, int node, vector<bool> &visisted, int distance)
{
    visisted[node] = true;
    if (max_length <distance)
    {
        max_length = distance;
        last_node = node;
    }
    for (int neighbour : graph.adjList[node])
    {
        if (!visisted[neighbour])
        {
            recursiveDFS(graph, neighbour, visisted, distance + 1);
        }
    }
}

int find_longest_path(Graph const &graph, int src,int V)
{
    int len = 0;
    vector<bool> visisted(V, 0);
    recursiveDFS(graph, src, visisted, 0);
    vector<bool> visisted2(V, 0);
    recursiveDFS(graph, last_node, visisted2, 0);
    return max_length;
}

int main()
{
    int v;
    cin >> v;
    vector<Edge> edges;
    for (int i = 0; i < v - 1; i++)
    {
        Edge temp_edge;
        int u, w;
        cin >> u >> w;
        temp_edge.src = u - 1;
        temp_edge.dest = w - 1;
        edges.push_back(temp_edge);
    }

    int max_length = 0;
    Graph graph(edges, v);
    int longest_path = find_longest_path(graph, 0,v);
    cout  << longest_path ;

    return 1;
}
/*
Example 1 :
Input:
3
1 2
1 3
Output:
2
Example 2 :
Input:
4
1 2
3 1
4 2
Output:
3

*/