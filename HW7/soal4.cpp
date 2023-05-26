// Problem No.4
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

vector<int> adjList[9999];
bool visited[9999];
lint weight[9999];

void findResForNode(int v, int n)
{
    lint power = weight[v], res = 0;

    for (int i = 0; i < n; i++)
        visited[i] = false;
    visited[v] = true;

    set<pair<int, int>> neighbor;
    for (int u : adjList[v])
        if (!visited[u])
            neighbor.insert(make_pair(weight[u], u));

    for (int i = 0; i < n - 1; i++)
    {
        int u = (*neighbor.begin()).second;
        neighbor.erase(neighbor.begin());

        visited[u] = true;
        for (int w : adjList[u])
            if (!visited[w])
                neighbor.insert(make_pair(weight[w], w));

        if (weight[u] < power + res)
            power += weight[u];
        else
        {
            res += weight[u] - (power + res) + 1;
            power += weight[u];
        }
    }

    cout << res << " ";
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[v - 1].push_back(u - 1);
        adjList[u - 1].push_back(v - 1);
    }

    for (int v = 0; v < n; v++)
        findResForNode(v, n);

    return 0;
}

/*
Input :
7 10
16 1 32 256 4 128 64
2 6
6 7
1 2
3 7
5 4
7 5
6 2
4 2
4 6
6 3
Output :
112 112 33 0 61 12 29

Input :
3 2
1 2 3
1 2
2 3
Output :
2 1 0
*/