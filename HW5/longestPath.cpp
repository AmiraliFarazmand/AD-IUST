// longest path in a graph
//  Used graph DS from techie delight website, and chat-gpt 3.5
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
vector<int> distance(100, 0);
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
        }
    }

    vector<vector<int>> adjList;
};

void recursiveDFS(Graph const &graph, int node, vector<bool> &visited, vector<int> &departure_times, int &time)
{
    visited[node] = true;
    for (int neighbour : graph.adjList[node])
    {
        if (!visited[neighbour])
        {
            recursiveDFS(graph, neighbour, visited, departure_times, time);
        }
    }
    departure_times[node] = time--;
}

void topological_sort(Graph const &graph, int n, vector<int> &topological_order)
{
    vector<bool> visited(n, false);
    vector<int> departure_times(n, -1);
    int time = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            recursiveDFS(graph, i, visited, departure_times, time);
        }
    }

    for (int i = 0; i < n; i++)
    {
        topological_order[departure_times[i]] = i;
    }
}

int find_longest_path(Graph const &graph, int src)
{
    int V = graph.adjList.size();

    vector<int> topological_order(V);
    topological_sort(graph, V, topological_order);

    vector<int> dist(V, INT_MIN);
    dist[src] = 0;

    for (int i = 0; i < V; i++)
    {
        int u = topological_order[i];

        if (dist[u] != INT_MIN)
        {
            for (int v : graph.adjList[u])
            {
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }
    }

    int longest_path = INT_MIN;
    for (int d : dist)
    {
        longest_path = max(longest_path, d);
    }

    return longest_path;
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

    cout << "****";
    int max_length = 0;
    Graph graph(edges, v);
    int longest_path = find_longest_path(graph, 0);
    cout << "The length of the longest path is: " << longest_path << endl;
    // vector<int> topological_order(v);
    // topological_sort(graph, v, topological_order);

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