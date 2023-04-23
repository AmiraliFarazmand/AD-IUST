#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs_iterative(vector<vector<int>>& adj_list, int start_node) {
    vector<bool> visited(adj_list.size(), false);
    stack<int> stack;
    stack.push(start_node);
 
    while (!stack.empty()) {
        int curr_node = stack.top();
        stack.pop();
            cout << curr_node << "\n";
 
        if (!visited[curr_node]) {
            visited[curr_node] = true;
        }
 
        for (int neighbor : adj_list[curr_node]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
            }
        }
    }
}

int main() {
    int v, e,start;
    // cout << "Enter the number of vertices: ";
    cin >> v;
    // cout << "Enter the number of edges: ";
    cin >> e>>start;

    vector<vector<int>> adj_list(v);
    // cout << "Enter the edges as pairs of integers (e.g. '0 1' for an edge between nodes 0 and 1):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
 
    // cout << "DFS starting from node 0: ";
    dfs_iterative(adj_list, start);
 
    return 0;
}