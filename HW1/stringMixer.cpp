// Solved with using help from https://www.geeksforgeeks.org/find-if-a-string-is-linterleaved-of-two-other-strings-dp-33/
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
// lolint memo[1001][1001];
typedef vector<vector<lolint>> Matrix;
Matrix memo(1001, vector<lolint>(1001, 3));

lolint string_mixer(string s1, string s2, string s3, lolint p1, lolint p2, lolint p3, lolint n1, lolint n2)
{
    // cout << "string_mixer called( " << p1 << " " << p2 << " " << p3 << ")\n";
    if (p1 < n1 && p2 < n2 && memo[p1][p2] != 3)
        return memo[p1][p2];
    if (p1 == n1 && p2 == n2)
        return 1;

    if (s1[p1] == s3[p3] && s2[p2] == s3[p3] && p1 < n1 && p2 < n2)
    {
        lolint go_row = string_mixer(s1, s2, s3, p1 + 1, p2, p3 + 1, n1, n2);
        lolint go_col = string_mixer(s1, s2, s3, p1, p2 + 1, p3 + 1, n1, n2);
        return memo[p1][p2] = go_row || go_col;
    }
    if (p1 < n1 && s1[p1] == s3[p3])
    {
        return memo[p1][p2] = string_mixer(s1, s2, s3, p1 + 1, p2, p3 + 1, n1, n2);
    }
    if (p2 < n2 && s2[p2] == s3[p3])
    {
        return memo[p1][p2] = string_mixer(s1, s2, s3, p1, p2 + 1, p3 + 1, n1, n2);
    }
    return memo[p1][p2] = 0;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    lolint p1 = 0, p2 = 0, p3 = 0;
    if (s3.length() != (s1.length() + s2.length()))
    {
        cout << "False";
        return 1;
    }
    string result = (string_mixer(s1, s2, s3, p1, p2, p3, s1.length(), s2.length()) == 1) ? "True" : "False";

    // for (lolint i = 0; i < 8; i++)
    // {
    //     for (lolint j = 0; j < 8; j++)
    //         cout << memo[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "*****\n";
    // // lolint memo [s1.length()+1][s2.length()+1];
    cout << result;
    return 0;
}