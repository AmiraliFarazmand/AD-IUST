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
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        adjList.resize(n);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Perform iterative DFS on graph starting from vertex `v`
void iterativeDFS(Graph const &graph, int v, vector<bool> &discovered)
{
    // create a stack used to do iterative DFS
    stack<int> stack;
 
    // push the source node into the stack
    stack.push(v);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // Pop a vertex from the stack
        v = stack.top();
        stack.pop();
 
        // if the vertex is already discovered yet,
        // ignore it
        if (discovered[v]) {
            continue;
        }
 
        // we will reach here if the popped vertex `v` is not discovered yet;
        // print `v` and process its undiscovered adjacent nodes into the stack
        discovered[v] = true;
        cout << v+1 << "\n";
 
        // do for every edge (v, u)
        // we are using reverse iterator (Why?)
        for (auto it = graph.adjList[v].rbegin(); it != graph.adjList[v].rend(); it++)
        {
            int u = *it;
            if (!discovered[u]) {
                stack.push(u);
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

    vector<bool> is_visited(v, 0);
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
    iterativeDFS(graph, start_node, is_visited);
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