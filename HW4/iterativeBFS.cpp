// Recursive iterativeBFS implementation
// learnt about the problem in https://www.techiedelight.com/breadth-first-search/
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

vector<int> neighbours_vector[99999];

void iterativeBFS( int start_node, int v)
{
    queue<int> q;
    vector<bool> visited(v + 1, false);

    q.push(start_node);
    visited[start_node] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << endl;
        for (int n : neighbours_vector[node])
        {
            if (!visited[n])
            {
                visited[n] = true;
                q.push(n);
            }
        }
    }

}

int main()
{
    int v, e;
    cin >> v >> e;


    int start_node;
    cin >> start_node;

    for (int i = 0; i < e; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        neighbours_vector[node1].push_back(node2);
        neighbours_vector[node2].push_back(node1);
    }
    // queue<int> nodes_queue;
    // nodes_queue.push(start_node);
    // visited[start_node] = true;
    iterativeBFS( start_node, v);
    return 0;
}

/*
Input:
10 10 1
1 8
1 10
8 4
8 7
10 9
4 3
4 5
7 6
9 2
9 3
Output:
1
8
10
4
7
9
3
5
6
2
*/