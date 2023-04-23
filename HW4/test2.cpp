#include <iostream>
#include <vector>
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
 
// Perform DFS on the graph and set the departure time of all vertices of the graph
int DFS(Graph const &graph, int v, vector<bool>
    &discovered, vector<int> &departure, int &time)
{
    // mark the current node as discovered
    discovered[v] = true;
 
    // do for every edge (v, u)
    for (int u: graph.adjList[v])
    {
        // if `u` is not yet discovered
        if (!discovered[u]) {
            DFS(graph, u, discovered, departure, time);
        }
    }
 
    // ready to backtrack
    // set departure time of vertex `v`
    departure[v] = time++;
}
 
// Returns true if given directed graph is DAG
bool isDAG(Graph const &graph, int n)
{
    // keep track of whether a vertex is discovered or not
    vector<bool> discovered(n);
 
    // keep track of the departure time of a vertex in DFS
    vector<int> departure(n);
 
    int time = 0;
 
    // Perform DFS traversal from all undiscovered vertices
    // to visit all connected components of a graph
    for (int i = 0; i < n; i++)
    {
        if (!discovered[i]) {
            DFS(graph, i, discovered, departure, time);
        }
    }
 
    // check if the given directed graph is DAG or not
    for (int u = 0; u < n; u++)
    {
        // check if (u, v) forms a back-edge.
        for (int v: graph.adjList[u])
        {
            // If the departure time of vertex `v` is greater than equal
            // to the departure time of `u`, they form a back edge.
 
            // Note that departure[u] will be equal to
            // departure[v] only if `u = v`, i.e., vertex
            // contain an edge to itself
            if (departure[u] <= departure[v]) {
                return false;
            }
        }
    }
 
    // no back edges
    return true;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    int e, n;
    cin >> n >> e;
    vector<Edge> edges;
    for (int i = 1; i <= e; i++)
    {
        Edge temp_edge;
        int u, v;
        cin >> u >> v;
        temp_edge.src = u - 1;
        temp_edge.dest = v - 1;
        edges.push_back(temp_edge);
    }
    // build a graph from the given edges
    Graph graph(edges, n);
 
    // check if the given directed graph is DAG or not
    if (!isDAG(graph, n)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
 
    return 0;
}