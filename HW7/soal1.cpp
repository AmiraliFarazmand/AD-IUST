#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dist[10005], V, E, parent[10005];
vector<int> smallest_cycle;
template<typename T>

void removeDuplicates(std::vector<T>& vec)
{
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
struct Edge
{
    int from, to, weight;
};

vector<Edge> edges;

bool bellman_ford()
{
    bool negative_cycle = false;
    // Initialize distances, parent pointers, and last relaxed vertex for each source vertex
    for (int source = 1; source <= V; source++)
    {
        fill(dist, dist + V + 1, INF);
        dist[source] = 0;
        fill(parent, parent + V + 1, -1);
        int last_relaxed;
        // Relax all edges V-1 times
        for (int i = 1; i < V; i++)
        {
            last_relaxed = -1;
            for (Edge e : edges)
            {
                int u = e.from, v = e.to, w = e.weight;
                // If we can improve the distance to vertex v through vertex u, update it
                if (dist[u] != INF && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    last_relaxed = v;
                }
            }
            // If no edges were relaxed in the previous iteration, we can stop early
            if (last_relaxed == -1)
            {
                break;
            }
        }
        // If we relaxed an edge during the V-1th iteration, there is a negative cycle
        if (last_relaxed != -1)
        {
            negative_cycle = true;
            vector<int> cycle;
            int x = last_relaxed, visited[V + 1] = {false};
            // Traverse parent pointers to find the nodes in the negative cycle
            while (!visited[x])
            {
                cycle.push_back(x);
                visited[x] = true;
                x = parent[x];
            }
            cycle.push_back(x);
            reverse(cycle.begin(), cycle.end());
            // Print the nodes in the negative cycle if it is the smallest one found so far
            if (cycle.size() < smallest_cycle.size() || smallest_cycle.empty())
            {
                smallest_cycle = cycle;
            }
        }
    }
    // Print the smallest negative cycle found
    if (!smallest_cycle.empty())
    {
        // int min_node = min(smallest_cycle.begin(), smallest_cycle.end()) ;
        // sort(smallest_cycle.begin(), smallest_cycle.end());
        // smallest_cycle.erase(unique(smallest_cycle.begin(), smallest_cycle.end()), smallest_cycle.end());
        // set<int> s(smallest_cycle.begin(), smallest_cycle.end());
        // removeDuplicates<int>(smallest_cycle);
        // smallest_cycle.assign(s.begin(), s.end());
        // cout << "Smallest negative cycle found: ";
        // vector<int > smallest_cycle_new = reverse(smallest_cycle.begin(), smallest_cycle.end());
        int minIdx = min_element(smallest_cycle.begin(), smallest_cycle.end()) - smallest_cycle.begin();
        // for (int node : smallest_cycle) {
        // for(int i = smallest_cycle.size();i>=0 ;i++){
        vector<bool> isvisited(101, 0);
        int i = minIdx;
        for (int j = 0; j < smallest_cycle.size(); j++)
        {
            // cout<< node<<' ';
            if(isvisited[smallest_cycle[i]] == 0){
            cout << smallest_cycle[i] << " ";
            isvisited[smallest_cycle[i]] = 1;
            }

            i = (i + 1) % smallest_cycle.size();
        }
        // cout <<smallest_cycle[0];
        cout << smallest_cycle[minIdx];
    }
    else
    {
        // cout << "No negative cycle found" << endl;
    }
    return negative_cycle;
}

int main()
{
    // Read in the input
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    // Run the Bellman-Ford algorithm and print the result
    if (!bellman_ford())
    {
        cout << "-1";
    }
    return 0;
}

/*
Example 1 :
Input :
5 5
0 1 2
1 2 3
2 3 4
3 4 5
4 1 -13
Output :
1 2 3 4 1


Example 2 :
Input :
5 5
0 1 2
1 2 3
2 3 4
3 4 5
4 1 1
Output :
-1


5 6
1 2 1
2 3 2
3 1 -10
1 4 5
4 5 6
5 3 -10
>>>1 4 5 3 1


8 13
0 1 -10
1 2 -10
2 3 -10
0 7 -20
1 6 -10
2 5 -30
2 6 -9
5 3 1
3 4 -20
4 6 6
7 6 -10
6 5 4
5 4 5
>>>3 4 6 5 3

9 14
5 0 -2
0 1 1
1 2 2
2 3 8
1 4 8
3 4 0
4 5 1
5 6 2
4 7 0
8 3 5
7 8 5
6 7 -3
0 6 1
6 5 0
>>>0 6 5 0
*/