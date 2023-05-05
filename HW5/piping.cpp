// Piping problem
//  Used chat-gpt 3.5
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;
using namespace std;
const int N = 100000;

 
bool mark[N];
int n, m, a[N], sz, ans;
vector <int> topol;
vector <int> q;
vector <int> vect1[N];
vector <int> vect2[N];
 
void dfs (int u){
    mark[u] = true;
    for (int i : vect2[u]){
        if (!mark[i]){
            dfs (i);
        }
    }
    topol.push_back(u);
}
 
void dfs2 (int u){
    mark[u] = true;
    ++ sz;
    for (int i : vect1[u]){
        if (!mark[i]){
            dfs2 (i);
        }
    }
    return;
}
 
int main(){
    cin >> n >> m;
    for (int i=0;i< m; i++){
        int a, b;
        cin >> a >> b;
        vect2[--a].push_back(--b);
        vect1[a].push_back(b);
        vect1[b].push_back(a);
    }
    for (int i = 0; i < n; ++ i){
        if (!mark[i]){
            dfs (i);
        }
    }
    reverse (topol.begin(), topol.end());
    for (int i = 0; i < topol.size(); ++ i){
        a[topol[i]] = i;
    }
    for (int i = 0; i < topol.size(); ++ i){
        for (int j : vect2[topol[i]]){
            if (a[j] < a[topol[i]]){
                q.push_back(topol[i]);
            }
        }
    }
    fill (mark, mark + n + 1, false);
    for (int i : q){
        if (!mark[i]){
            sz = 0;
            dfs2 (i);
            ans += sz;
        }
    }
    for (int i = 0; i < n; ++ i){
        if (!mark[i]){
            sz = 0;
            dfs2 (i);
            ans += sz - 1;
        }
    }
    cout << ans;
    return 0;
}
 