// LCA
//  Used graph DS from AlgoTree website 
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

using namespace std;

class Tree
{

private:
    list<int> *adjlist;
    vector<int> parentlist;
    vector<bool> visited;
    vector<int> depth;

public:
    Tree()
    {
    }

    Tree(int nodes)
    {
        adjlist = new list<int>[nodes + 1];
        parentlist.resize(nodes + 1);
        visited.resize(nodes + 1);
        depth.resize(nodes + 1);
        depth[0] = -1;
    }

    ~Tree()
    {
        delete[] adjlist;
    }

    void add_edge(int src, int dst)
    {
        adjlist[src].push_back(dst);
        adjlist[dst].push_back(src);
    }

    void get_depths(int node, int parent)
    {

        depth[node] = depth[parent] + 1;

        for (auto &v : adjlist[node])
        {
            if (v != parent)
            {
                parentlist[v] = node;
                get_depths(v, node);
            }
        }
    }

    int findLCA(int node_a, int node_b)
    {

        while (node_a != node_b)
        {
            if (depth[node_a] > depth[node_b])
            {
                swap(node_a, node_b);
            }
            node_b = parentlist[node_b];
        }
        return node_a;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    Tree t(n);
    for (int i = 2; i <= n; i++)
    {
        int parent;
        cin >> parent;
        t.add_edge(parent, i); // -1 shayad bekhad!!!!!
    }
    t.get_depths(1, 0);
    for (int k = 0; k < q; k++)
    {
        int u, v, res = 0;
        cin >> u >> v;
        res = t.findLCA(u, v);
        cout << res << endl;
    }

    return 0;
}
/*
6 4
1 1 2 2 5
1 5
4 6
5 3
6 2
Output:
1
2
1
2

*/