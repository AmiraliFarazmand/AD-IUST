// Minimum Coin Change problem.
// Used help from GFG.
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

vector<int> nums(100000, -1);

lint find_min(int num, vector<lint> coins, int target)
{
    if (target == 0)
        return 0;
    int temp_min = 1000000;
    for (int i = 0; i < num; i++)
    {
        if (target >= coins[i])
        {
            int remainders_num = find_min(num, coins, target - coins[i]);
            if (remainders_num != 1000000 && remainders_num + 1 < temp_min)
            {
                temp_min = remainders_num + 1;
            }
        }
    }
    return temp_min;
}

int main()
{
    int n, v, len = 0;
    cin >> n >> v;
    vector<lint> coins(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end(), greater<int>());
    // cout << "##";
    lint res = find_min(n, coins, v);
    if (res >= 0)
        cout << res << endl;
    else
        cout << -1 << endl;
    // cout<<-1;
    // cout << "##";
    // for (int i = 0; i < v + 1; i++)
    //     cout << i<<' '<< nums[i] << endl;
}

/*
Input :
3 30
25 5 10
Output:
2


4 37
30
4
3
18
*/