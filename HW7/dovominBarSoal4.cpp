
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
bool is_visited[99999];
int capacity[99999];
bool mycomp(int a, int b){
    return capacity[a] < capacity[b];
}
int calculateRes(vector<int> q, vector<bool> visited, int Solidersnum)
{
    int temp_soldiers = Solidersnum;
    
    if (q.empty())
        return Solidersnum;
    int node = q.front();
    q.pop_back();
    // cout << node << endl;
    bool flag =true;
    for (int n:neighbours_vector[node]){
        if (!visited[n]){
            if(flag){
                temp_soldiers = capacity[node];
            }
            visited[n] = true;
            q.push_back(n);
        }
    }
    return calculateRes(q, visited,temp_soldiers);
}

int main()
{
    int v, e;
    cin >> v >> e;

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
    for (int i = 0; i < v; i++)
    {
        sort(neighbours_vector[i ].begin(), neighbours_vector[i ].end(), mycomp);
    }

    int start_node;
     start_node=0 ;
    
    vector<bool> visited(v+1, false);
    vector<int> nodes_vector;
    nodes_vector.push_back(start_node);
    visited[start_node] = true;
    int res = calculateRes( nodes_vector, visited, capacity[start_node]);
    cout<< res;
    return 0;
}

/*
*/