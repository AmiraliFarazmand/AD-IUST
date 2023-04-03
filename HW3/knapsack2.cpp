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

typedef struct item
{
    int price;
    int weight;
    double value;
} item;

static bool comp(item a, item b)
{
    return a.value >b.value;
}
int main()
{
    int cap, n;
    double temp1, temp2, temp3;
    cin >> cap >> n;
    float prices[n] = {0};
    float weights[n] = {0};
    float values[n] = {0.0};
    item itemarr[n];
    item temp_item ;
    for (int i = 0; i < n; i++)
        cin >> itemarr[i].price;
    for (int i = 0; i < n; i++)
        cin >> itemarr[i].weight;

    for (int i = 0; i < n; i++)
        itemarr[i].value = itemarr[i].price / itemarr[i].weight;

    // for (int i = 0; i < n; i++)
    //     cout << values[i] << ' ' << prices[i]<<'|';

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (itemarr[i].value < itemarr[j].value | (itemarr[i].value == itemarr[j].value & itemarr[i].price > itemarr[j].price))
    //         {
    //             temp_item = itemarr[j];
    //             itemarr[j] = itemarr[i];
    //             itemarr[i] = temp_item;
    //         }
    //     }
    // }
    sort(itemarr , itemarr+n , comp);
    double max_gain = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (cap > itemarr[i].weight)
        {
            max_gain +=(double) itemarr[i].price;
            cap -= itemarr[i].weight;
        }
        else if (cap > 0)
        {
            max_gain += ((double)itemarr[i].price * ((double)cap /(double) itemarr[i].weight));
            cap = 0;
            // cout<<'$'<<(itemarr[i].price * (cap / itemarr[i].weight))<<endl;
        }
        // if(cap == 0)
        //     break;
        // cout << max_gain << ' ' << cap << '*' << endl;
    }
    // max_gain = ((lint)(max_gain* 100 + .5) / 100.0);
    cout << fixed << setprecision(2) << max_gain;

    // for (int i = 0; i < n; i++)
    //     cout << values[i] << ' ' << itemarr[i].price << '|';

    // for (int i = 0; i < n; i++)
    //     cout << itemarr[i].weight << ' ' << itemarr[i].price<<'|';

    return 0;
}

/*
50 3
60 100 120
10 20 30
Output:
240


Input:
15 7
10 5 15 7 6 18 3
2 3 5 7 1 4 1
Output:
55.33

*/