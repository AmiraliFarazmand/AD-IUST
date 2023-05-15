#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lolint;

class Edge {
public:
    int node_start;
    int node_end;
    int weight;
};

bool compWeight(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
private:
    int num_nodes;
    vector<Edge> edgelist;
    vector<int> parent;
    vector<int> rank;

public:
    Graph() {}
    Graph(int num_nodes) {
        this->num_nodes = num_nodes;
        parent.resize(num_nodes);
        rank.resize(num_nodes);
    }

    void AddEdge(Edge e) {
        edgelist.push_back(e);
    }

    int FindParent(int node) {
        if (node != parent[node])
            parent[node] = FindParent(parent[node]);
        return parent[node];
    }

    void Union(int node1, int node2) {
        int root1 = FindParent(node1);
        int root2 = FindParent(node2);
        if (root1 != root2) {
            if (rank[root1] < rank[root2])
                parent[root1] = root2;
            else if (rank[root1] > rank[root2])
                parent[root2] = root1;
            else {
                parent[root1] = root2;
                rank[root2]++;
            }
        }
    }

    lolint KruskalMST(vector<Edge>& result) {
        lolint mst_weight = 0;
        for (int i = 0; i < num_nodes; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        sort(edgelist.begin(), edgelist.end(), compWeight);
        for (Edge e : edgelist) {
            int root1 = FindParent(e.node_start);
            int root2 = FindParent(e.node_end);
            if (root1 != root2) {
                result.push_back(e);
                mst_weight += e.weight;
                Union(root1, root2);
            }
        }
        return mst_weight;
    }

    lolint SecondBestMST() {
        vector<Edge> mst;
        lolint mst_weight = KruskalMST(mst);
        lolint sbmst_weight = INTMAX_MAX;
        for (Edge e : mst) {
            vector<Edge> subgraph;
            for (Edge e2 : edgelist) {
                if (e2.node_start != e.node_start || e2.node_end != e.node_end) {
                    subgraph.push_back(e2);
                }
            }
            vector<Edge> sbmst;
            lolint weight = KruskalMST(sbmst);
            if (sbmst.size() == num_nodes - 1 && weight < sbmst_weight) {
                sbmst_weight = weight;
            }
        }
        return sbmst_weight;
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++) {
        Edge e;
        cin >> e.node_start >> e.node_end >> e.weight;
        e.node_start--;
        e.node_end--;
        g.AddEdge(e);
    }
    lolint sbmst_weight = g.SecondBestMST();
    cout << sbmst_weight << endl;
    return 0;
}