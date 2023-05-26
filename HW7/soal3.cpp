// problem No.3
// https://leetcode.com/problems/network-delay-time/
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

class node
{
public:
    int weight;
    int id;
    node(int weight, int id)
    {
        this->weight = weight;
        this->id = id;
    }
};

class myComp
{
public:
    bool operator()(node &a, node &b)
    {
        return a.weight > b.weight;
    }
};

int networkDelayTime(vector<vector<int>> &times, int N, int K)
{
    vector<vector<node>> g(N + 1);
    vector<bool> visit(N + 1, false);
    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;

    for (int i = 0; i < times.size(); i++)
    {
        node neiborNode = node(times[i][2], times[i][1]);
        g[times[i][0]].push_back(neiborNode);
    }

    priority_queue<node, vector<node>, myComp> q;
    q.push(node(0, K));

    while (!q.empty())
    {
        node top = q.top();
        q.pop();
        int closestNode = top.id;
        visit[closestNode] = true;

        for (int i = 0; i < g[closestNode].size(); i++)
        {

            int neiborNode = g[closestNode][i].id;
            int neiborWeight = g[closestNode][i].weight;

            if (visit[neiborNode] == false && dist[neiborNode] > dist[closestNode] + neiborWeight)
            {
                dist[neiborNode] = dist[closestNode] + neiborWeight;
                q.push(node(dist[neiborNode], neiborNode));
            }
        }
    }

    int ans = 0;

    for (int i = 1; i < dist.size(); i++)
    {
        ans = max(ans, dist[i]);
    }

    if (ans == INT_MAX)
        return -1;

    return ans;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> times(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    int result = networkDelayTime(times, n, k);
    cout << result << endl;

    return 0;
}
/*
Example 1 :
Input :
2 3 4
1 1 2
1 3 2
1 4 3
Output :
2
Example 2 :
Input :
2 1 2
1 2 1
Output :
-1

*/