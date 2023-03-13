// Hassan's algorithm problem
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

int main()
{
    int k, n,sum = 0;
    cin >> n >> k;

    vector<int> arr(k + 1, 0);
    for (int i = 1; i <= k; i++)
        cin >> arr[i];
    sort(arr.begin() + 1, arr.end());
    for (int i = 1; i <= k; i++)
    {
        arr[i] = arr[i - 1] + arr[i];
        sum += arr[i];
    }
    // for (int i =0; i <= k; i++)
    //     cout << arr[i] << endl;
    cout << sum << endl;
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