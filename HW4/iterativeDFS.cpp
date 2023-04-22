// Iterative DFS implementation
// Modified code of previous part
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

stack<int> node_stack;
vector<int> neighbours_vector[9999];
bool is_visited[9999];

void IterativeDFS()
{
    while (!node_stack.empty())
    {
        int node = node_stack.top();
        // is_visited[node] = true;
        // cout << node << endl;
        node_stack.pop();
        // cout<<node<<"##\n";
        if (!is_visited[node])
        {
            cout << node << "\n";
            is_visited[node] = true;
        }
        // for (auto i = neighbours_vector[node].begin(); i != neighbours_vector[node].end(); ++i)
        //     if (!is_visited[*i])
        //         node_stack.push(*i);

        for (int n : neighbours_vector[node])
        {
            if (!is_visited[n]){
                node_stack.push(n);
                // cout<< n<<"*\n";
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < v; i++)
    {
        is_visited[i + 1] = false;
    }
    int start_node;
    cin >> start_node;
    node_stack.push(start_node);

    for (int i = 0; i < e; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        neighbours_vector[node1].push_back(node2);
       neighbours_vector[node2].push_back(node1);
    }

    IterativeDFS();
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


5 5
1
2 1
1 3
3 2
1 4
2 5
>>> 1 4 3 2 5


5 4
1
2 1
3 2
4 5
5 1
>>>1 2 3 4 5
*/