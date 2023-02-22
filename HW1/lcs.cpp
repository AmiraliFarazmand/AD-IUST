#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;
/*
Used help from https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/ .
*/
int lcs( vector<int>array1, vector<int> array2, int l1, int l2 )
{
     int tabulate[l1 + 1][l2 + 1];
 
    for(int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 || j == 0)
                tabulate[i][j] = 0;
            else if (array1[i - 1] == array2[j - 1])
                tabulate[i][j] = tabulate[i - 1][j - 1] + 1;
            else
                tabulate[i][j] = max(tabulate[i - 1][j], tabulate[i][j - 1]);
        }
    }
    return tabulate[l1][l2];
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
    cout<<lcs(arr, arr2, len1, len2);
    return 0;
}