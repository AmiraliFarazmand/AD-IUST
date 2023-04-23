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
        adjList.resize(n + 1);

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
void recursiveDFS(Graph const &graph, int node, vector<bool> &visisted, vector<int> &departure_time, int &time)
{
    visisted[node] = true;
    time++;
    for (int neighbour : graph.adjList[node])
    {
        if (!visisted[neighbour])
        {
            recursiveDFS(graph, neighbour, visisted, departure_time, time);
        }
    }
    departure_time[time] = node;
    time++;
}

int main()
{
    int e, v;
    cin >> e >> v;
    vector<Edge> edges;
    Edge temp_edge;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        temp_edge.src = u - 1;
        temp_edge.dest = v - 1;
        edges.push_back(temp_edge);
    }

    Graph graph = Graph(edges, v);
    // count_connected_components(graph, v);
    return 0;
}