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

    int min_stops = 0, current_spot = 0, flag = 0, candidate_stop;

    // while (current_spot < d)
    // {
    int i = 0;
    while (current_spot < d)
    {
        if (current_spot + m > stop[i] & current_spot < stop[i])
        {
            candidate_stop = stop[i];
            flag = 1;
            i++;
        }
        else if (current_spot + m < stop[i + 1])
        {
            current_spot = candidate_stop;
            min_stops += 1;
            // if (flag == 0)
            // {
            //     cout << -1;
            //     return 1;
            // }
            flag = 0;
            i -= 1;
        }
        else
        {
            cout << -1<<'*';
            return 1;
        }
        // else if (current_spot + m < stop[i] && current_spot + m > stop[i+1]  )
        // {
        //     candidate_stop = stop[i];
        //     flag = 1;
        //     cout << -1;
        // }
        // else
        // {
        //     current_spot = candidate_stop;
        //     min_stops += 1;
        //     flag = 0;
        //     candidate_stop = -1;

        // }
    }
    if (current_spot < d)
        cout << -1;
    else
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
*/