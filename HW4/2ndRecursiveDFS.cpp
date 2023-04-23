// Recursive DFS implementation
// using Graph DS and idea from https://gist.github.com/smihir031/8c9cb3ed3797ad3668a21ed983aa799c
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

vector<int> neighbours_vector[99999];
bool is_visited[99999];

void DFS(int node)
{
    is_visited[node] = true;
    cout << node << endl;
    for (int n : neighbours_vector[node])
    {
        if (!is_visited[n])
            DFS(n);
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    int start_node;
    cin >> start_node;

    for (int i = 0; i < v; i++)
    {
        is_visited[i + 1] = false;
    }

    for (int i = 0; i < e; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        neighbours_vector[node1].push_back(node2);
        neighbours_vector[node2].push_back(node1);
    }
    DFS(start_node);
    return 0;
}

/*
Input:
4 3
1
1 2
1 3
1 4
Output:
1
2
3
4
*/