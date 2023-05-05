// LCA
//  Used graph DS from techie delight website, and help from chat-gpt 3.5
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
struct Node
{
    vector<int> children;
    int parent;
    int depth;
};

int main()
{
    int n, q;
    cin >> n, q;
    vector<Node> nodes(n + 1);
    nodes[1].parent = 0;
    nodes[1].depth = 0;
    for (int i = 1; i <= q; i++)
    {
        int parent;
        cin >> parent;
        nodes[i].parent = parent;
        nodes[parent].children.push_back(i);
        nodes[i].depth = nodes[parent].depth + 1;
    }
    int u, v;
    cin >> u >> v;
    vector<int> parents1(n + 1, 0), parents2(n + 1, 0);
    for (int i = u; i != 0; i = nodes[i].parent)
    {
        parents1[i] = 1;
    }
    for (int i = v; i != 0; i = nodes[i].parent)
    {
        parents2[i] = 1;
    }
    

    if(nodes[u].depth<nodes[v].depth){
        for(int i=0;i<=n;i++){
            for (int j = n; j)
        }
    }
    return 1;
}