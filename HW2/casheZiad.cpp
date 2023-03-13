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
typedef vector<vector<int>> Matrix;

int find_min(vector<int> tiles, int target, int num_tiles)
{
    Matrix memo(num_tiles + 1, vector<int>(target + 1, 1000000000));
    memo[0][0] = 0;

    for (int i = 1; i < num_tiles + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            int coin_value = tiles[i - 1];
            for (int k = 0; k <= coin_value; k++)
            {
                int temp = 1000000000;
                if (j >= (k * k))
                    temp = memo[i - 1][j - k * k] + pow((coin_value - k), 2);
                memo[i][j] = min(memo[i][j], temp);
            }
        }
    }

    // for (int i = 0; i < num_tiles + 1; i++)
    // {
    //     for (int j = 0; j < target + 1; j++)
    //         cout<<setfill('0')<<setw(7)<< memo[i][j] << ' ';
    //     cout << endl;
    // }

    if (memo[num_tiles][target] == 1000000000)
        return -1;
    return memo[num_tiles][target];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> tiles(n);
    vector<int> used_tiles(n, 0);
    for (int i = 0; i < n; i++)
        cin >> tiles[i];
    // sort(tiles.begin(), tiles.end(), greater<int>());
    int result = find_min(tiles, m, n);
    cout << result;
    return 0;
}

/*
3 6
3
3
1
>>>5
*/