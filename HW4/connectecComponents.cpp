// Count the number of connected components in a graph
//  Used graph DS from techie delight website
// I also used the code from topologicalSort.cpp 
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

    cout << count << endl;
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
    count_connected_components(graph, v);
    return 0;
}
/*
Input:
2
4
1 2
3 2
Output:
2
*/