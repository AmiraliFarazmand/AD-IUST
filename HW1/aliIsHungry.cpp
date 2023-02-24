// solved with idea of "assembly line scheduling" problem
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

long int max(long int s1, long int s2)
{
    if (s1 < s2)
        return s2;
    return s1;
}

long int find_max_gain(int n, long int p, long int line1[], long int line2[])
{
    long int gains1[n] = {}, gains2[n] = {};
    gains1[0] = line1[0];
    gains2[0] = line2[0];
    int i; 
    // cout<<gains1[0]<<gains2[0]<<endl;
    for (i = 1; i <n; i++)
    {
        gains1[i] = max(gains1[i - 1] + line1[i], gains2[i - 1] + line1[i] - p);
        gains2[i] = max(gains2[i - 1] + line2[i], gains1[i - 1] + line2[i] - p);
    }
    // cout << endl;
    // for (int i =0; i < n; i++)
    //     cout << gains1[i] << ' ';
    // cout << endl;
    // for (int i =0; i < n; i++)
    //     cout << gains2[i] << ' ';
    // cout << endl;
    return max(gains1[n - 1], gains2[n - 1]);
}

int main()
{
    unsigned int n;
    long int p;
    cin >> n >> p;
    long int line1[n], line2[n];
    for (int i = 0; i < n; i++)
        cin >> line1[i];
    for (int i = 0; i < n; i++)
        cin >> line2[i];
    long int res = find_max_gain(n, p, line1, line2);
    cout << res;
    return 0;
}