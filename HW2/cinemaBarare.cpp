// Cinema Barare problem
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
#define MAX_NUM 999999999
#define NUM 4000
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

int find_min_cost(vector<int> arr, int n, int capacity)
{
    int tmp1 = 0, tmp2 = 0, min_cost = MAX_NUM;
    int memo[2][NUM - 1][NUM];

    for (int i = 0; i <= n; i++)
    {
        memo[0][i][i] = MAX_NUM;
        memo[1][i][i] = MAX_NUM;
    }

    memo[0][0][1] = 0;
    memo[1][0][1] = arr[1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j == 0)
                tmp1 = MAX_NUM;
            else
                tmp1 = memo[0][j - 1][i - 1];

            memo[0][j][i] = min(tmp1, memo[1][j][i - 1] + arr[i]);
            memo[1][j][i] = min(tmp1 + arr[i], memo[1][j][i - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (memo[0][i][n] < min_cost && i + 1 <= capacity && n - i - 1 <= capacity)
        {
            min_cost = memo[0][i][n];
        }
        if (memo[1][i][n] < min_cost && i <= capacity && n - i <= capacity)
        {
            min_cost = memo[1][i][n];
        }
    }
    // cout << min_cost;
    return min_cost;
}

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    vector<int> array(NUM);
    for (int i = 1; i <= n; i++)
        cin >> array[i];
    int res = find_min_cost(array, n, capacity);
    cout << res;
    return 0;
}

/*
Example 1:
Input:
2 1
1000 50
Output:
50
Example 2:
Input:
3 2
50 10 1000
Output:
10
*/