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
    int d, m, n;
    cin >> d >> m >> n;
    int stop[n];
    for (int i = 0; i < n; i++)
        cin >> stop[i];
    int l = 0;
    int i = 0, flag = 0;
    int min_stops = 0;
    while (l < d)
    {
        if (l + m > d)
            break;
        if (l + m > stop[i])
        {
            flag = 1;
            i++;
        }

        else if (flag == 1)
        {
            min_stops += 1;
            flag = 0;
            l = stop[i - 1];
            // i -= 1;
            if (l + m >= d)
                break;
        }
        else if (flag == 0)
        {
            flag = 0;

            cout << -1;
            return 1;
        }
    }

    cout << min_stops;
    return 0;
}

/*
950
400
4
200 375 550 750
>>>2

10
3
4
1 2 5 9
>>>-1

200
250
2
100 150
>>>0
*/