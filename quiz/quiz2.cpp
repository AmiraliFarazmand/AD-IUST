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
        // std::vector<char> arr;
        // std::vector<char> arr2;
        string arr;
        string arr2;
        cin >> arr;
        cin >> arr2;
        // string temp;
        // getline(cin, arr);
        // getline(cin, arr2);
        // std::istringstream iss("wrgl zrgl");
        // std::string arr, arr2;
        // iss >> arr >> arr2;
        // istringstream iss(temp);
        // copy(std::istream_iterator<char>(iss), std::istream_iterator<char>(), std::back_inserter(arr));
        int len1 = arr.length(), len2 = arr2.length();
        int counter1 = 0, counter2 = 0;
        bool flag1 = 0, flag2 = 0;

        // for (int j = 0; j < len1; j++)
        // {
        //     for (int k = 0; k < len2; k++)
        //     {
        //         if (arr[j] == arr2[k])
        //         {
        //             counter1++;
        //         }
        //     }
        //     if (counter1 == len2)
        //         flag1 = 1;
        // }
        // for (int j = len1-1 ; j >= 0; j--)
        // {
        //     for (int k = 0; k < len2; k++)
        //     {
        //         if (arr[j] == arr2[k])
        //         {
        //             counter2++;
        //         }
        //     }
        //     if (counter2 == len2)
        //         flag2 = 1;
        // }
        int indx1=0, indx2=0;
        while(indx1<len1)
        {
            if (arr[indx1] == arr2[indx2])
            {
                indx1++;
                indx2++;
            }
            else{
                indx1++;
            }
            if (indx2==len2)
                flag1=1;
            if (indx1==len1)
                break;

        }
        indx2=0;indx1=len1-1;
        while(indx1>=0)
        {
            if (indx1<0)
                break;
            if (arr[indx1] == arr2[indx2])
            {
                indx1--;
                indx2++;
            }
            else{
                indx1--;
            }
            if (indx2==len2)
                flag1=1;

        }
        if (flag1 || flag2)
            cout << "YES"
                 << endl;//<<endl;
        else
            cout << "NO"
                 << endl;//<<endl;
        // cout << arr << ' ' << arr2 << endl<<len1<<' '<<len2<<endl;
    }
}

/*
5
abcdefghi
dfge
abcdefghi
hcba
qwer
asdf
qwkedlrfid
kelid
abacdfeag
bca

>>>
NO
YES
NO
YES
YES
*/