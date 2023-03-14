// Hassan's algorithm problem
// Soloution explanation : https://www.geeksforgeeks.org/minimum-cost-of-reducing-array-by-merging-any-adjacent-elements-repetitively/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
#define NUM 128
#define MAX_NUM 99999999
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

long optimal_merges_cost(vector<int> &numbers, int n)
{
    int dist, indx1, indx2, k;

    if (numbers.size() == 0)
    {
        return 0;
    }

    vector<vector<long>> dp_table(NUM, vector<long>(NUM  , MAX_NUM));
    for (int i = 1; i <= n; i++)
        dp_table[i][i] = 0;

    vector<long> prefix_sum(NUM, 0);
    // fill prefix_sum
    for (int indx1 = 1; indx1 <= n; indx1++)
    {
        prefix_sum[indx1] = prefix_sum[indx1 - 1] + numbers[indx1 - 1];
    }

    // Iterate for distance >= 1
    for (dist = 2; dist <= n; dist++)
    {

        for (indx1 = 1; indx1 <= n - dist + 1; indx1++)
        {
            indx2 = indx1 + dist - 1;

            // sum of [indx1 to indx2]
            long sum = prefix_sum[indx2] - prefix_sum[indx1 - 1];

            // find minimum cost
            for (k = indx1; k < indx2; k++)
            {
                dp_table[indx1][indx2] = min(dp_table[indx1][k] + dp_table[k + 1][indx2] + sum, dp_table[indx1][indx2]);
            }
        }
    }

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int indx2 = 0; indx2 < n + 1; indx2++)
    //         cout << setfill('0') << setw(3) << dp_table [i][indx2] << ' ';
    //     cout << endl;
    // }

    return dp_table[1][n];
}
int main()
{
    int k, n, sum = 0;
    cin >> n >> k;

    vector<int> arr(NUM, 0);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    // sort(arr.begin() + 1, arr.end());
    // for (int i =0; i <= n; i++)
    //     cout << arr[i] << endl;
    // vector<int> arr = {16, 4, 6};
    // int n = arr.size();
    cout << optimal_merges_cost(arr, k)<<endl;
    return 0;
}

/*
Example 2:
Input:
7 4
1 1 1 4
Output:
12
Example 3:
Input:
2 2
1 1
Output:
2
Example 4:
Input:
4 3
1 2 1
Output:
7
*/