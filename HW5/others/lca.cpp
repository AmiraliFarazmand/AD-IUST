#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> adj;
vector<int> eulerTour, firstAppearance, depth;
vector<vector<int>> sparseTable;


int count_leading_zeros(unsigned int x) {
    int count = 0;
    while (x) {
        x >>= 1;
        count++;
    }
    return sizeof(unsigned int) * 8 - count;
}
void dfs(int u, int p, int& timer) {
    eulerTour.push_back(u);
    firstAppearance[u] = timer++;
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, timer);
            eulerTour.push_back(u);
            timer++;
        }
    }
}
void buildSparseTable() {
    int n = eulerTour.size();
    sparseTable.resize(n, vector<int>(log2(n) + 1));
    for (int i = 0; i < n; i++) {
        sparseTable[i][0] = eulerTour[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            int left = sparseTable[i][j - 1];
            int right = sparseTable[i + (1 << (j - 1))][j - 1];
            if (depth[left] < depth[right]) {
                sparseTable[i][j] = left;
            } else {
                sparseTable[i][j] = right;
            }
        }
    }
}
int query(int u, int v) {
    int left = firstAppearance[u];
    int right = firstAppearance[v];
    if (left > right) {
        swap(left, right);
    }
    int j = 31 - count_leading_zeros(right - left + 1);
    int node1 = sparseTable[left][j];
    int node2 = sparseTable[right - (1 << j) + 1][j];
    if (depth[node1] < depth[node2]) {
        return node1;
    } else {
        return node2;
    }

}

int main() {
    int n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    firstAppearance.resize(n + 1);
    depth.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    int timer = 0;
    dfs(1, 0, timer);
    buildSparseTable();
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        int lca = query(u, v);
        cout << lca << endl;
    }
    return 0;
}
