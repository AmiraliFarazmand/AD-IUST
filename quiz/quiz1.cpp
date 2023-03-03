// Solution for https://www.geeksforgeeks.org/queries-for-number-of-distinct-elements-from-a-given-index-till-last-index-in-an-array/
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

int n;
int output_nums[1000000] = {0};

int find_outputs(int a_arr[], int min_elm, int target)
{
    int counter = 0;

    vector<int> seen_nums(1000000, -1);
    for (int i = target; i >= min_elm; i--)
    {
        if (seen_nums[a_arr[i]] != -1)
        { // found
            output_nums[i] = counter;
        }
        else
        {
            counter++;
            seen_nums[a_arr[i]] = 9;
            output_nums[i] = counter;
        }
    }
    return 0;
}

int main()
{
    int m;
    cin >> n >> m;
    int a_arr[n + 1];
    vector<int> i_arr(m);
    for (int i = 1; i < n + 1; i++)
        cin >> a_arr[i];

    for (int i = 0; i < m; i++)
        cin >> i_arr[i];
    int min_i = *min_element(i_arr.begin(), i_arr.end());
    int temp = find_outputs(a_arr, min_i, n);

    for (int i = 0; i < m; i++)
        cout << output_nums[i_arr[i]] << endl;

    return 0;
}
/*
10 10
1
2
3
4
1
2
3
4
100000
999999
1
2
3
4
5
6
7
8
9
10




*/