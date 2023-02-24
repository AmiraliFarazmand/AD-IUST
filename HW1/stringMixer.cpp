#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;
// int memo[1001][1001];
typedef vector<vector<int>> Matrix;
int string_mixer(string s1, string s2, string s3, int p1, int p2, int p3, int n1, int n2, Matrix &memo)
{

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //         cout << *memo[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << "*****\n";
    if (s3[p3] == s1[p1 + 1])
    {
        cout << "##1 p1:"<<p1<<" p2: "<<p2<<" p3: "<<p3<<endl;
        return string_mixer(s1, s2, s3, p1 + 1, p2, p3 + 1, n1, n2, memo);
    }
    if (s3[p3] == s2[p1 + 1])
    {
        cout << "##2 p1:"<<p1<<" p2: "<<p2<<" p3: "<<p3<<endl;
        return string_mixer(s1, s2, s3, p1, p2 + 1, p3 + 1, n1, n2, memo);
    }
    else if (p1 == n1 && p2 == n2)
        return 1;
    else if (p1 == n1 && s2[p2 + 1] != s3[p3])
        return 0;
    else if (p2 == n1 && s1[p1 + 1] != s3[p3])
        return 0;
    // else 
    //     cout<<"IDK\n";return 0;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int p1 = -1, p2 = -1, p3 = 0;
    bool flag = 1;
    if (s3.length() != s1.length() + s2.length())
    {
        cout << "False";
        return 1;
    }
    Matrix memo(1001, vector<int>(1001, 0));

    // for (int i = 0; i < 1001; i++)
    //     for (int j = 0; j < 1001; j++)
    //         memo[i][j] = 0;
    string result = (string_mixer(s1, s2, s3, p1, p2, p3, s1.length()-1, s2.length()-1, memo) == 1) ? "True" : "False";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << memo[i][j] << ' ';
        cout << endl;
    }
    cout << "*****\n";
    // int memo [s1.length()+1][s2.length()+1];
    cout << result;
    return 0;
}