// Knapsack problem.
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
    lint cap, n, temp1, temp2, temp3;
    cin >> cap >> n;
    float prices[n] = {0};
    float weights[n] = {0};
    float values[n] = {0.0};
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    for (int i = 0; i < n; i++)
        values[i] = prices[i] / weights[i];

    // for (int i = 0; i < n; i++)
    //     cout << values[i] << ' ' << prices[i]<<'|';

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (values[i] < values[j] | (values[i]==values[j]&prices[i]>prices[j]))
            {
                temp1 = prices[i];
                temp2 = weights[i];
                temp3 = values[i];
                prices[i] = prices[j];
                weights[i] = weights[j];
                values[i] = values[j];
                prices[j] = temp1;
                weights[j] = temp2;
                values[j] = temp3;
            }
        }
    }

    double max_gain = 0;
    for (int i = 0; i < n; i++)
    {
        if (cap > weights[i])
        {
            max_gain += prices[i];
            cap -= weights[i];
        }
        else if (cap > 0)
        {
            max_gain += (prices[i] * (cap / weights[i]));
            cap = 0;
            // cout<<'$'<<(prices[i] * (cap / weights[i]))<<endl;
        }
        // if(cap == 0)
        //     break;
        // cout << max_gain << ' ' << cap << '*' << endl;
    }
    // max_gain = ((lint)(max_gain* 100 + .5) / 100.0); 
    cout << fixed << setprecision(2) << max_gain;

    // for (int i = 0; i < n; i++)
    //     cout << values[i] << ' ' << prices[i] << '|';

    // for (int i = 0; i < n; i++)
    //     cout << weights[i] << ' ' << prices[i]<<'|';

    return 0;
}