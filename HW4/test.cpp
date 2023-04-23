#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Data structure to store a graph edge
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
 
        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
 
// Function to perform DFS traversal on the graph on a graph
void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    // mark current node as visited
    visited[v] = true;
 
    // do for every edge (v, u)
    for (int u: graph.adjList[v])
    {
        // `u` is not visited
        if (!visited[u]) {
            DFS(graph, u, visited);
        }
    }
}
 
// Function to check if the graph is strongly connected or not
bool isStronglyConnected(Graph const &graph, int n)
{
    // do for every vertex
    for (int i = 0; i < n; i++)
    {
        // to keep track of whether a vertex is visited or not
        vector<bool> visited(n);
 
        // start DFS from the first vertex
        DFS(graph, i, visited);
 
        // If DFS traversal doesn't visit all vertices,
        // then the graph is not strongly connected
        if (find(visited.begin(), visited.end(), false) != visited.end()) {
            return false;
        }
    }
 
    return true;
}
 
int main()
{
    // vector of graph edges as per the above diagram
      int e, v;
    cin >> v>>e;
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

    Graph graph = Graph(edges, v);;
 
    // build a graph from the given edges
    // Graph graph(edges, v);
 
    // check if the graph is not strongly connected or not
    if (isStronglyConnected(graph, v)) {
        cout << "The graph is strongly connected";
    }
    else {
        cout << "The graph is not strongly connected";
    }
 
    return 0;}