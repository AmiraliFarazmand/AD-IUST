#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

Matrix distance_dp(2, vector<int>(100005, -1));

void recurciveDFS(int node, int i, vector<int> &edges, int d)
{
    distance_dp[i][node] = d;
    if (edges[node] != -1 && distance_dp[i][edges[node]] == -1)
    {
        recurciveDFS(edges[node], i, edges, d + 1);
    }
}

int nearest_node(vector<int> &edges, int node1, int node2 ,int n)
{
    recurciveDFS(node1, 0, edges, 0);
    recurciveDFS(node2, 1, edges, 0);
    int min_distance = INT_MAX;
    int result_id = -1;
    for (int i = 0; i < n; i++)
    {
        if (distance_dp[0][i] == -1 || distance_dp[1][i] == -1)
            continue;
        if (max(distance_dp[0][i], distance_dp[1][i]) < min_distance)
        {
            min_distance = max(distance_dp[0][i], distance_dp[1][i]);
            result_id = i;
        }
    }
    return result_id;
}

int main()
{
    int n;
    cin >> n;
    vector<int> edges(n);

    for (int i = 0; i < n; i++)
    {
        cin >> edges[i];
    }
    int node1, node2;
    cin >> node1;
    cin >> node2;
    int result = nearest_node(edges, node1, node2 , n);
    cout<<result;
    return 0;
}
/*
Input:
4
2 2 3 -1
0
1
Output:
2


Input:
3
1 2 -1
0
2
Output:
2

Input:
7
2 2 3 4 6 4 5
1
6
Output:
4
*/