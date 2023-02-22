/*
2 5 7 
2 7
>>>2
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;
int lcs(vector<int> array1, vector<int> array2, int l1, int l2, vector<vector<int>> &memo)
{
    if (l1 == 0 || l2 == 0)
        return 0;
    if (array1[l1 - 1] == array2[l2 - 1])
        return memo[l1][l2] = 1 + lcs(array1, array2, l1 - 1, l2 - 1, memo);
    else if (memo[l1][l2] == -1)
        return memo[l1][l2] = max(lcs(array1, array2, l1, l2 - 1, memo), lcs(array1, array2, l1 - 1, l2, memo));
    return memo[l1][l2];
}

int main()
{
    std::vector<int> arr;
    std::vector<int> arr2;

    string temp;
    getline(cin, temp);
    istringstream iss(temp);
    copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(arr));

    getline(cin, temp);
    istringstream iss2(temp);
    copy(std::istream_iterator<int>(iss2), std::istream_iterator<int>(), std::back_inserter(arr2));

    int len1 = arr.size(), len2 = arr2.size();
    vector<vector<int>> memoize(len1 + 1, vector<int>(len2 + 1, -1));
    cout << lcs(arr, arr2, len1, len2, memoize);
    return 0;
}