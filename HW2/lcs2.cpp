#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;
int lcs(vector<int> array1, vector<int> array2, int l1, int l2, int l3, vector<vector<int>> &memo)
{
    if (l1 == 0 || l2 == 0 || l3==0)
        return 0;
    if (array1[l1 - 1] == array2[l2 - 1])
        return memo[l1][l2] = 1 + lcs(array1, array2, l1 - 1, l2 - 1, memo);
    else if (memo[l1][l2] == -1)
        return memo[l1][l2] = max(lcs(array1, array2, l1, l2 - 1, memo), lcs(array1, array2, l1 - 1, l2, memo));
    return memo[l1][l2];
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
    
}