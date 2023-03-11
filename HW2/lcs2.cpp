// LCS problem for 3 arrays:
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

int find_max_in_3(int a, int b, int c)
{
    if (a >= b)
    {
        if (a >= c)
            return a;
        else
            return c;
    }
    if (b >= c)
        return b;
    return c;
}
int lcs(vector<int> array1, vector<int> array2, vector<int> array3, int l1, int l2, int l3, vector<vector<vector<int>>> &memo)
{
    if (l1 == 0 || l2 == 0 || l3 == 0)
        return 0;
    
    if (array1[l1 - 1] == array2[l2 - 1] && array1[l1 - 1] == array3[l3 - 1])
        return memo[l1][l2][l3] = 1 + lcs(array1, array2, array3, l1 - 1, l2 - 1, l3 - 1, memo);

    else if (memo[l1][l2][l3] == -1)
        return memo[l1][l2][l3] = find_max_in_3(lcs(array1, array2, array3, l1 - 1, l2, l3, memo),
                                                lcs(array1, array2, array3, l1, l2 - 1, l3, memo),
                                                lcs(array1, array2, array3, l1, l2, l3 - 1, memo));

    return memo[l1][l2][l3]; // whhen memo is not -1
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr1(n);
    vector<int> arr2(m);
    vector<int> arr3(k);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    for (int i = 0; i < k; i++)
        cin >> arr3[i];
    vector<vector<vector<int>>> memoize(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    cout << lcs(arr1, arr2, arr3, n, m, k, memoize);
}
/*
5 5 7
1 2 3 4 5
5 4 3 2 1
5 4 3 2 1 6 7
>>>1


5 5 7
1 2 3 4 5
5 4 3 4 1
5 4 3 2 4 6 7
>>>2
*/