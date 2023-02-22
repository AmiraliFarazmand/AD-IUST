// Longest Increasing Subsequence
// Used help from GfG
/*
5
21 3 33 4 88
>>>3
*/
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

int lis(int *array, int n)
{
    int lis_memo[n];
    for (int i = 0; i < n; i++)
        lis_memo[i] = 1;

    for (int i = 1; i < n; i++)
    {
        lis_memo[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (array[j] < array[i])
            {
                if (lis_memo[j] + 1 > lis_memo[i])
                {
                    lis_memo[i] = lis_memo[j] + 1;
                }
            }
        }
    }
    long int max = -1000000000;
    for (int i = 0; i < n; i++)
        if (max < lis_memo[i])
            max = lis_memo[i];
    return max;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lis(arr, n);
    return 0;
}