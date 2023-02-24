// solved with idea of "assembly line scheduling" problem
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

double find_max_gain(int n, double line1[], double line2[], int p)
{
    double gains1[n] = {}, gains2[n] = {};
    gains1[0] = line1[0];
    gains2[0] = line2[0];
    for (int i = 1; i < n; i++)
    {
        gains1[i] = max(gains1[i - 1] + line1[i], gains2[i - 1] - p + line1[i]);
        gains2[i] = max(gains2[i - 1] + line2[i], gains1[i - 1] - p + line2[i]);
    }
    return max(gains1[n - 1], gains2[n - 1]);
}

int main()
{
    int n, p;
    cin >> n >> p;
    double line1[n], line2[n];
    for (int i = 0; i < n; i++)
        cin >> line1[i];
    for (int i = 0; i < n; i++)
        cin >> line2[i];
    int res = find_max_gain(n, line1, line2, p);
    cout << res;
    return 0;
}