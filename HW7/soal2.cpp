// problem No.2
// Used help from chat-gpt
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
    // int weight;
};

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

    int numNodesAccessible(int n)
    {
        // Initialize vector to keep track of visited nodes
        vector<bool> visited(num_nodes, false);
        visited[0] = true;

        // Initialize queue for BFS traversal
        queue<int> q;
        q.push(0);

        // Initialize variables to keep track of current move and number of accessible nodes
        int moves = 0;
        int num_accessible = 0;

        while (!q.empty() && moves <= n)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                num_accessible++;

                // Add unvisited neighbors to queue
                for (Edge e : edgelist)
                {
                    if (e.node_start == curr && !visited[e.node_end])
                    {
                        q.push(e.node_end);
                        visited[e.node_end] = true;
                    }
                }
            }

            moves++;
        }

        return num_accessible;
    }
};
int main()
{
    int n, e, maxMoves;
    cin >> n >> e;
    vector<int> sources, destinations, cs;
    for (int i = 1; i <= e; i++)
    {
        // Edge tempEdge;
        int u, v, temp_c;
        cin >> u >> v >> temp_c;
        sources.push_back(u);
        destinations.push_back(v);
        cs.push_back(temp_c);
        // t.AddEdge(tempEdge);
        // swap(tempEdge.node_start, tempEdge.node_end);
        // t.AddEdge(tempEdge);
    }
    cin >> maxMoves;
    // auto sumCs = std::reduce(cs.begin(), cs.end());
    Graph t(n);

    Edge tempEdge;
    for (int k = 0; k < cs.size(); k++)
    {
        int temp_c = cs[k];
        if (temp_c > 0)
        {
            tempEdge.node_start = n;
            tempEdge.node_end = sources[k];
            t.AddEdge(tempEdge);
            swap(tempEdge.node_start, tempEdge.node_end);
            t.AddEdge(tempEdge);
            // n++;
            for (int i = 1; i < temp_c; i++)
            {
                tempEdge.node_start = n;
                tempEdge.node_end = n + 1;
                t.AddEdge(tempEdge);
                swap(tempEdge.node_start, tempEdge.node_end);
                t.AddEdge(tempEdge);
                n++;
            }
            tempEdge.node_start = n;
            tempEdge.node_end = destinations[k];
            t.AddEdge(tempEdge);
            swap(tempEdge.node_start, tempEdge.node_end);
            t.AddEdge(tempEdge);
            n++;
        }
        else
        {
            tempEdge.node_start = sources[k];
            tempEdge.node_end = destinations[k];
            t.AddEdge(tempEdge);
            swap(tempEdge.node_start, tempEdge.node_end);
            t.AddEdge(tempEdge);
        }
    }

    cout << t.numNodesAccessible(maxMoves) << endl;

    return 0;
}
/*
Example 1 :
Input :
3 3
0 1 10
0 2 1
1 2 2
6
Output :
13


Example 2 :
Input :
5 5
1 2 4
1 4 5
1 3 1
2 3 4
3 4 5
17
Output :
1


*/