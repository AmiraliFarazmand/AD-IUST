// Mokhalefaane haakem
//  Used code from problem No.2
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
    int calculateSumEdges(vector<Edge> &edges)
    {

        int cost = 0;
        for (Edge e : edges)
        {
            cost += e.weight;
        }
        // cout << cost << endl;
        return cost;
    }
};

int main()
{
    int n, e, G, S;
    cin >> n >> e >> G >> S;
    vector<int> srcNodes(n);
    vector<int> destNodes(n);
    vector<int> golds(n);
    vector<int> silvers(n);
    int minBarare = INFINITY;
    Graph t(n);
    for (int i = 0; i < e; i++)
    {
        Edge tempEdge;
        // int u, v, weight,gold,silver;
        // cin >> u >> v >> gold>>silver;
        cin >> srcNodes[i] >> destNodes[i] >> golds[i] >> silvers[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int weight = golds[i] * G + silvers[i] * S;
            
            for (int k = 0; k < e; k++)
            {
            }
        }
    }
    vector<Edge> MST;
    t.KruskalMST(MST);
    t.calculateSumEdges(MST);

    return 0;
}
/*
Example 1 :
Input:
3 3
2 1
1 2 10 15
1 2 4 20
1 3 5 1
Output:
30

*/