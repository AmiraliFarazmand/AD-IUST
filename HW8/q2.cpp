// Maximum matchmaking problem on a bipartite graph
// used chat GPT to solve it
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
using lint = long int;
#define NIL 0
#define INF 1e9

class BipartiteGraph
{
private:
    int M; 
    int N; 
    vector<vector<bool>> graph;

public:
    BipartiteGraph(int n, int m)
    {
        M = m;
        N = n;
        graph.resize(M, vector<bool>(N, false));
    }

    void addEdge(int u, int v)
    {
        graph[u][v] = true;
    }

    bool dfs(int u, vector<bool> &visited, vector<int> &matchNodes)
    {
        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] && !visited[v])
            {
                visited[v] = true;

                if (matchNodes[v] == -1 || dfs(matchNodes[v], visited, matchNodes))
                {
                    matchNodes[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findMaximumMatching()
    {
        vector<int> matchNodes(N, -1);
        vector<bool> visited(N, false);

        for (int u = 0; u < M; u++)
        {
            visited.assign(N, false);
            dfs(u, visited, matchNodes);
        }

        return matchNodes;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    BipartiteGraph matching(n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int value;
            cin >> value;
            if (value == 1)
            {
                matching.addEdge(j, i);
            }
        }
    }

    vector<int> result = matching.findMaximumMatching();

    for (int i = 0; i < n; i++)
    {
        if (result[i] != -1)
        {
            cout << (result[i] + 1) << " ";
        }
        else
        {
            cout << "-1 ";
        }
    }
    cout << endl;

    return 0;
}
/*
Example 1 :
Input :
3 4
1 1 0 1
0 1 0 0
0 0 0 0
Output :
1 2 -1
8
*/