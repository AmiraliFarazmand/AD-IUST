// Reachablity problem for graphs
// Used graph DS from techie delight website
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
        adjList.resize(n+1);

        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};

bool is_reachable(int src, int dest, int v, Graph &graph)
{
    vector<bool> visited(v);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (node == dest)
            return 1;
        for (int neighbour : graph.adjList[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return 0;
}

int main()
{
    int e, v;
    cin >> v >> e;
    int ali, reza;
    cin >> ali >> reza;
    vector<Edge> edges;
    Edge temp_edge;
    for (int i = 1; i <= v; i++)
    {
        int num = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int tempNode;
            cin >> tempNode;
            temp_edge.src = tempNode;
            temp_edge.dest = i;
            edges.push_back(temp_edge);
        }
    }
    Graph graph = Graph(edges, v);
    bool res = is_reachable(ali, reza, v, graph);
    if (res)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
/*
Input:
4 3
2 4
2 2 3
1 1
2 1 4
1 3
Output:
YES

*/