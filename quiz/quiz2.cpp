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

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string arr;
        string arr2;
        cin >> arr;
        cin >> arr2;
        int len1 = arr.length(), len2 = arr2.length();
        int counter1 = 0, counter2 = 0;
        bool flag1 = 0, flag2 = 0;

        int indx1 = 0, indx2 = 0;
        while (indx1 <= len1 + 2)
        {
            if (indx1 == len1)
                break;
            if (arr[indx1] == arr2[indx2])
            {
                indx1++;
                indx2++;
            }
            else
            {
                indx1++;
            }
            if (indx2 == len2)
                flag1 = 1;
        }
        indx2 = 0;
        indx1 = len1 - 1;
        while (indx1 >= -2)
        {
            if (indx1 < 0)
                break;
            if (arr[indx1] == arr2[indx2])
            {
                indx1--;
                indx2++;
            }
            else
            {
                indx1--;
            }
            if (indx2 == len2)
                flag2 = 1;
        }
        if (flag1 || flag2)
            cout << "YES"
                 << endl; //<<endl;
        else
            cout << "NO"
                 << endl; //<<endl;
    }
}
