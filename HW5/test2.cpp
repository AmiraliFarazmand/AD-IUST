#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Tree{

    private:
        list<int> *adjlist;
        vector<int> parentlist;
        vector<bool> visited;
        vector<int> depth;

    public:
        Tree() {
        }

        Tree (int nodes) {
            adjlist = new list<int> [nodes+1];
            parentlist.resize(nodes+1);
            visited.resize(nodes+1);
            depth.resize(nodes+1);
            depth[0] = -1; // Hypothetical parent of root(1) is '0' at depth -1
        }

        ~Tree() {
            delete [] adjlist;
        }

        void AddEdge(int src, int dst) {
            adjlist[src].push_back(dst);
            adjlist[dst].push_back(src);
        }

        // Get parent of every node and find its depth
        void GetParentAndDepth(int node, int parent) {

             depth[node] = depth[parent] + 1;

             for(auto& v : adjlist[node]) {
                 if (v != parent) {
                    parentlist[v] = node;
                    GetParentAndDepth(v, node);
                 }
             }
        }

        // Consider node_b at greater depth. Move node_b a level closer to node_a which is higher up till both nodes become equal.
        int GetLCA(int node_a, int node_b) {

            while (node_a != node_b) {
                if (depth[node_a] > depth[node_b]) {
                    swap(node_a, node_b);
                }
                node_b = parentlist[node_b];
            }
            return node_a;
        }
};

int main(){

    Tree t(20);

    t.AddEdge(1, 2);
    t.AddEdge(1, 3);
    t.AddEdge(1, 4);
    t.AddEdge(2, 5);
    t.AddEdge(2, 6);
    t.AddEdge(2, 7);
    t.AddEdge(4, 8);
    t.AddEdge(4, 9);
    t.AddEdge(5, 10);
    t.AddEdge(8, 12);
    t.AddEdge(8, 19);
    t.AddEdge(9, 16);
    t.AddEdge(10, 11);
    t.AddEdge(12, 13);
    t.AddEdge(12, 14);
    t.AddEdge(12, 15);
    t.AddEdge(13, 20);
    t.AddEdge(16, 17);
    t.AddEdge(16, 18);

    // Root node '1' does not have any parent; so set it to 0
    t.GetParentAndDepth(1, 0);
    cout << "LCA of (10, 13) : " << t.GetLCA(10, 13) << endl;
    cout << "LCA of (7, 5)   : " << t.GetLCA(7, 5) << endl;
    cout << "LCA of (12, 9)  : " << t.GetLCA(12, 9) << endl;
    cout << "LCA of (19, 8)  : " << t.GetLCA(19, 8) << endl;
    cout << "LCA of (17, 18) : " << t.GetLCA(17, 18) << endl;

    return 0;
}