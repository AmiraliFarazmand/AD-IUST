#include <iostream>
#include <list>
#include <vector>

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
        depth[0] = -1; // Hypothetical parent of root(1) is '0' at depth -1
    }

    ~Tree()
    {
        delete[] adjlist;
    }

    void AddEdge(int src, int dst)
    {
        adjlist[src].push_back(dst);
        adjlist[dst].push_back(src);
    }

    // Get parent of every node and find its depth
    void GetParentAndDepth(int node, int parent)
    {

        depth[node] = depth[parent] + 1;

        for (auto &v : adjlist[node])
        {
            if (v != parent)
            {
                parentlist[v] = node;
                GetParentAndDepth(v, node);
            }
        }
    }

    // Consider node_b at greater depth. Move node_b a level closer to node_a which is higher up till both nodes become equal.
    int GetLCA(int node_a, int node_b)
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
    for (int i = 2; i <= n ; i++)
    {
        int parent;
        cin >> parent;
        t.AddEdge(parent, i); // -1 shayad bekhad!!!!!
    }
    t.GetParentAndDepth(1,0);
    // cout << "nadomne\n";
    for (int k = 0; k < q; k++)
    {
        int u, v, res = 0;
        cin >> u >> v;
        res = t.GetLCA(u, v);
        cout << res << endl;
    }
    // Root node '1' does not have any parent; so set it to 0
    // t.GetParentAndDepth(1, 0);
    // cout << "LCA of (10, 13) : " << t.GetLCA(10, 13) << endl;
    // cout << "LCA of (7, 5)   : " << t.GetLCA(7, 5) << endl;
    // cout << "LCA of (12, 9)  : " << t.GetLCA(12, 9) << endl;
    // cout << "LCA of (19, 8)  : " << t.GetLCA(19, 8) << endl;
    // cout << "LCA of (17, 18) : " << t.GetLCA(17, 18) << endl;

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