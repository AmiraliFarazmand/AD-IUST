#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <sstream>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;

vector<int> dp(10000, 0);
int counter = 0;
void make_safe(int indx, int n)
{
    for (int i = indx; i < n; i++)
    {
        if (dp[i] == 1)
        {
            break;
        }
        dp[i] = 1;
    }
    if (indx == 1 or indx == 2)
    {
        cout << counter;
        exit(0);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    int pointer = n;
    for (int i = 0; i < k - 1; i++)
    {
        if (pointer % 2 == 0)
            pointer /= 2;
        else
            pointer = pointer / 2 + 1;
        make_safe(pointer, n);
        counter++;
    }
    // int counter=0;
    for (int j = 0; j < n; j++)
    {
        if (dp[j] == 0)
            counter++;
    }
    cout << counter;
}