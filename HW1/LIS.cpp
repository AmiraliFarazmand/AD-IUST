// Longest Increasing Subsequence
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int min = 29999999;
    int num=1;
} subsequence;

subsequence lis(int *array, int i, subsequence *subs)
{
    if (subs[i + 1].min != 29999999){
        if (array[i] < subs[i + 1].min)
        {
            subs[i].min = array[i];
            subs[i].num++;
            return lis(array, i - 1, subs);
        }
    }
    if (i == sizeof(subs)/sizeof(subs[0])-1){
        subs[i].min = array[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[n];

    subsequence subseq[n];

    cout << lis(arr, 0, subseq).min;
    return 0;
}