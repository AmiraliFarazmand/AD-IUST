// Cashe Ziad problem
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<lolint>> Matrix;

int find_min(vector<int> tiles, vector<int> used_tiles, int num_tiles)
{

}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tiles(n);
    vector<int> used_tiles(n, 0);
    for (int i = 0; i < n; i++)
        cin >> tiles[i];
    sort(tiles.begin(), tiles.end());
    find_min(tiles, used_tiles, n);
    
    return 0;
}