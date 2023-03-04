#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<lolint>> Matrix;

vector<int> nums(100000, -1);

lint find_min(int num, vector<lint> coins, int n)
{
    // cout<<num<<" called"<<endl;
    if (nums[num] > -1)
    {
        return nums[num];
    }
    if (num == 0)
    {
        return 0;
    }

        lint min_nums = 10000000;
    for (int i = 0; i < n; i++)
    {
        lint temp = 10000000;
        // cout << "?";
        if (num >= coins[i])
        {
            lint temp2 = find_min(num % coins[i], coins, n);
            // lint temp3 = find_min(num / coins[i], coins, n);
            if ( temp2 != -2)
                temp = floor(num / coins[i])+temp2;
            else
                temp =10000000;
        }
        if (temp < min_nums)
            min_nums = temp;
    }
    if (min_nums != 10000000)   
        return nums[num] =min_nums ;//( min_nums ? (min_nums != 10000000) : 0);
    else return nums[num] =  -2 ;
}

int main()
{
    int n, v, len = 0;
    cin >> n >> v;
    vector<lint> coins(n, 0);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end(), greater<int>());
    // cout << "##";
    lint res = find_min(v, coins, n);
    if (res>=0)
        cout << res<< endl;
    else cout << -1<< endl;
    // cout<<-1;
    // cout << "##";
    // for (int i = 0; i < v + 1; i++)
    //     cout << i<<' '<< nums[i] << endl;
}

/*
Input :
3 30
25 5 10
Output:
2


4 37
30
4
3
18
*/