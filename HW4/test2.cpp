// #include<bits/stdc++.h>
// using namespace std;

// // This class represents a directed graph using adjacency
// // list representation
// class Graph
// {
//     int V;    // No. of vertices
//     list<int> *adj;    // adjacency lists
// public:
//     Graph(int V);  // Constructor
//     void addEdge(int v, int w); // to add an edge to graph
//     void DFS(int s);  // prints all vertices in DFS manner
//     // from a given source.
// };

// Graph::Graph(int V)
// {
//     this->V = V;
//     adj = new list<int>[V];
// }

// void Graph::addEdge(int v, int w)
// {
//     adj[v].push_back(w); // Add w to v’s list.
// }

// // prints all not yet visited vertices reachable from s
// void Graph::DFS(int s)
// {
//     // Initially mark all vertices as not visited
//     vector<bool> visited(V, false);

//     // Create a stack for DFS
//     stack<int> stack;

//     // Push the current source node.
//     stack.push(s);

//     while (!stack.empty())
//     {
//         // Pop a vertex from stack and print it
//         int s = stack.top();
//         stack.pop();

//         // Stack may contain same vertex twice. So
//         // we need to print the popped item only
//         // if it is not visited.
//         if (!visited[s])
//         {
//             cout << s << "\n";
//             visited[s] = true;
//         }

//         // Get all adjacent vertices of the popped vertex s
//         // If a adjacent has not been visited, then push it
//         // to the stack.
//         for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
//             if (!visited[*i])
//                 stack.push(*i);
//     }
// }
// int main()
// {

// 	int v, e;
// 	cin >> v >> e;
// 	Graph g(v); // Total 5 vertices in graph

// 	int start_node;
// 	cin >> start_node;

// 	for (int i = 0; i < e; i++)
// 	{
// 		int node1, node2;
// 		cin >> node1 >> node2;
// 		g.addEdge(node1, node2);
// 	}
// 	// cout << "Following is Depth First Traversal\n";
// 	// g.addEdge(1, 0);
// 	// g.addEdge(0, 2);
// 	// g.addEdge(2, 1);
// 	// g.addEdge(0, 3);
// 	// g.addEdge(1, 4);

// 	g.DFS(start_node);

// 	return 0;
// }

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Data structure to store a graph edge
struct Edge
{
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
        for (auto &edge : edges)
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
        if (discovered[v])
        {
            continue;
        }

        // we will reach here if the popped vertex `v` is not discovered yet;
        // print `v` and process its undiscovered adjacent nodes into the stack
        discovered[v] = true;
        cout << v << "\n";

        // do for every edge (v, u)
        // we are using reverse iterator (Why?)
        for (auto it = graph.adjList[v].rbegin(); it != graph.adjList[v].rend(); it++)
        {
            int u = *it;
            if (!discovered[u])
            {
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

    vector<Edge> edges;
    for (int i = 0; i < e; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        Edge tempEdge;
        tempEdge.src = node1;
        tempEdge.dest = node2;
        edges.push_back(tempEdge);
    }
    // build a graph from the given edges
    Graph graph(edges, v);

    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(v, false);

    iterativeDFS(graph, start_node, discovered);

    return 0;

    return 0;
}
