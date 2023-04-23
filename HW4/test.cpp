// Iterative DFS implementation
// Modified code of previous part
#include <string>
#include <vector>
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
void iterativeDFS(Graph const &graph, int node, vector<bool> &is_visited)
{
    stack<int> node_stack;
    node_stack.push(node);

 while (!node_stack.empty())
    {
        int node = node_stack.top();
        node_stack.pop();
        if (is_visited[node])
            continue;
        else if (!is_visited[node])
        {
            cout << node +1<< "\n";
            is_visited[node] = true;
        }
        for (int n : graph.adjList[node])
        {
            if (!is_visited[n])
            {
                node_stack.push(n);
            }
        }
    }    
}

int main()
{
    int v, e;
    cin >> v >> e;
    int start_node;
    cin >> start_node;

    vector<bool> is_visited(v);
    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        Edge temp_edge;
        int node1, node2;
        cin >> node1 >> node2;
        temp_edge.src = node1-1;
        temp_edge.dest = node2-1;
        edges.push_back(temp_edge);
    }
    Graph graph(edges, v);
    iterativeDFS(graph, start_node-1, is_visited);
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