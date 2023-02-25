//https://codeforces.com/problemset/problem/180/C

#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length(), min_change = 9999999;
    str = str.insert(n, "%");
    str = str.insert(0, "%");
    unsigned int first_smalls[n + 2] = {}, last_caps[n + 2] = {};
    for (int i = 1; i <= n; i++)
    {
        first_smalls[i] = first_smalls[i - 1];
        if (str[i] >= 'a' && str[i] <= 'z')
            first_smalls[i]++;
    }
    for (int i = n; i >= 1; i--)
    {
        last_caps[i] = last_caps[i + 1];
        if (str[i] >= 'A' && str[i] <= 'Z')
            last_caps[i]++;
    }
    for (int i = 1; i <=n; i++){
        if (first_smalls[i]+last_caps[i]<min_change)
            min_change = first_smalls[i]+last_caps[i];
    }
    cout<<min_change-1<<endl;
    for (int i =0;i<n+2;i++)
        cout<<last_caps[i];

    return 0;
}
// PRuvetSTAaYA
// 001234000100
// 210000321021
// // heklkoijijjiojijioj