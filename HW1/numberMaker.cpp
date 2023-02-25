// Coin change Permutations problem:
// Useful links:
//  https://cppsecrets.com/users/101611099712197110107114971065149535048484864103109971051084699111109/C00-The-Coin-Change-Permutation-Problem-.php
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;
// int memo[100000];
vector< unsigned int> memo(100000, 0);
unsigned int coin_change(int target, int n, int nums[])
{
    // cout<<"called func for( "<<target<<" )\n";
    // if (memo[target] != 0)
    // {
    //     return memo[target];
    // }
    // if (target == 0)
    //     return 1;
    // int flag = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (nums[i] < target)
    //     {
    //         flag =1;
    //         int x = coin_change(target-nums[i], n, nums);
    //         // if (x != -1)
    //             memo[target] += x;
    //     }
    // }
    // // if (flag == 1)
    // //     return memo[target];
    // if (flag == 0)
    //     return 0;

    memo[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[j] <= i)
            {
                // cout<<" i: "<<i<<" nums[j]: "<<nums[j]<<endl;
                memo[i] += memo[i - nums[j]];
            }
        }
    }
    return memo[target];
}

int main()
{
    int n;
    cin >> n;
    int numbs[n];
    for (int i = 0; i < n; i++)
        cin >> numbs[i];
    int target;
    cin >> target;
    // for (int i=0; i<100000; i++)
    //     memo[i]= -1
    unsigned int res = coin_change(target, n, numbs);
    // cout <<res<<' '<<memo[target]<<endl;
    // for (int i=0; i<10; i++)
    //     cout <<i<<":"<<memo[i]<<"  ";
    if (res != 0)
        cout << res;
    else    
        cout <<"Empty";
    return 0;
}