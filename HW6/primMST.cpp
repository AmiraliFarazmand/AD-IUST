// Kruskal Algorithm
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
    int node_start;
    int node_end;
    int weight;
};

bool compWeight(const Edge a, const Edge b)
{
    return a.weight < b.weight;
}

class Graph
{

private:
    int num_nodes;
    vector<Edge> edgelist; 
    vector<int> parent;
    vector<int> rank;

public:
    Graph() {}
    Graph(int num_nodes)
    {
        this->num_nodes = num_nodes;
        parent.resize(num_nodes);
        rank.resize(num_nodes);
    }

    void AddEdge(Edge e)
    {
        edgelist.push_back(e);
    }

    int FindParent(int node)
    {

        if (node != parent[node])
            parent[node] = FindParent(parent[node]);
        return parent[node];


    }

    void KruskalMST(vector<Edge> &result)
    {

        for (int i = 0; i < num_nodes; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        sort(edgelist.begin(), edgelist.end(), compWeight);

        for (Edge e : edgelist)
        {
            int root1 = FindParent(e.node_start);
            int root2 = FindParent(e.node_end);

            if (root1 != root2)
            {
                result.push_back(e);
                if (rank[root1] < rank[root2])
                {
                    parent[root1] = root2;
                    rank[root2]++;
                }
                else
                {
                    parent[root2] = root1;
                    rank[root1]++;
                }
            }
        }
    }
    void calculateSumEdges(vector<Edge> &edges)
    {

        int cost = 0;
        for (Edge e : edges)
        {
            cost += e.weight;
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
        swap(tempEdge.node_start, tempEdge.node_end);
        t.AddEdge(tempEdge);
    }

    vector<Edge> MST;
    t.KruskalMST(MST);
    t.calculateSumEdges(MST);

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