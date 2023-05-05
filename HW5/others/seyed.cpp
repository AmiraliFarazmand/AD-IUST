#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN = 2e5+10;
vector<long> adj[MAXN];
int start_distances[MAXN];
int end_distances[MAXN];
int max_distances[MAXN];

pair<int,int> farNodes(int start, int n) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int farthest_node = start;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[farthest_node]) {
            farthest_node = i;
        }
    }
    return {dist[farthest_node], farthest_node};
}

void bfs(int start, int n, int choice) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (choice == 1) {
                    start_distances[v] = start_distances[u] + 1;
                } else {
                    end_distances[v] = end_distances[u] + 1;
                }
            }
        }
    }
}

int lower_boundd(int arr[], int n, int x) {
    int l = 0, r = n-1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// void insertionSort(int arr[], int n)
// {
//     int i, key, j;
//     for (i = 1; i < n; i++)
//     {
//         key = arr[i];
//         j = i - 1;
 
//         // Move elements of arr[0..i-1], 
//         // that are greater than key, to one
//         // position ahead of their
//         // current position
//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }
// }

signed main()
{
    int t;
    int n;
    cin >> n;
    int i = 1;
    while(i<=n){
        adj[i].clear();
        i++;
    }
    i = 1;
    while(i<n){
        int u,v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        i++;
    }
    pair<int,int> first_farthest_node = farNodes(1, n);
    pair<int,int> second_farthest_node = farNodes(first_farthest_node.second, n);

    start_distances[first_farthest_node.second] = 0;
    end_distances[second_farthest_node.second] = 0;
    int diameter = second_farthest_node.first;

    bfs(first_farthest_node.second, n, 1);
    bfs(second_farthest_node.second, n, 2);

    int j = 1;
    while(j <= n) {
        max_distances[j] = max(start_distances[j], end_distances[j]);
        j++;
    }

    // insertionSort(max_distances+1, max_distances+1+n);
    sort(max_distances+1, max_distances+1+n);


    i = 1;
    while(i<=n){
        int pos = lower_bound(max_distances+1,max_distances+1+n,i) - max_distances;
        pos=min(pos,n);
        cout << pos << " ";
        i++;
    }
    cout << endl;
    return 0;

}