#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define N 3010
using namespace std;

int dp[2][N - 1][N];
int cost[N];
int n;
int b;
int32_t main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    for (int i = 0; i <= n; i++)
    {
        dp[0][i][i] = INT32_MAX;
        dp[1][i][i] = INT32_MAX;
    }

    // exit(1);

    dp[0][0][1] = 0;
    dp[1][0][1] = cost[1];
    for (int i = 2; i <= n; i++)
    {
        for (int k = 0; k < i; k++)
        {
            dp[0][k][i] = min(dp[1][k][i - 1] + cost[i], k == 0 ? INT32_MAX : dp[0][k - 1][i - 1]);
            dp[1][k][i] = min(k == 0 ? INT32_MAX : dp[0][k - 1][i - 1] + cost[i], dp[1][k][i - 1]);
        }
    }

    int min = INT32_MAX;
    for (int k = 0; k < n; k++)
    {
        if (dp[0][k][n] < min && k + 1 <= b && n - k - 1 <= b)
        {
            min = dp[0][k][n];
        }
        if (dp[1][k][n] < min && k <= b && n - k <= b)
        {
            min = dp[1][k][n];
        }
    }

    cout << min;

    return 0;
}