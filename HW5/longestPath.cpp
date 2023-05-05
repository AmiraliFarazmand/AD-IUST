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
vector<int> distance(100,0);
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
void topological_sort(Graph const &graph, int n)
{
    vector<int> departure(2 * n, -1);

    vector<bool> discovered(n);
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (!discovered[i])
        {
            recursiveDFS(graph, i, discovered, departure, time);
        }
    }

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (departure[i] != -1)
        {
            cout << departure[i] + 1 << " ";
        }
    }
}

int find_longest_path(Graph const &grap){

}

int main()
{
    int v;
    cin >> v;
    vector<Edge> edges;
    for (int i = 0; i < v; i++)
    {
        Edge temp_edge;
        int u, v;
        cin >> u >> v;
        temp_edge.src = u - 1;
        temp_edge.dest = v - 1;
        edges.push_back(temp_edge);
    }

    int max_length=0;
    Graph graph(edges, v-1);

    return 1;
}