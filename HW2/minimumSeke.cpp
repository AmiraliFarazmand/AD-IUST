// Minimum number of coins that make a given value.
// Solved by using help from GFG.
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
#define NUM 1000000
vector<int> nums(NUM, NUM);

lint find_min(int target, vector<lint> coins, int n)
{
    nums[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
            int remainders_min = nums[i - coins[j]];
            if (remainders_min != NUM)
                if (remainders_min +1< nums[i])
                    nums[i] = remainders_min+1;
            }
        }
    }
    return nums[target];
}

int main()
{
    int n, v, len = 0;
    cin >> n >> v;
    vector<lint> coins(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end(), greater<int>());
    lint res = find_min(v, coins, n);
    if (res >= 0 && res!= NUM)
        cout << res << endl;
    else
        cout << -1 << endl;
    // cout<<-1;
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