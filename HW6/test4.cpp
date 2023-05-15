// SBMST problem
// used code from problem No.2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

typedef long long int lolint;

class Edge {
public:
    int node_start;
    int node_end;
    int weight;
};

class Graph {
private:
    int num_nodes;
    vector<Edge> edgelist;

public:
    Graph() {}
    Graph(int num_nodes) {
        this->num_nodes = num_nodes;
    }

    void AddEdge(Edge e) {
        edgelist.push_back(e);
    }

    lolint KruskalMST() {
        vector<int> parent(num_nodes);
        vector<int> rank(num_nodes);
        for (int i = 0; i < num_nodes; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        sort(edgelist.begin(), edgelist.end(), [](const Edge& a, const Edge& b) { return a.weight < b.weight; });
        lolint mst_weight = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (Edge e : edgelist) {
            int root1 = FindParent(e.node_start, parent);
            int root2 = FindParent(e.node_end, parent);
            if (root1 != root2) {
                mst_weight += e.weight;
                parent[root1] = root2;
                rank[root2] += rank[root1] == rank[root2];
                pq.push(make_pair(e.node_start, e.node_end));
            }
        }
        lolint sbmst_weight = numeric_limits<lolint>::max();
        while (!pq.empty()) {
            const pair<int, int>& edge = pq.top();
            pq.pop();
            vector<Edge> subgraph;
            for (Edge e : edgelist) {
                if ((e.node_start != edge.first || e.node_end != edge.second) &&
                    (e.node_start != edge.second || e.node_end != edge.first)) {
                    subgraph.push_back(e);
                }
            }
            vector<int> subgraph_parent(num_nodes);
            vector<int> subgraph_rank(num_nodes);
            for (int i = 0; i < num_nodes; i++) {
                subgraph_parent[i] = i;
                subgraph_rank[i] = 0;
            }
            lolint weight = 0;
            for (Edge e : subgraph) {
                int root1 = FindParent(e.node_start, subgraph_parent);
                int root2 = FindParent(e.node_end, subgraph_parent);
                if (root1 != root2) {
                    weight += e.weight;
                    subgraph_parent[root1] = root2;
                    subgraph_rank[root2] += subgraph_rank[root1] == subgraph_rank[root2];
                }
            }
            if (weight < sbmst_weight && CountComponents(subgraph_parent) == 1) {
                sbmst_weight = weight;
            }
        }
        return sbmst_weight == numeric_limits<lolint>::max() ? -1 : sbmst_weight;
    }

    int FindParent(int node, vector<int>& parent) {
        if (node != parent[node]) {
            parent[node] = FindParent(parent[node], parent);
        }
        return parent[node];
    }

    int CountComponents(vector<int>& parent) {
        int count = 0;
        for (int i = 0; i < num_nodes; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
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
    lolint sbmst_weight = g.KruskalMST();
    cout << sbmst_weight << endl;
    return 0;
}