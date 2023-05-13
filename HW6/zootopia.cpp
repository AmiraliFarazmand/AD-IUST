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

bool compWeight( Edge a,  Edge b)
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

    void zootopia(vector<Edge> &secondMST)
    {
        sort(edgelist.begin(), edgelist.end(), compWeight);

        // Find MST
        vector<Edge> mst;
        KruskalMST(mst, edgelist);

        // Iterate over edges in MST to find the second minimum spanning tree
        int min_cost = INT_MAX;
        vector<Edge> mst_edges(mst.size());
        for (int i = 0; i < mst.size(); i++)
        {
            parent.assign(num_nodes, -1);
            rank.assign(num_nodes, 0);
            vector<Edge> edges_copy(edgelist);

            // Remove edge i from the graph
            edges_copy.erase(remove(edges_copy.begin(), edges_copy.end(), mst[i]), edges_copy.end());

            // Find minimum spanning tree
            vector<Edge> second_mst;
            KruskalMST(second_mst, edges_copy);

            // Calculate cost of the new MST
            int cost = 0;
            for (Edge e : second_mst)
            {
                cost += e.weight;
            }

            // Update min_cost and mst_edges if the new MST is better
            if (cost < min_cost)
            {
                min_cost = cost;
                mst_edges = second_mst;
            }
        }

        // Print second minimum spanning tree
        cout << "Edges in the second minimum spanning tree:\n";
        for (Edge e : mst_edges)
        {
            cout << e.node_start << " - " << e.node_end << " with weight " << e.weight << endl;
            secondMST.push_back(e);
        }
        cout << "Total cost of second minimum spanning tree: " << min_cost << endl;
    }
    void KruskalMST(vector<Edge> &result, vector<Edge> newEdgeList)
    {

        for (int i = 0; i < num_nodes; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        sort(edgelist.begin(), edgelist.end(), compWeight);

        for (Edge e : newEdgeList)
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
        // swap(tempEdge.node_start, tempEdge.node_end);
        // t.AddEdge(tempEdge);
    }
    vector<Edge> secondMST;
     t.zootopia(secondMST);
    // std::cout <<-1;
    // vector<Edge> MST;
    // t.KruskalMST(MST);
    // t.calculateSumEdges(MST);

    return 0;
}
/*
Input:
4 3
1 2 1
4 1 3
2 3 1
Output:
-1

4 4
1 2 1
4 1 3
2 3 1
1 3 2
Output:
6
*/