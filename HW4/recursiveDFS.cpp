// Recursive DFS implementation
// using Graph DS from GFG
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

class Graph
{

    void DFSUtil(int v)
    {
        visited[v] = true;
        cout << v << " ";

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i);
    };

public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); 
    };
    void DFS()
    {
        for (auto i : adj)
            if (visited[i.first] == false)
                DFSUtil(i.first);
    };
};

int main()
{
    int e, v;
    cin >> v >> e;

    return 2;
}