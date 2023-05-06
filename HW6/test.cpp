#include<iostream>
#include<vector>
#include<algorithm>

class Edge {

    public:

    int node_start;
    int node_end;
    int weight;
    Edge(){}
    Edge(int node1, int node2, int wt): node_start(node1), node_end(node2), weight(wt){}
};

bool CompareCost (const Edge a, const Edge b) {
     return a.weight < b.weight;
}

class Graph{

    private:
    int num_nodes;
    std :: vector<Edge> edgelist; // edgelist will store the edges of minimum spanning tree
    std :: vector<int> parent;
    std :: vector<int> rank;

    public:
    Graph(){}
    Graph (int num_nodes)
    {
        this->num_nodes = num_nodes;
        parent.resize(num_nodes);
        rank.resize(num_nodes);
    }

    void AddEdge(Edge e);
    int FindParent(int node);
    void KruskalMST(std :: vector<Edge>&);
    void DisplayEdges(std :: vector<Edge>&);
};

void Graph :: AddEdge (Edge e) {
    edgelist.push_back(e);
}

int Graph :: FindParent (int node) {

    // With path compression
    if ( node != parent[node] )
        parent[node] = FindParent(parent[node]);
     return parent[node];

    /* Without path compression
    if ( node == parent[node] )
        return node;
     return FindParent(parent[node]); */
}

void Graph :: DisplayEdges (std :: vector<Edge>& mst) {

    int cost = 0;
    std :: cout << "Edges of minimum spanning tree : ";
    for (auto& e : mst) {
        std :: cout << "[" << e.node_start << "-" << e.node_end << "](" << e.weight << ") ";
        cost += e.weight;
    }
    std :: cout << "\nCost of minimum spanning tree : " << cost << std :: endl;
}

//Funtion implements Kruskal's algorithm and finds the minimum spanning tree.
void Graph :: KruskalMST (std :: vector<Edge>& result) {

    for (int i=0; i<num_nodes; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    // Sort the edges based on their weights
    sort(edgelist.begin(), edgelist.end(), CompareCost);

    // Apply union-by-rank technique to find the minimum spanning tree.
    for (auto& e : edgelist) {
        int root1 = FindParent(e.node_start);
        int root2 = FindParent(e.node_end);

        if (root1 != root2) {
           result.push_back(e);
           if (rank[root1] < rank[root2]) {
              parent[root1] = root2;
              rank[root2]++;
           } else {
              parent[root2] = root1;
              rank[root1]++;
           }
        }
    }
}

int main() {

    int num_nodes = 6; // Nodes (0, 1, 2, 3, 4, 5)

    Edge e1(0, 1, 4);
    Edge e2(0, 2, 1);
    Edge e3(0, 3, 5);
    Edge e4(1, 3, 2);
    Edge e5(1, 4, 3);
    Edge e6(1, 5, 3);
    Edge e7(2, 3, 2);
    Edge e8(2, 4, 8);
    Edge e9(3, 4, 1);
    Edge e10(4, 5, 3);

    Graph g1(num_nodes);
    g1.AddEdge(e1);
    g1.AddEdge(e2);
    g1.AddEdge(e3);
    g1.AddEdge(e4);
    g1.AddEdge(e5);
    g1.AddEdge(e6);
    g1.AddEdge(e7);
    g1.AddEdge(e8);
    g1.AddEdge(e9);
    g1.AddEdge(e10);

    std :: vector<Edge> mst; // mst will contain the minimum spanning tree
    g1.KruskalMST(mst);
    g1.DisplayEdges(mst);

    num_nodes = 7;

    Edge a(0, 1, 1);
    Edge b(0, 2, 2);
    Edge c(0, 3, 1);
    Edge d(0, 4, 1);
    Edge e(0, 5, 2);
    Edge f(0, 6, 1);
    Edge g(1, 2, 2);
    Edge h(1, 6, 2);
    Edge i(2, 3, 1);
    Edge j(3, 4, 2);
    Edge k(4, 5, 2);
    Edge l(5, 6, 1);

    Graph g2(num_nodes);
    g2.AddEdge(a);
    g2.AddEdge(b);
    g2.AddEdge(c);
    g2.AddEdge(d);
    g2.AddEdge(e);
    g2.AddEdge(f);
    g2.AddEdge(g);
    g2.AddEdge(h);
    g2.AddEdge(i);
    g2.AddEdge(j);
    g2.AddEdge(k);
    g2.AddEdge(l);

    mst.clear();
    g2.KruskalMST(mst);
    g1.DisplayEdges(mst);

    return 0;
}