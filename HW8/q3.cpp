// maximum flow problem where vertices have capacities
// solved using chatGPT and
// https://stackoverflow.com/questions/8751327/edmonds-karp-algorithm-for-a-graph-which-has-nodes-with-flow-capacities
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Number of vertices in the graph
#define MAX_VERTICES 4000

// Structure to represent a directed edge
struct Edge
{
    int v;        // To vertex
    int capacity; // Capacity of the edge
    int flow;     // Flow through the edge (initially set to 0)
};

// Function to add an edge to the graph
void addEdge(vector<Edge> *graph, int u, int v, int capacity)
{
    Edge e1 = {v, capacity, 0};
    Edge e2 = {u, 0, 0};
    graph[u].push_back(e1);
    graph[v].push_back(e2);
}

// Function to find a path from source to sink using BFS
bool bfs(vector<Edge> *graph, int source, int sink, int parent[])
{
    bool visited[MAX_VERTICES] = {false};

    // Create a queue for BFS
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    // Standard BFS loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (const auto &edge : graph[u])
        {
            int v = edge.v;
            int capacity = edge.capacity;
            int flow = edge.flow;

            if (!visited[v] && capacity > flow)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached the sink, then there is a path from source to sink
    return visited[sink];
}

// Function to implement the Ford-Fulkerson algorithm
int fordFulkerson(vector<Edge> *graph, int source, int sink)
{
    int parent[MAX_VERTICES];
    int maxFlow = 0;

    // Augment the flow while there is a path from source to sink
    while (bfs(graph, source, sink, parent))
    {
        int pathFlow = INT_MAX;

        // Find the maximum flow that can be pushed through this path
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            for (const auto &edge : graph[u])
            {
                if (edge.v == v)
                {
                    pathFlow = min(pathFlow, edge.capacity - edge.flow);
                    break;
                }
            }
        }

        // Update residual capacities and reverse edges along the path
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            for (auto &edge : graph[u])
            {
                if (edge.v == v)
                {
                    edge.flow += pathFlow;
                    break;
                }
            }

            for (auto &edge : graph[v])
            {
                if (edge.v == u)
                {
                    edge.flow -= pathFlow;
                    break;
                }
            }
        }

        // Add path flow to overall flow
        maxFlow += pathFlow;
    }

    // Return the overall flow
    return maxFlow;
}

int main()
{
    int numNodes, numEdges;
    cin >> numNodes;
    cin >> numEdges;

    vector<Edge> graph[MAX_VERTICES];
    int edges_data[numEdges][4];

    for (int i = 0; i < numEdges; i++)
    {
        int u, v, capacity;
        cin >> edges_data[i][0] >> edges_data[i][1] >> edges_data[i][2];
    }

    int cap;
    for (int i = 1; i <= numNodes; i++)
    {
        cin >> cap;
        addEdge(graph, i, 2000 + i, cap);
    }

    for (int i = 0; i < numEdges; i++)
    {
        addEdge(graph, 2000 + edges_data[i][0], edges_data[i][1], edges_data[i][2]);
    }
    int source, sink;
    cin >> source >> sink;

    int maxFlow = fordFulkerson(graph, source, 2000 + sink);
    cout << maxFlow << endl;

    return 0;
}

/*
Example1:
Input :
4 4
3 2 7
2 4 3
1 3 1
1 4 6
5 6 6 4
1 4
Output :
4
*/