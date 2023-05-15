// Prim's Algorithm
//  Used Tree DS from AlgoTree website
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

class Edge
{
public:
    int src;
    int dest;
    int weight;
};

bool compWeight(const Edge a, const Edge b)
{
    return a.weight < b.weight;
}

class Graph
{
public:
    Graph(vector<Edge> const &edges, int V) : adjList(V)
    {
        for (auto &edge : edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }

    vector<vector<int>> adjList;
};
int last_node = 0;
int max_length = 0;
void recursiveDFS(Graph const &graph, int node, vector<bool> &visisted, int distance)
{
    visisted[node] = true;
    if (max_length < distance)
    {
        max_length = distance;
        last_node = node;
    }
    for (int neighbour : graph.adjList[node])
    {
        if (!visisted[neighbour])
        {
            recursiveDFS(graph, neighbour, visisted, distance + 1);
        }
    }
}

void primMST(Graph const &graph, vector<Edge> &result, int v)
{
    int n = v;
    vector<bool> visited(n + 1, false);
    vector<Edge> availableEdges;
    int visitedCount = 1;
    int start_node = 0;
    visited[start_node] = true;
    availableEdges.insert(availableEdges.end(), graph.adjList[start_node].begin(), graph.adjList[start_node].end());
    int weightCount = 0;
    while (visitedCount < n)
    {
        visited[start_node] = true;
        for (Edge e : availableEdges)
        {
            Edge edge = availableEdges.front();
            availableEdges.erase(availableEdges.begin());
            result.push_back(edge); 
            int destNode = edge.dest;
            weightCount += edge.weight;
            if (visited[destNode] == false)
            {
                visited[destNode] = true;
                visitedCount++;
                // availableEdges.push_back(e);
                availableEdges.insert(availableEdges.end(), graph.adjList[e.dest].begin(), graph.adjList[e.dest].end());
                sort(availableEdges.begin(), availableEdges.end(), compWeight);
            }
        }
    }
    cout<<weightCount<<endl;
}
void calculateSumEdges(vector<Edge> &edges)
{

    int cost = 0;
    for (Edge e : edges)
    {
        cost += e.weight;
    }
    cout << cost << endl;
};

int main()
{
    int n, e;
    cin >> n >> e;
    // Graph t();
    vector<Edge> edgelist;
    for (int i = 1; i <= e; i++)
    {
        Edge tempEdge;
        int u, v, weight;
        cin >> u >> v >> weight;
        tempEdge.src = u - 1;
        tempEdge.dest = v - 1;
        tempEdge.weight = weight;
        edgelist.push_back(tempEdge);
        // swap(tempEdge.src, tempEdge.dest);
        // t.AddEdge(tempEdge);
    }
    Graph(edgelist, n);
    vector<Edge> MST;
    // t.KruskalMST(MST);
    // t.calculateSumEdges(MST);

    return 0;
}
/*
Input:
4 4
1 2 1
1 3 4
3 4 2
1 4 3
Output:
6

*/