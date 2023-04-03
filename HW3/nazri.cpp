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
    int m, n;
    cin >> m >> n;
    double arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, greater<int>());
    int d = max(n, m + 1);
    Matrix table(arr[0], vector<int>(d, 0)); // Change 0 just in case ...
    int x = 0;
    for (int i = 0; i < arr[0]; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (i == arr[0] - 1)
            {
                if (j < n)
                {

                    if (arr[0] == arr[j])
                    {
                        // cout << "* ";
                        x++;
                    }
                    else
                    {
                        cout << x;
                        return 0;
                    }
                }
            }
            else
            {
                x += 1;
            }
        }
    }

    cout << x ;
    // cout << arr[0] << ' ' << d;
    return 0;
}

/*
Example 2 :
Input:
2
3
2 2 2
Output:
6

Example 1 :
Input:
2
2
3 3
Output:
8

*/