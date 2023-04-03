#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
using lint = long int;
using lolint = long long int;
using namespace std;
typedef vector<vector<int>> Matrix;
// for(int i=0; i<n;i++)
//     cout<<arr[i].arrvie<<' ';

typedef struct schedule
{
    int arrvie;
    int leave;
} schedule;

int main()
{
    int n = 0;
    cin >> n;
    schedule arr[n];
    schedule temp;
    for (int i = 0; i < n; i++)
        cin >> arr[i].arrvie >> arr[i].leave;

    // sort by arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].arrvie > arr[j].arrvie)
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    int c_dot=INT_MAX;//arr[0].leave;
    int sum=1;
    for(int i =0 ; i<n;i++){
        if(arr[i].leave<c_dot)
        {
            // sum+=1;
            c_dot = arr[i].leave;
        }
        else if (arr[i].arrvie >c_dot){
            sum++;
            c_dot = arr[i].leave;
        }
    }
    cout<<sum;
    return 0;
}


/*
Example 1 :
Input:
3
1 3
2 5
3 6
Output:
1

Example 2 :
Input:
4
4 7
1 3
2 5
5 6
Output:
2



*/