// Longest Increasing Subarray in order of n.log n
// Implemented using help from leetcode:(https://leetcode.com/problems/longest-increasing-subsequence/solutions/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation/)

#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> array)
{
    int sz = array.size();
    int len = 0;
    vector<int> tails(sz, 0);
    for (int indx = 0; indx < sz; indx++)
    {
        int i = 0, j = len;
        while (i < j)
        {
            int m = (i + j) / 2;
            if (tails[m] < array[indx])
                i = m + 1;
            else
                j = m;
        }
        tails[i] = array[indx];
        len = max(i+1 , len);
    }
    return len;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lis(arr);
    return 0;
}
/*
5
2 7 4 3 8

*/