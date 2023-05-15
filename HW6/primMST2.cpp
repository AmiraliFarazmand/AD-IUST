// Prim's Algorithm
//  Used Tree DS from AlgoTree website & chat-gpt 3.5
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
#include <functional> 
#include <unordered_set>
using lint = long int;
using lolint = long long int;
// typedef vector<vector<int>> Matrix;
using namespace std;
class Edge
{
public:
    int node_start;
    int node_end;
    int weight;
};

class Graph
{
private:
    int num_nodes;
    vector<Edge> edgelist;
    vector<vector<pair<int, int>>> adj_list;

public:
    Graph(int num_nodes)
    {
        this->num_nodes = num_nodes;
        adj_list.resize(num_nodes);
    }

    void AddEdge(Edge e)
    {
        edgelist.push_back(e);
        adj_list[e.node_start].push_back({e.node_end, e.weight});
        adj_list[e.node_end].push_back({e.node_start, e.weight});
    }

    void PrimMST()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> key(num_nodes, INT_MAX);
        vector<int> parent(num_nodes, -1);
        unordered_set<int> visited;

        int src = 0;
        pq.push({0, src});
        key[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            visited.insert(u);

            for (auto &neighbor : adj_list[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (visited.find(v) == visited.end() && weight < key[v])
                {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }

        int cost = 0;
        for (int i = 1; i < num_nodes; i++)
        {
            cost += key[i];
        }
        cout << cost << endl;
    }
};

int main()
{

    int n, e;
    cin >> n >> e;
    Graph t(n);
    for (int i = 1; i <= e; i++)
    {
        Edge tempEdge;
        int u, v, weight;
        cin >> u >> v >> weight;
        tempEdge.node_start = u - 1;
        tempEdge.node_end = v - 1;
        tempEdge.weight = weight;
        t.AddEdge(tempEdge);
        // swap(tempEdge.node_start, tempEdge.node_end);
        // t.AddEdge(tempEdge);
    }

    vector<Edge> MST;
    t.PrimMST();
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